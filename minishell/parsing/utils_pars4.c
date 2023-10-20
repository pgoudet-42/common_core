/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:13:59 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/16 10:20:21 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	display(char **tab)
{
	int			i;
	static int	j;

	i = -1;
	if (tab)
		while (tab[++i])
			dprintf(1, "display>%d>%s\n", j, tab[i]);
	j++;
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

char	*trait_argv(char *arg)
{
	int	i;
	int	compt;

	i = -1;
	compt = 0;
	while (arg[++i])
	{
		if (arg[i] == 34 || arg[i] == 39)
		{
			if (arg[i - 1] && arg[i - 1] == 92 && is_inquote(i, arg) == 0)
			{
				if (gotonextquote(&arg[i], i) == (int)ft_strlen(&arg[i]))
				{
					if (arg[i] == 34)
						arg = take_arg(arg, 1, &compt);
					else
						arg = take_arg(arg, 2, &compt);
				}
			}
		}
	}
	return (arg);
}

int	back_start(char *arg, int i)
{
	int	j;

	j = 0;
	while (i - j > 0 && (arg[i - j] != ';'
			&& arg[i - j] != 92 && ft_isspace(arg[i - j]) == 0))
		j++;
	return (j);
}

int	go_end(char *arg, int i)
{
	int	j;

	j = 0;
	while (arg[i + j] && (arg[i + j] != ';'
			&& arg[i + j] != 92 && ft_isspace(arg[i + j]) == 0))
		j++;
	return (j);
}
