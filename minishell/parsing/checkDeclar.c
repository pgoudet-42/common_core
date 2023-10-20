/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkDeclar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:18:32 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/21 14:55:57 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*malloc_res(char *arg, const char *charset)
{
	int		j;
	char	*res;

	j = 0;
	while (arg[j] && (is_charset(arg[j], charset) == 0
			|| (j > 0 && is_charset(arg[j], charset) == 1
				&& bsvalid(arg, j) == 1)
			|| (j > 0 && is_charset(arg[j], charset) == 1
				&& is_inquote(j, arg) > 0)))
		j++;
	res = malloc(j + 1);
	if (!res)
		return (NULL);
	return (res);
}

static char	*whilecd(char *arg, char *res, const char *charset, int *i)
{
	int	j;

	j = -1;
	while (arg[++j] && (is_charset(arg[j], charset) == 0
			|| (j > 0 && is_charset(arg[j], charset) == 1
				&& bsvalid(arg, j) == 1)
			|| (is_charset(arg[j], charset) == 1
				&& is_inquote(j, arg) > 0)))
	{
		if (is_sep(&arg[j]) == 1 && bsvalid(arg, j) == 0
			&& is_inquote(j, arg) == 0)
		{
			free(res);
			res = gest_sep(arg, &j);
			if (j >= 1)
				j--;
			*i += j;
			return (res);
		}
		res[j] = arg[j];
		res[j + 1] = 0;
	}
	res[j] = 0;
	*i += j;
	return (res);
}

char	*checkdeclar(char *arg, const char *charset, int *i)
{
	char	*res;

	res = malloc_res(arg, charset);
	if (!res)
		return (NULL);
	res = whilecd(arg, res, charset, i);
	return (res);
}
