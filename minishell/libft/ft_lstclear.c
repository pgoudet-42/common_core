/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:19:04 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/17 15:08:45 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*n;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		free_fct(begin_list->content);
		n = begin_list->next;
		free(begin_list);
		begin_list = n;
	}
}
