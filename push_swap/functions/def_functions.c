/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:02:07 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 07:50:28 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	call_fnct2(char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0)
		return (0);
	else if (ft_strcmp(instruction, "sb") == 0)
		return (1);
	else if (ft_strcmp(instruction, "ss") == 0)
		return (2);
	else if (ft_strcmp(instruction, "pa") == 0)
		return (3);
	else if (ft_strcmp(instruction, "pb") == 0)
		return (4);
	else if (ft_strcmp(instruction, "ra") == 0)
		return (5);
	else if (ft_strcmp(instruction, "rb") == 0)
		return (6);
	else if (ft_strcmp(instruction, "rr") == 0)
		return (7);
	else if (ft_strcmp(instruction, "rra") == 0)
		return (8);
	else if (ft_strcmp(instruction, "rrb") == 0)
		return (9);
	else if (ft_strcmp(instruction, "rrr") == 0)
		return (10);
	return (-1);
}

t_fnct 	call_fnct(char *instruction)
{
	int		res;
	t_fnct	tab_fnct[11];

	tab_fnct[0] = sa_fnct;
	tab_fnct[1] = sb_fnct;
	tab_fnct[2] = ss_fnct;
	tab_fnct[3] = pa_fnct;
	tab_fnct[4] = pb_fnct;
	tab_fnct[5] = ra_fnct;
	tab_fnct[6] = rb_fnct;
	tab_fnct[7] = rr_fnct;
	tab_fnct[8] = rra_fnct;
	tab_fnct[9] = rrb_fnct;
	tab_fnct[10] = rrr_fnct;
	res = call_fnct2(instruction);
	if (res == -1)
		return (NULL);
	return (tab_fnct[res]);
}

void	error_exit(char *fnct)
{
	write(1, "error in function :", 19);
	write(1, fnct, ft_strlen(fnct));
	exit(-1);
}
