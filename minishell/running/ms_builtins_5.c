/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:55:55 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/18 10:09:53 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ms_builtins.h"

int	ms_cmp(char *s1, char *s2)
{
	return (ft_strcmp(s1, s2));
}

void	ms_del(void *p)
{
	(void)p;
	return ;
}

void	export_one(char *s)
{
	int	j;

	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	j = 0;
	while ((s[j] && s[j] != '='))
		write(STDOUT_FILENO, &s[j++], 1);
	if (s[j])
		j++;
	write(STDOUT_FILENO, "=\"", 2);
	while (s[j])
		write(STDOUT_FILENO, &s[j++], 1);
	ft_putendl_fd("\"", STDOUT_FILENO);
}

void	ms_sort_print_export(char **env)
{
	t_list	*ls;
	t_list	*l1;
	int		i;

	ls = NULL;
	i = 0;
	while (env[i])
	{
		l1 = ft_lstnew(env[i]);
		ft_lstadd_front(&ls, l1);
		i++;
	}
	ft_list_sort(&ls, ms_cmp);
	l1 = ls;
	while (l1)
	{
		export_one(l1->content);
		l1 = l1->next;
	}
	ft_lstclear(ls, ms_del);
}
