import { Injectable } from "@nestjs/common";
import { InjectRepository } from "@nestjs/typeorm";
import { Repository, getRepository, Not } from 'typeorm';
import { ChatterEntity } from "src/entities/eb-chatter.entity";
import { ConversationEntity } from "src/entities/eb-conversation.entity";
import { InvitationEntity } from "src/entities/eb-invitation.entity";
import { MessageEntity } from "src/entities/eb-message.entity";
// import { Repository } from "typeorm";
import { ChatterService } from "./sb-chatter.service";
import { UserService } from "./sb-user.service";
import { ChatService } from "./sb-chat.service";


@Injectable()
export class ConvService {

  private convId;

  constructor( @InjectRepository(ConversationEntity)
                private conversation: Repository<ConversationEntity>,
                @InjectRepository(MessageEntity)
                private message: Repository<MessageEntity>,
                @InjectRepository(ChatterEntity)
                private chatter: Repository<ChatterEntity>,
                @InjectRepository(ChatterEntity)
                private invitation: Repository<InvitationEntity>,
                private user: UserService,
                private chatterService: ChatterService,
                ){}


  async newConvcheckValue (conv: ConversationEntity) {
    if (conv.members.length === 0 || conv.name.length === 0) 
      return (false);
    else if ((await this.conversation.find({where: {name: conv.name}})).length != 0)
      return (false);
    for (const mem of conv.members){
      if (!(await this.user.findOneApiUser(mem)))
        return (false)
    }
    conv.password = conv.password
    return (true);
  }

  async createConv(conv: ConversationEntity) {
    const result = {
      success: true,
      data: {},
    }
      console.log('Conversation creation');
      try {
          let newConversation;
          newConversation = await this.conversation.insert(conv)
          result.data  = newConversation
          return (result);
      }
      catch (error) {
        result.data = `error.severity: ${error.severity}, 
        \     code: ${error.code},
        \     detail: ${error.detail}`
        result.success = false;
        return (result);
      }
  }
  
  //For View Room in chat
  async findAllAvailableRoomsInApp() : Promise<ConversationEntity[]> {
    console.log(`findAllAvailableRoomsInApp`);
		return this.conversation.find();
	}

  async findOneConversation(id: number) : Promise<any> {
		return this.conversation.findOne(id);
	}

  async findOneConversationByName(name: string) : Promise<any> {
		return this.conversation.findOne({where: {name: name}});
	}

  async findAllConv(login: string): Promise<Array<ConversationEntity>> {
    const chatterArray = (await this.chatter.find({
       join: {
        alias: "conv",
        leftJoinAndSelect: {
          conv_id: "conv.conv_id",
        }},
       where: {login: login, ban: false},
    }));
    const convArray = new Array<ConversationEntity>();
    for (const chatter of chatterArray) {
      const convId = chatter.conv_id as any;
      const tmp  = await this.conversation.find({conv_id: convId.conv_id});
      if (tmp)
      convArray.push(...tmp);
    }
    return(convArray);
  }


  async joinRoomCheckValue(emission, conv: ConversationEntity, isInvited: boolean, name:string) {
    emission.data.roomPassword = emission.data.roomPassword;
    if (!conv || conv?.members?.find(member => member === name) || conv.type === 'private') {
      return (false);
    }
    else if (conv.type === 'protected' && emission.data.roomPassword != conv.password && isInvited === false) {
      return (false);
    }
    return (true);
  }

	async joinRoom(emission, name: string, isInvited: boolean) {
		let conv = await this.conversation.findOne({where: {name: emission.data.roomName}})

    if (await this.joinRoomCheckValue(emission, conv, isInvited, name) === false)
      return (undefined)
		await this.conversation.update({name: emission.data.roomName}, {members: [name, ...conv.members]});
		conv = await this.conversation.findOne({where: {name: emission.data.roomName}})
    const target = await this.chatter.findOne({conv_id: conv.conv_id, login: name});
    if (target) {
      await this.chatter.update({login:target.login, conv_id: target.conv_id}, {ban: true});
    }
    else {
		  await this.chatter.insert({
		  	chat_role: "chatter",
		  	conv_id: conv.conv_id,
		  	is_present: "yes",
		  	login: name,
		  	muted: false,
        ban: false,
		  });
    }
		return (conv);
	}

  // async removeMemberOfConv(convName, id, login, user: ChatterEntity) {
  //   try {
  //     let conv = await this.conversation.findOne({where: {name: convName, conv_id: id}})
  //     const members = conv.members;
  //     let index = members.findIndex(member => member === login);
  //     members.splice(index, 1);
  //     while ((index = members.findIndex(member => member === login)) >= 0) {
  //       members.splice(index, 1);
  //     }
  //     await this.conversation.update({name: convName}, {members: [...members]});
  //     await this.chatter.remove(user);
  //     conv = await this.conversation.findOne({where: {name: convName, conv_id: id}})
  //     if (conv.members.length === 0)
  //       this.conversation.remove(conv);
  //     return ('ok')
  //   }
  //   catch (error) {
  //     console.log('error = ', error)
  //     return ('ko')
  //   }
  // }

  async removeMemberOfConv(convName, id, login, user: ChatterEntity) {
    try {
      let conv = await this.conversation.findOne({where: {name: convName, conv_id: id}});
      const members = conv.members;
      let index = members.findIndex(member => member === login);
      members.splice(index, 1);
      while ((index = members.findIndex(member => member === login)) >= 0) {
        members.splice(index, 1);
      }
      await this.conversation.update({name: convName}, {members: [...members]});
      await this.chatter.remove(user);
      conv = await this.conversation.findOne({where: {name: convName, conv_id: id}})
      if (conv.members.length === 0)
      {
        const chattersToRemove = await this.chatter.find({where: {conv_id: id}, relations: ["conv_id", "login"]});
        await chattersToRemove.forEach(async chatter => await this.chatter.remove(chatter));
        const messagesToRemove = await this.message.find({where: {conv_id: id}, relations: ["conv_id"]});
        await messagesToRemove.forEach(async message => await this.message.remove(message));
        await this.conversation.remove(conv)
        // return ('empty');
      }
      return ('ok')
    }
    catch (error) {
      console.log('error = ', error)
      return ('ko')
    }
  }



  async destroyRoom(conv: ConversationEntity) {
    try {
      const invit = await this.getInvitationRoomById(conv.conv_id);
      if (invit)
        await this.unsetInvitation(invit);
      const chatters = await this.chatterService.findAllChatters(conv.conv_id);
      for (const chatter of chatters) {
        await this.chatter.remove(chatter);
      }
      const messagesToRemove = await this.message.find({where: {conv_id: conv.conv_id}});
      // messagesToRemove.forEach(message => this.);
      for (const message of messagesToRemove) {
          await this.message.remove(message);
      }
      await this.conversation.remove(conv);
      return ('ok');
    }
    catch (error) {
      console.log('error = ', error)
      return ('ko');
    }
  }

  async changePassword(conv_id: number, password: string) {
    try {
      this.conversation.update({conv_id: conv_id}, {password: password, type: password.length === 0 ? 'public' : 'protected'});
      return ('ok')
    }
    catch (error) {
      console.log(error);
      return ('ko');
    }
  }

  // OK
  async getConversationById(id: number): Promise<ConversationEntity> {
    const convRepository = getRepository(ConversationEntity);
    return convRepository.findOne({
      where: { conv_id: id }
    })
    .then((response: any) => {
      const conversation: ConversationEntity = response;
      return conversation;
    })
    .catch((error: any) => {
      return undefined;
    })
  }

  // async getAllInvitationsByLogin(login: string): Promise<InvitationEntity[]> {
  //   const invitRepository = getRepository(InvitationEntity);
  //   return invitRepository.find({
  //     relations: ["emitter", "receiver", "room"],
  //     where: [ 
  //       { emitter: login },
  //       { receiver: login }
  //     ]
  //   })
  //   .then((response: any) => {
  //     const invitations: InvitationEntity[] = response;
  //     return invitations;
  //   })
  //   .catch((error) => {
  //     console.error("OOPS -> getAllInvitationsByLogin()");
  //     return undefined;
  //   })
  // }

  // OK
  async getInvitationRoomById(id: number): Promise<InvitationEntity> {
    const invitRepository = getRepository(InvitationEntity);
    return invitRepository.findOne({
      relations: ["emitter", "receiver", "room"],
      where: { room: id }
    })
    .then((response) => {
      const invitation: InvitationEntity = response;
      return invitation;
    })
    .catch((error) => {
      console.error("OOPS -> getInvitationForRoomById()");
      return undefined;
    })
  }

  // OK
  async setInvitation(id: number, emitter: string, receiver: string, type: string) {
    const invitRepository = getRepository(InvitationEntity);
		const invitation: InvitationEntity = {
      id: 0,
      emitter: emitter,
      receiver: receiver,
      game_type: type,
      invitation_type: "play",
      room: id,
      created: new Date()
		}
		return invitRepository.insert(invitation);
  }

  // OK
  async unsetInvitation(invitation: InvitationEntity): Promise<boolean> {
    const invitRepository = getRepository(InvitationEntity);
		return invitRepository.delete(invitation)
		.then((response) => {
			console.log(`Delete invitation by entity has succeeded.`);
			return true;
		})
		.catch((error) => {
      console.error("OOPS -> getInvitationForRoomById()");
			return false;
		})
  }

}