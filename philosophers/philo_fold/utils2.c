/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:31:32 by pgoudet           #+#    #+#             */
/*   Updated: 2021/06/14 08:11:30 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strlen_int(long int l)
{
	int	compt;

	compt = 0;
	if (l < 0 || l == -0)
		compt++;
	while (l != 0)
	{
		l = l / 10;
		compt++;
	}
	return (compt);
}

char	*ft_itoa_bis(char *tab, long int l)
{
	int	i;

	i = ft_strlen_int(l) - 1;
	if (l == -0)
		tab[0] = 48;
	if (l < 0)
		l = -l;
	while (l != 0)
	{
		tab[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char		*tab;
	long int	l;

	l = (long int)n;
	if (l < 0)
	{
		tab = malloc(sizeof(char) * (ft_strlen_int(l)) + 1);
		if (!tab)
			return (NULL);
		tab[0] = '-';
	}
	else
		tab = malloc(sizeof(char) * ft_strlen_int(l) + 1);
	if (!tab)
		return (NULL);
	tab[ft_strlen_int(l)] = 0;
	tab = ft_itoa_bis(tab, l);
	return (tab);
}

void	ft_atoi_bis(int *neg, int *i, char *str)
{
	*neg = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32
		|| str[*i] == ',' || ft_isalpha(str[*i]) == 1)
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg = -(*neg);
		*i += 1;
	}
}

double	ft_atoi(char *str)
{
	int	res;
	int	neg;
	int	i;

	res = 0;
	neg = 1;
	i = 0;
	ft_atoi_bis(&neg, &i, str);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		res = res * 10 + str[i] - 48;
		i += 1;
	}
	return (res = res * neg);
}
