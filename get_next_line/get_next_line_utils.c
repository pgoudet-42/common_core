/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:55:48 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/04 15:13:44 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int			i;
	char		*tab;
	const char	*tab2;

	if (dest == NULL && src == NULL)
		return (dest);
	tab2 = (const char *)src;
	tab = (char *)dest;
	i = 0;
	while (i < n)
	{
		tab[i] = tab2[i];
		i++;
	}
	tab[i] = 0;
	return (dest);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s)
		return (0);
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (0);
	if (start >= ft_strlen(s))
	{
		tab[0] = 0;
		free(s);
		return (tab);
	}
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[len] = 0;
	free(s);
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		len;

	i = -1;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!tab)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		tab[i] = s1[i];
	len = -1;
	while (++len < (int)ft_strlen(s2))
		tab[i + len] = s2[len];
	tab[i + len] = 0;
	free(s1);
	return (tab);
}

int		pn(char *tab)
{
	int i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
