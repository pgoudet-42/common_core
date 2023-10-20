/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyquotearg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:19:17 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/16 10:19:21 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*copy(char *arg, int flag, int size)
{
	int		i;
	char	*newarg;

	newarg = malloc(size + 1);
	if (!newarg)
		return (NULL);
	i = 0;
	if (flag == 2)
	{
		newarg[i] = arg[i];
		while (arg[++i] && (arg[i] != 34
				|| (arg[i] == 34 && bsvalid(arg, i) == 1)))
			newarg[i] = arg[i];
		newarg[i] = arg[i];
	}
	else
	{
		newarg[i] = arg[i];
		while (arg[++i] && (arg[i] != 39
				|| (arg[i] == 39 && bsvalid(arg, i) == 1)))
			newarg[i] = arg[i];
		newarg[i] = arg[i];
	}
	newarg[++i] = 0;
	return (newarg);
}

char	*copyquotearg(char *arg, int *i)
{
	int		j;
	char	*res;
	int		flag;

	j = 0;
	if (arg[j] == 39)
	{
		flag = 1;
		j++;
		while (arg[j] && (arg[j] != 39 || (arg[j] == 39
					&& bsvalid(arg, j) == 1)))
			j++;
	}
	else
	{
		flag = 2;
		j++;
		while (arg[j] && (arg[j] != 34 || (arg[j] == 34
					&& bsvalid(arg, j) == 1)))
			j++;
	}
	j++;
	res = copy(arg, flag, j);
	*i += ft_strlen(res);
	return (res);
}
