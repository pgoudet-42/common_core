/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:39:35 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/11 06:24:05 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*c;
	int		taille_src;
	int		i;

	taille_src = ft_strlen(src);
	i = 0;
	c = malloc(sizeof(char) * taille_src + 1);
	if (!c)
		return (NULL);
	while (i < taille_src)
	{
		c[i] = src[i];
		i++;
	}
	c[i] = 0;
	return (c);
}
