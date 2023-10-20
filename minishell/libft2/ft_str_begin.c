/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_begin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:08:37 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/15 06:40:02 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

int	ft_str_begin(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 == *p2 && *p2)
	{
		p1++;
		p2++;
	}
	return (!*p2);
}
