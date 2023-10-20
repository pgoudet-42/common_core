/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:24:39 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/18 09:53:03 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ms_builtins.h"

int	error_print_2(char *cmd, char *error, int ret)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	g_env.errnum = ret;
	return (ret);
}

int	error_print_3(char *cmd, char *prm, char *error, int ret)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": '", STDERR_FILENO);
	ft_putstr_fd(prm, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	g_env.errnum = ret;
	return (ret);
}

int	if2(char **argv, int *i)
{
	argv[*i] = var_fromenv(argv[*i]);
	if (!argv[*i])
		return (0);
	g_env.envp = add_el_tab(argv[*i], g_env.envp);
	return (1);
}

int	els_export(char **venv, char **argv, int *flag, int *i)
{
	int	l;
	int	j;

	l = ft_strlen(venv[*i]);
	j = 0;
	while (venv[j])
	{
		if (is_equal(argv[*i], venv[j]) == 1)
		{
			argv[*i] = var_fromenv(argv[*i]);
			if (!argv[*i])
				return (0);
			venv[j] = ft_strdup(argv[*i]);
			(*flag)++;
		}
		j++;
	}
	if (!(*flag))
		if (if2(argv, i) == 0)
			return (0);
	return (1);
}

int	fn_export(int argc, char **argv, char **venv)
{
	int	i;
	int	flag;

	venv = g_env.envp;
	if (argc == 1)
	{
		ms_sort_print_export(venv);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		flag = 0;
		if (!ft_check_var_name(argv[i]))
			error_print_3("export", argv[i], "not a valid identifier", 1);
		else
			if (els_export(venv, argv, &flag, &i) == 0)
				return (0);
		i++;
	}
	return (0);
}
