/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:01:46 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 16:11:04 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	check_argv(char **argv, int argc)
{
	int	i;
	int	j;

	if (argc == 1)
		return (0);
	if (argv == NULL)
		return (-1);
	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' && argv[i][j] > '9')
				return (-1);
		}
	}
	return (0);
}

int	check_instruction_bis(char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0)
		return (0);
	else if (ft_strcmp(instruction, "sb") == 0)
		return (0);
	else if (ft_strcmp(instruction, "ss") == 0)
		return (0);
	else if (ft_strcmp(instruction, "pa") == 0)
		return (0);
	else if (ft_strcmp(instruction, "pb") == 0)
		return (0);
	else if (ft_strcmp(instruction, "ra") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rb") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rr") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rra") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rrb") == 0)
		return (0);
	else if (ft_strcmp(instruction, "rrr") == 0)
		return (0);
	else
		return (-1);
}

int	check_instruction(char *instruction)
{
	char	**new;
	int		res;

	res = -1;
	if (*instruction == 16 || *instruction == 14 || *instruction == 0)
		return (0);
	new = ft_split((const char *)instruction, 10);
	while (*new != NULL)
	{
		res = check_instruction_bis(*new);
		if (res == -1)
			return (-1);
		new++;
	}
	return (res);
}

int	validate(t_liste *pile)
{
	while (pile)
	{
		if (pile->next && pile->next->nb < pile->nb)
			return (-1);
		if (pile->next && pile->next->nb < pile->nb)
			return (-1);
		pile = pile->next;
	}
	return (0);
}
