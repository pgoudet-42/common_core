/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:57:20 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/21 15:37:23 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	wich_envp(char *argvi, char **envp)
{
	int	i;
	int	j;
	int	size;

	i = tablen(envp);
	while (--i >= 0)
	{
		size = 0;
		while (envp[i][size] && envp[i][size] != '=')
			size++;
		j = 0;
		while (envp[i][j] && argvi[j]
			&& envp[i][j] != '=' && envp[i][j] == argvi[j])
			j++;
		if (j == size)
			return (i);
	}
	if (argvi[0] == '?' && ft_strlen(argvi) == 1)
		return (-2);
	return (-1);
}

char	*var_toval(char *argvi, char **envp)
{
	int		i;
	int		j;
	int		pos;
	char	*new_argv;

	i = -1;
	j = 0;
	pos = wich_envp(argvi, envp);
	if (pos == -1)
		return (NULL);
	if (pos == -2)
	{
		new_argv = ft_itoa(get_last_error());
		return (new_argv);
	}
	while (envp[pos][j] != 0 && envp[pos][j] != '=')
		j++;
	new_argv = malloc(ft_strlen(&envp[pos][j]));
	if (!new_argv)
		return (NULL);
	while (envp[pos][++i + j + 1])
		new_argv[i] = envp[pos][i + j + 1];
	new_argv[i] = 0;
	return (new_argv);
}

char	**whlcviv(char **argv, int *j, char **new_argv, char **envp)
{
	int	i;

	i = -1;
	*j = -1;
	while (argv[++i])
	{
		if ((argv[i][0] == 34 && argv[i][1] == '$') || argv[i][0] == '$')
		{
			new_argv[++(*j)] = var_toval(&argv[i][1], envp);
			if (new_argv[*j] == 0)
				j--;
		}
		else if (argv[i][0] == 39 && argv[i][1] == '$')
			new_argv[++(*j)] = ft_strdup(argv[i]);
		else
			new_argv[++(*j)] = ft_strdup(argv[i]);
	}
	return (new_argv);
}

char	**changevar_inval(char **argv, char **envp)
{
	char	**new_argv;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
		i++;
	new_argv = malloc(sizeof(void *) * (i + 1));
	if (!new_argv)
	{
		*new_argv = NULL;
		return (NULL);
	}
	new_argv = whlcviv(argv, &j, new_argv, envp);
	freetab(argv);
	new_argv[++j] = NULL;
	return (new_argv);
}
