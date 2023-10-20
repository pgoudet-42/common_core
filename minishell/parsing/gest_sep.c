/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_sep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:41 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/16 10:19:32 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_sep(char *arg)
{
	if (arg)
	{
		if (arg[0] == '<' || arg[0] == '>' || arg[0] == '|'
			|| arg[0] == ';')
			return (1);
	}
	return (0);
}

static char	*double_chev(char *arg, int *j)
{
	char	*res;

	res = malloc(3);
	if (!res)
		return (NULL);
	res[0] = arg[*j];
	res[1] = arg[*j + 1];
	res[2] = 0;
	(*j)++;
	return (res);
}

char	*gest_sep2(char *arg, int *j, char *res)
{
	if (*j < (int)ft_strlen(arg) - 1 && arg[0] == '>' && arg[1] == '>')
		res = double_chev(arg, j);
	else
	{
		res = malloc(2);
		if (!res)
			return (NULL);
		res[0] = arg[*j];
		res[1] = 0;
	}
	return (res);
}

char	*gest_sep(char *arg, int *j)
{
	int		k;
	char	*res;

	k = -1;
	res = NULL;
	if (*j == 0)
		res = gest_sep2(arg, j, res);
	else
	{
		res = malloc(*j + 1);
		if (!res)
			return (NULL);
		while (++k < *j)
			res[k] = arg[k];
		res[k] = 0;
	}
	return (res);
}
