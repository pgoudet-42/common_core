/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:14:59 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/15 07:02:18 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*malloc_res(char *res, char *start, char *var, char *end)
{
	if (start && var && end)
		res = malloc(ft_strlen(start) + ft_strlen(var) + ft_strlen(end) + 1);
	else if (start && var)
		res = malloc(ft_strlen(start) + ft_strlen(var) + 1);
	else if (var && end)
		res = malloc(ft_strlen(var) + ft_strlen(end) + 1);
	else if (var)
		res = malloc(ft_strlen(var) + 1);
	else
		res = NULL;
	if (!res)
		return (NULL);
	return (res);
}

static char	*noval2(char *start, int *i, char *res, char *end)
{
	int	j;

	j = -1;
	if (start)
	{
		while (start[++(*i)])
			res[*i] = start[*i];
		free(start);
		res[*i] = 0;
	}
	if (end)
	{
		ft_strlen(end);
		while (end[++j])
		{
			res[*i] = end[j];
			(*i)++;
		}
		free(end);
	}
	return (res);
}

static char	*noval(char *start, char *end)
{
	int		i;
	char	*res;

	i = -1;
	res = malloc(ft_strlen(start) + ft_strlen(end) + 1);
	if (!res)
	{
		free(start);
		free(end);
		return (NULL);
	}
	res = noval2(start, &i, res, end);
	res[i] = 0;
	return (res);
}

static char	*concat2(char *res, char *end, char *var, int i)
{
	int	j;

	j = -1;
	if (var)
	{
		while (var[++j])
			res[++i] = var[j];
		free(var);
	}
	j = -1;
	if (end)
	{
		while (end[++j])
			res[++i] = end[j];
		free(end);
	}
	res[++i] = 0;
	return (res);
}

char	*concat(char *start, char *var, char *end)
{
	char	*res;
	int		i;

	i = -1;
	res = NULL;
	res = malloc_res(res, start, var, end);
	if (res == NULL)
	{
		res = noval(start, end);
		free(var);
		return (res);
	}
	if (start)
	{
		while (start[++i])
			res[i] = start[i];
		free(start);
	}
	i--;
	res = concat2(res, end, var, i);
	return (res);
}
