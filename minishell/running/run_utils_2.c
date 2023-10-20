/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:06:41 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/16 13:10:11 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*var_fromenv(char *arg)
{
	int		res;
	char	*newarg;

	res = wich_envp(arg, g_env.var);
	if (res == -1)
		return (NULL);
	newarg = ft_strdup(g_env.var[res]);
	free(arg);
	return (newarg);
}

int	is_equal(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (0);
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (1);
}

char	**add_el_tab(char *argvi, char **venv)
{
	char	**tab;
	int		i;

	i = -1;
	tab = malloc(sizeof(void *) * (tablen(venv) + 2));
	while (venv[++i])
	{
		tab[i] = ft_strdup(venv[i]);
	}
	tab[i] = ft_strdup(argvi);
	tab[++i] = NULL;
	return (tab);
}

int	out_exp(char **env, int exp)
{
	int		i;
	int		j;

	(void)exp;
	i = 0;
	while (env[i])
	{
		if (env[i][0])
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			j = 0;
			while ((env[i][j] && env[i][j] != '='))
				write(STDOUT_FILENO, &env[i][j++], 1);
			if (env[i][j])
				j++;
			write(STDOUT_FILENO, "=\"", 2);
			while (env[i][j])
				write(STDOUT_FILENO, &env[i][j++], 1);
			ft_putendl_fd("\"", STDOUT_FILENO);
		}
		i++;
	}
	return (0);
}
