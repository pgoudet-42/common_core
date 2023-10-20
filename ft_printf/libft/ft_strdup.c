/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:39:35 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/18 17:11:53 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*c;
	int		i;

	if (!src)
	{
		if (!(c = malloc(7)))
			return (0);
		c[0] = '(';
		c[1] = 'n';
		c[2] = 'u';
		c[3] = 'l';
		c[4] = 'l';
		c[5] = ')';
		c[6] = 0;
		return (c);
	}
	i = -1;
	c = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!c)
		return (NULL);
	while (++i < (int)ft_strlen(src))
		c[i] = src[i];
	c[i] = 0;
	return (c);
}
