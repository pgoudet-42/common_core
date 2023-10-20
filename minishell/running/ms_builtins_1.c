/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:02:37 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/17 10:12:01 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>
#include "ms_builtins.h"

char	*get_venv(char **envp, char *var)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_str_begin(envp[i], var))
		{
			return (ft_strend(envp[i], ft_strlen(var)));
		}
		i++;
	}
	return ("");
}

int	fn_cd(int argc, char **argv, char **venv)
{
	char	*pth;
	int		ret;

	if (argc == 1)
	{
		pth = get_venv(venv, "HOME=");
		if (pth == NULL || !*pth)
			return (error_print_2("cd", "HOME not set", 1));
		ret = chdir(pth);
	}
	else
	{
		ret = chdir(argv[1]);
		if (ret)
		{
			return (error_print_3("cd", argv[1],
					"No such file or directory", 1));
		}
	}
	return (0);
}

int	fn_pwd(int argc, char **argv, char **venv)
{
	char	pth[PATH_MAX];
	char	*p;

	(void)argv;
	(void)argc;
	(void)venv;
	p = getcwd(pth, PATH_MAX);
	if (p != NULL)
		ft_putendl_fd(p, 1);
	return (0);
}

int	fn_echo(int argc, char **argv, char **venv)
{
	int	i;
	int	cr;

	(void)venv;
	i = 1;
	cr = 1;
	if (argc > 1 && !ft_strcmp(argv[1], "-n"))
	{
		i = 2;
		cr = 0;
	}
	while (i < argc)
	{
		ft_putstr_fd(argv[i], 1);
		if (i != argc - 1)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (cr)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	fn_exit(int argc, char **argv, char **venv)
{
	int	r;

	(void)venv;
	r = 0;
	ft_putendl_fd("exit", 1);
	if (argc > 1)
	{
		while (argv[1][r])
		{
			if (argv[1][r] < '0' || argv[1][r] > '9')
			{
				error_print_3("exit", argv[1],
					"numeric argument required", 255);
				exit(255);
			}
			r++;
		}
		if (argc > 2)
		{
			error_print_2("exit", "too many arguments", 1);
			return (-1);
		}
		r = ft_atoi(argv[1]);
	}
	exit(r);
}
