/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:15:36 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/22 06:22:48 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*rmquotes(char *arg)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!arg)
		return (NULL);
	new = malloc(ft_strlen(arg) + 1);
	if (!new)
		return (NULL);
	while (arg[++i])
	{
		if ((arg[i] != 34 && arg[i] != 39)
			|| (i > 0 && arg[i - 1] == 92 && (bsvalid(arg, i) == 1)))
			new[++j] = arg[i];
	}
	new[++j] = 0;
	free(arg);
	return (new);
}

char	*rmbs2(char *arg)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new = malloc(ft_strlen(arg) + 1);
	if (!new)
		return (NULL);
	while (arg[++i])
	{
		if ((arg[i] != 92 && arg[i] != 34 && arg[i] != 39))
			new[++j] = arg[i];
		else if (is_inquote(i, arg) == 1)
			new[++j] = arg[i];
		else if (is_inquote(i, arg) == 2 && bsvalid(arg, i) == 0)
			new[++j] = arg[i];
		else if ((arg[i] == 39 || arg[i] == 34)
			&& (i > 0 && arg[i - 1] == 92 && (bsvalid(arg, i) == 1)))
			new[++j] = arg[i];
	}
	new[++j] = 0;
	free(arg);
	return (new);
}

char	*arg_fromarg(char *str)
{
	int		i;
	char	*arg;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	arg = malloc(i + 1);
	if (!arg)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '=')
		arg[i] = str[i];
	arg[i] = 0;
	free(str);
	return (arg);
}

int	is_charset(char c, const char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}
