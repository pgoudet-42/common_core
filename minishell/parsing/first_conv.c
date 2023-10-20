/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 06:28:10 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/15 07:08:48 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*malloc_start(char *start, int i, int *j, char *arg)
{
	*j = -1;
	start = malloc(i + 1);
	if (!start)
		return (NULL);
	if (i == 0)
	{
		free(start);
		start = NULL;
	}
	else
	{
		while (++(*j) < i)
			start[*j] = arg[*j];
		start[*j] = 0;
	}
	if (*j < 0)
		(*j)++;
	return (start);
}

char	*init_end(char *arg, int j)
{
	int		i;
	char	*end;

	end = malloc(ft_strlen(arg) - j + 1);
	if (!end)
		return (NULL);
	if (ft_strlen(arg) - j == 0)
	{
		free(end);
		end = NULL;
	}
	else
	{
		i = -1;
		while (++j < (int)ft_strlen(arg))
			end[++i] = arg[j];
		end[++i] = 0;
	}
	return (end);
}

char	*change_var(char *arg, int i, char **envp)
{
	int		j;
	char	*start;
	char	*var;
	char	*end;

	start = NULL;
	start = malloc_start(start, i, &j, arg);
	while (arg[j] && arg[j] != ';'
		&& ft_isspace(arg[j]) == 0 && arg[j] != 39 && arg[j] != 34)
		j++;
	if (arg[j] != 0)
		j--;
	var = var_toval(&arg[i + 1], envp);
	if (!var && g_env.var)
		var = var_toval(&arg[i + 1], g_env.var);
	if (!var)
	{
		free(start);
		return (arg);
	}
	end = init_end(arg, j);
	free(arg);
	arg = concat(start, var, end);
	return (arg);
}

char	*var_inval(char *arg, char **envp)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(arg))
		if (arg[i] == '$' && is_inquote(i, arg) != 1)
			if (!(i > 0) || (i > 0 && bsvalid(arg, i) == 0))
				arg = change_var(arg, i, envp);
	return (arg);
}
