/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:22:40 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/17 15:09:06 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swp(t_list *l)
{
	void	*swp;

	swp = l->content;
	l->content = l->next->content;
	l->next->content = swp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		flag;
	t_list	*l;

	if (!begin_list || !(*begin_list) || !(*begin_list)->next)
		return ;
	flag = 0;
	while (!flag)
	{
		flag = 1;
		l = *begin_list;
		while (l)
		{
			if (l->next)
			{
				if (cmp(l->content, l->next->content) > 0)
				{
					ft_swp(l);
					flag = 0;
				}
			}
			l = l->next;
		}
	}
}
