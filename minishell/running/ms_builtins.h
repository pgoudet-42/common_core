/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 07:08:58 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/18 09:53:12 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

int		ft_str_begin(const char *s1, const char *s2);

int		execpath(char **envp, char *path, char	*exec);
int		is_builtin(char *arg);
int		builtin_exec(char **argv, char **venv);
int		builtin_exec_0(char **argv, char **venv);

int		error_print_2(char *cmd, char *error, int ret);
int		error_print_3(char *cmd, char *prm, char *error, int ret);
char	*ft_strend(char const *s, unsigned int start);
char	*get_venv(char **envp, char *var);
int		fn_cd(int argc, char **argv, char **venv);
int		fn_pwd(int argc, char **argv, char **venv);
int		fn_echo(int argc, char **argv, char **venv);
int		fn_exit(int argc, char **argv, char **venv);

int		ft_check_var_name(char *var);
void	venv_sup(char **envp, char *var);
int		fn_unset(int argc, char **argv, char **venv);
int		fn_env(int argc, char **argv, char **venv);
int		fn_export(int argc, char **argv, char **venv);

int		fn_redirin(int argc, char **argv);
int		fn_redirout1(int argc, char **argv);
int		fn_redirout2(int argc, char **argv);

void	ms_sort_print_export(char **env);
#endif
