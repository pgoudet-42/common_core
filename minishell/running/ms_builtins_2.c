/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:29:29 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/17 14:36:19 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ms_builtins.h"

int	ft_check_var_name(char *var)
{
	while (*var && *var != '=')
	{
		if (!ft_isalnum(*var) && *var != '_')
			return (0);
		var++;
	}
	return ((*var == '=') + 1);
}

void	venv_sup(char **envp, char *var)
{
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(var);
	while (envp[i])
	{
		if (envp[i][l] == '=' && ft_str_begin(envp[i], var))
		{
			*(envp[i]) = 0;
			return ;
		}
		i++;
	}
}

int	fn_unset(int argc, char **argv, char **venv)
{
	int	i;

	venv = g_env.envp;
	i = 1;
	while (i < argc)
	{
		if (!ft_check_var_name(argv[i]))
			error_print_3("unset", argv[i], "not a valid identifier", 1);
		else
			venv_sup(venv, argv[i]);
		i++;
	}
	return (0);
}

int	fn_env(int argc, char **argv, char **venv)
{
	int		i;

	venv = g_env.envp;
	(void)argc;
	(void)argv;
	i = 0;
	while (venv[i])
	{
		if (venv[i][0])
			ft_putendl_fd(venv[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
