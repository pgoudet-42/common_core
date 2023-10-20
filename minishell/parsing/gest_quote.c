/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:16:45 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/18 15:02:12 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*take_arg2(char *newarg, int nbr, int *compt)
{
	char	buff[2];
	int		res;

	buff[0] = '\n';
	buff[1] = 0;
	newarg = ft_strjoin(newarg, buff);
	write(1, "Quote:", 6);
	res = read(0, buff, 1);
	while (res > 0 && buff[0] != nbr)
	{
		if (buff[0] == 10)
			write(1, "Quote:", 6);
		buff[1] = 0;
		newarg = ft_strjoin(newarg, buff);
		res = read(0, buff, 1);
	}
	buff[1] = 0;
	newarg = ft_strjoin(newarg, buff);
	(*compt)++;
	return (newarg);
}

char	*take_arg(char *arg, int flag, int *compt)
{
	char	*newarg;
	char	*argfin;
	int		i;

	newarg = malloc(1);
	newarg[0] = 0;
	if (flag == 1)
		newarg = take_arg2(newarg, 34, compt);
	else if (flag == 2)
		newarg = take_arg2(newarg, 39, compt);
	argfin = malloc(ft_strlen(arg) + 1);
	i = -1;
	while (arg[++i])
		argfin[i] = arg[i];
	argfin[i] = 0;
	arg = ft_strjoin(argfin, newarg);
	free(newarg);
	return (arg);
}

static int	size_arg(char *arg, int k, int flag)
{
	while (arg[k] && (arg[k] != 34 || bsvalid(arg, k) == 1) && flag == 1)
		k++;
	while (arg[k] && (arg[k] != 39 || bsvalid(arg, k) == 1) && flag == 2)
		k++;
	return (k);
}

char	*gestquote(char *arg, int *i, int *compt)
{
	int	k;
	int	flag;

	k = *i;
	flag = 0;
	if (arg[k] == 34)
		flag = 1;
	else
		flag = 2;
	k++;
	k = size_arg(arg, k, flag);
	if (k == (int)ft_strlen(arg))
	{
		arg = take_arg(arg, flag, compt);
		k = *i + 1;
		k = size_arg(arg, k, flag);
	}
	*i = k + 1;
	return (arg);
}
