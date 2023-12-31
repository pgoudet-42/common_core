# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sad-aude <sad-aude@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 16:17:37 by sad-aude          #+#    #+#              #
#    Updated: 2021/07/30 18:01:24 by sad-aude         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Colors
NORMAL= \033[0m
GREY = \033[90m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m
PURPLE = \033[35m
RED = \033[31m
HIDDEN = \033[2m
ITALIC = \033[3m
CLEAN = \e[1;1H\e[2J

# Pre-compiling
NAME		= webserv
CC		 	= clang++
CPPFLAGS 	= -g -Wall -Wextra -Werror
VPATH		=	./config \
				./server \
				./

HEADERS		=	Request.hpp \
				Socket.hpp \
				Webserv.hpp \
				WebservData.hpp \
				Config.hpp \
				Parser.hpp
FILES		= AutoIndex.cpp \
			  CreatingPage.cpp \
			  FdManager.cpp \
			  main.cpp \
			  ParsingRequest.cpp \
			  ProcessSocket.cpp \
			  RequestChecker.cpp \
			  RequestManager.cpp \
			  ResponseManager.cpp \
			  Socket.cpp \
			  WebservData.cpp \
			  Config.cpp \
			  Parser.cpp

OPATH		= objs/

OBJS		= $(addprefix $(OPATH), ${FILES:.cpp=.o})

# Compiling
all:	draw $(NAME)

$(OPATH)%.o	:	%.cpp $(HEADERS)
	$(shell mkdir -p $(OPATH))
	@echo "$(BLUE)$(HIDDEN)COMPILATION $(NORMAL)$(GREY)\t"$<
ifeq ($(ARG),noflags)
	@$(CC) -c $< -o $@
else ifeq ($(ARG),fsanitize)
	@$(CC) $(CPPFLAGS) -fsanitize=address -c $< -o $@
else
	@$(CC) $(CPPFLAGS) -c $< -o $@
endif

$(NAME):	$(OBJS)
	@echo "$(CYAN)\nWEBSERV $(GREEN)\tREADY FOR EXEC\n$(NORMAL)"
ifeq ($(ARG),noflags)
	@$(CC) $(OBJS) -o $(NAME)
else ifeq ($(ARG),fsanitize)
	@$(CC) $(CPPFLAGS) -fsanitize=address $(OBJS) -o $(NAME)
else
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
endif

# Cleaning
clean:
	@echo "$(BLUE)WEBSERV $(GREY)\t.O DELETION $(NORMAL)"
	@rm -rf $(OPATH)

fclean:		clean
	@echo "$(BLUE)WEBSERV $(GREY)\tEXEC DELETION $(NORMAL)"
	@rm -f $(NAME)
	@echo "$(CYAN)\nWEBSERV $(GREEN)\tALL HAS BEEN CLEANED $(NORMAL)"

re: fclean all

# Designing
draw:
	@printf "$(CLEAN)"
	@printf "\n"
	@printf "$(BLUE)[..        [..          [..                                         \n"
	@printf "$(BLUE)[..        [..          [..                                         \n"
	@printf "$(BLUE)[..   [.   [..   [..    [..       [....    [..    [. [...[..     [..\n"
	@printf "$(BLUE)[..  [..   [.. [.   [.. [.. [..  [..     [.   [..  [..    [..   [.. \n"
	@printf "$(BLUE)[.. [. [.. [..[..... [..[..   [..  [... [..... [.. [..     [.. [..  \n"
	@printf "$(BLUE)[. [.    [....[.        [..   [..    [..[.         [..      [.[..   \n"
	@printf "$(BLUE)[..        [..  [....   [.. [..  [.. [..  [....   [...       [..    \n"
	@printf "$(ITALIC)\t\t\t\t\t\t\t Webserv\n"
	@printf "$(HIDDEN)$(ITALIC)\t\t\t\t\t\t\t La team\n"
	@printf "$(NORMAL)																\n"

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all ./webserv config/nginx.conf

exec: all
	@./webserv ./config/nginx.conf

.PHONY: all clean fclean re exec valgrind draw noflags fsanitize