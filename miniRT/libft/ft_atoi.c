/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:37:50 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:50:20 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void		ft_atoi_bis(double *res, double *neg, int *i, char *str)
{
	*res = 0;
	*neg = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32 ||
	str[*i] == ',' || ft_isalpha(str[*i]) == 1)
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg = -*neg;
		*i += 1;
	}
}

double		ft_atoi(char *str, int *i)
{
	double	res;
	double	neg;
	double	compt;

	res = 0;
	neg = 1;
	compt = 0;
	ft_atoi_bis(&res, &neg, i, str);
	while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '.')
	{
		if (str[*i] == '.')
			compt = 1;
		else
		{
			if (compt >= 1)
				compt++;
			res = res * 10 + str[*i] - 48;
		}
		*i += 1;
	}
	if (compt > 0)
		return (res = res / pow(10, compt - 1) * neg);
	else
		return (res = res * neg);
}
