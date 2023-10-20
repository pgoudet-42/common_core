/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 07:15:48 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/21 16:10:34 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include "./libft/libft.h"
# include <signal.h>
# include <limits.h>

# define	F_BINARY 0
# define	F_ECHO	1
# define	F_CD 2
# define	F_PWD 3
# define	F_EXPORT 4
# define	F_UNSET 5
# define	F_ENV 6
# define	F_EXIT 7
# define	F_RDIR_IN 12
# define	F_RDIR_OUT1 13
# define	F_RDIR_OUT2 14
# define	F_PIPE 15

typedef struct s_command
{
	char				*exec;
	char				**argv;
	int					argc;
	int					func;
	int					pip_in;
	int					pip_out;
	int					pip[2];
	pid_t				pid;
	int					fd_in;
	int					fd_out;
	struct s_command	*prev;
	struct s_command	*next;
}				t_command;

typedef struct s_envp
{
	char		**envp;
	char		**var;
	char		thepath[PATH_MAX];
	int			errnum;
	int			errnum2;
	t_command	*commande;
}				t_envp;

t_envp	g_env;

int			cat(const char *file);
void		pwd(void);
void		echo(int argc, char **argv);
t_command	*parsing(char *command_lign, char **envp);

t_command	*init_struct(t_command *commande, int *tab_id,
				int size_tab, char **argv);
int			trait_error(int *tab_id, char **argv, int size_tab);
char		**find_char_spe(char **argv);
char		**unset(char *var);
int			*findQuote(char **argv);
char		**ft_splitp(char *arg, const char *charset);
char		*var_toval(char *argvi, char **envp);
char		**changevar_inval(char **argv, char **envp);
int			is_inquote(int pos_c, char *arg);
int			*pos_quote(char *arg);
int			*pos_dquote(char *arg);
char		*take_arg(char *arg, int flag, int *compt);
int			gotonextquote(char *arg, int i);
void		trait_arg(void);
void		freetab(char **tab);
int			is_charset(char c, const char *charset);
int			arg_to_struct(char **arg);
char		*var_inval(char *arg, char **envp);
int			bsvalid(char *arg, int i);
char		*gestquote(char *arg, int *i, int *compt);
char		*copyquotearg(char *arg, int *i);
int			back_start(char *arg, int i);
int			is_sep(char *arg);
void		display(char **tab);
char		*gest_sep(char *arg, int *j);
int			tablen(char **tab);
char		*concat(char *start, char *var, char *end);
char		*checkdeclar(char *arg, const char *charset, int *i);
int			malloc_struct(int *j, int *size, char **arg);
char		*arg_fromarg(char *str);
char		*rmbs2(char *arg);
char		*rmquotes(char *arg);
void		rmarg(int i, int *j);
void		last_chance(void);
int			wich_envp(char *argvi, char **envp);
char		*var_fromenv(char *arg);
int			is_equal(char *str, char *str2);
int			compt_word(char **arg, const char *charset);
char		**add_el_tab(char *argvi, char **venv);
int			out_exp(char **env, int exp);
int			get_last_error(void);
#endif