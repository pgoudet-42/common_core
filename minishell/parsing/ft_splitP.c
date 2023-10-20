/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitP.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 06:23:50 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/18 16:27:24 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*copy2(const char *charset, char *arg, int size)
{
	char	*tab;
	int		j;
	int		i;

	j = -1;
	i = -1;
	tab = malloc(size + 1);
	if (!tab)
		return (NULL);
	while (++j < (int)ft_strlen(arg) && arg[j]
		&& is_charset(arg[j], charset) == 0)
	{
		if (arg[j] == 34)
			while (arg[++j] && arg[j] != 34)
				tab[++i] = arg[j];
		else if (arg[j] == 39)
			while (arg[j] && arg[j] != 39)
				tab[++i] = arg[j];
		else
			tab[++i] = arg[j];
	}
	tab[++i] = 0;
	return (tab);
}

static char	**convertarg2(char **newenvp, char **envp, int *i, int *j)
{
	*i = 0;
	*j = -1;
	while (envp[*i])
		(*i)++;
	newenvp = malloc(sizeof(void *) * (*i + 2));
	if (!newenvp)
		return (NULL);
	newenvp[*i + 1] = NULL;
	while (envp[++(*j)])
	{
		newenvp[*j] = ft_strdup(envp[*j]);
		free(envp[*j]);
	}
	return (newenvp);
}

int	convertarg(char *arg, char **envp, const char *charset)
{
	char	**newenvp;
	int		i;
	int		j;

	newenvp = NULL;
	newenvp = convertarg2(newenvp, envp, &i, &j);
	if (!newenvp)
		return (-1);
	i = -1;
	while (arg[++i] && is_charset(arg[i], charset) == 0)
		if (arg[i] == 34 || arg[i] == 39)
			i += gotonextquote(&arg[i], i);
	newenvp[j + 1] = malloc(i + 1);
	if (!newenvp[j + 1])
		return (-1);
	newenvp[++j] = copy2(charset, arg, i);
	envp = newenvp;
	return (i);
}

char	**ft_splitp(char *arg, const char *charset)
{
	int		i;
	int		j;
	char	**argv;

	i = compt_word(&arg, charset);
	argv = malloc(sizeof(void *) * (i + 1));
	i = -1;
	j = -1;
	while (++i < (int)ft_strlen(arg) && arg[i])
	{
		while (is_charset(arg[i], charset) == 1
			&& bsvalid(arg, i) == 0 && is_inquote(i, arg) == 0)
			i++;
		while (i < (int)ft_strlen(arg) && ((arg[i] == 39 || arg[i] == 34)
				&& bsvalid(arg, i) == 0))
			argv[++j] = copyquotearg(&arg[i], &i);
		argv[++j] = checkdeclar(&arg[i], charset, &i);
		if (argv[j] == NULL || argv[j][0] == 0)
			free(argv[j--]);
	}
	free(arg);
	argv[++j] = NULL;
	return (argv);
}
