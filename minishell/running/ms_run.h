/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:12:24 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/16 16:09:36 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_RUN_H
# define MS_RUN_H

t_command	*cmds_init(t_command *tc);
void		tabl_aff2(void);
void		free_t_com(t_command *tc);
void		free_pl_com(void);

int			ms_exec(char *ex, char **ar, int in, int out);
int			ms_input(char **envp);
int			ms_check_path(t_command *tc, char *thepath, char **envp);
int			pipe_exec(t_command *tc, int *in, char *thepath, int *p);

void		sigintHandler_q(int sig_num);
void		sigintHandler_q2(int sig_num);
void		sigintHandler_c(int sig_num);
void		sigintHandler_c2(int sig_num);

void		check_multi_redir(t_command *tc);
#endif