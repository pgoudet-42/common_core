/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:39:11 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/15 07:42:04 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*malloc_tab(char *s, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dest = malloc(sizeof(*dest) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	nombre_mots(char *s, char c)
{
	int	i;
	int	count;
	int	mot;

	count = 0;
	mot = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (mot == 0)
				count++;
			mot = 1;
			i++;
		}
		mot = 0;
	}
	return (count + 1);
}

void	free_tab(char **dest, int k)
{
	while (--k >= 0)
		free(dest[k]);
	free(dest);
}

char	**check_dest(int *k, const char *s, int c, char **dest)
{
	dest[*k] = malloc_tab((char *)s, c);
	if (!(dest[*k]))
	{
		free_tab(dest, *k);
		return (NULL);
	}
	(*k)++;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		k;

	k = 0;
	dest = malloc(sizeof(*dest) * nombre_mots((char *)s, c));
	if (!dest)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			dest = check_dest (&k, s, c, dest);
			if (!dest)
				return (NULL);
		}
		while (*s && *s != c)
			s++;
	}
	dest[k] = 0;
	return (dest);
}
