/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:24:27 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/17 09:59:04 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <limits.h>
#include "ms_builtins.h"

int	execpath_ok(char *thepath, char *pth, char *exc)
{
	ft_strlcpy(thepath, pth, PATH_MAX);
	ft_strlcat(thepath, "/", PATH_MAX);
	ft_strlcat(thepath, exc, PATH_MAX);
	return (access(thepath, X_OK));
}

int	execpath(char **envp, char *path, char *exec)
{
	int		f;
	int		j;
	char	**pth;
	char	*pat;

	ft_strlcpy(path, exec, PATH_MAX);
	if (exec[0] == '/' || exec[0] == '.')
		return (!access(exec, X_OK));
	pat = get_venv(envp, "PATH=");
	pth = ft_split(pat, ':');
	if (*pat)
		free(pat);
	j = 0;
	f = 0;
	while (pth[j])
	{
		if (!f)
		{
			f = !execpath_ok(path, pth[j], exec);
		}
		free(pth[j++]);
	}
	free(pth);
	return (f);
}

int	is_builtin(char *arg)
{
	if (ft_strcmp(arg, "cd") == 0 || ft_strcmp(arg, "export") == 0
		|| ft_strcmp(arg, "unset") == 0 || ft_strcmp(arg, "exit") == 0)
		return (2);
	if (ft_strcmp(arg, "echo") == 0 || ft_strcmp(arg, "pwd") == 0
		|| ft_strcmp(arg, "env") == 0 || ft_strcmp(arg, "redirin") == 0
		|| ft_strcmp(arg, "redirout1") == 0 || ft_strcmp(arg, "redirout2") == 0)
		return (1);
	return (0);
}

int	builtin_exec_0(char **argv, char **venv)
{
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (ft_strcmp(argv[0], "cd") == 0)
		return (fn_cd(argc, argv, venv));
	if (ft_strcmp(argv[0], "export") == 0)
		return (fn_export(argc, argv, venv));
	if (ft_strcmp(argv[0], "unset") == 0)
		return (fn_unset(argc, argv, venv));
	if (ft_strcmp(argv[0], "exit") == 0)
		return (fn_exit(argc, argv, venv));
	return (0);
}

int	builtin_exec(char **argv, char **venv)
{
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (ft_strcmp(argv[0], "echo") == 0)
		return (fn_echo(argc, argv, venv));
	if (ft_strcmp(argv[0], "pwd") == 0)
		return (fn_pwd(argc, argv, venv));
	if (ft_strcmp(argv[0], "env") == 0)
		return (fn_env(argc, argv, venv));
	if (ft_strcmp(argv[0], "redirin") == 0)
		return (fn_redirin(argc, argv));
	if (ft_strcmp(argv[0], "redirout1") == 0)
		return (fn_redirout1(argc, argv));
	if (ft_strcmp(argv[0], "redirout2") == 0)
		return (fn_redirout2(argc, argv));
	return (0);
}
