/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:01:53 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 16:12:08 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	apply_fnct(t_liste **pile_a, t_liste **pile_b, char *instruction)
{
	char	**instructs;

	instructs = ft_split((const char *)instruction, 10);
	if (*instructs && ft_isascii(**instructs) != 14)
	{
		while (*instructs && ft_isascii(**instructs) != 14)
		{
			call_fnct(*instructs)(pile_a, pile_b);
			instructs++;
		}
	}
}

static void	display_answer(char *instruction, t_liste *pile_a, t_liste *pile_b)
{
	if (check_instruction(instruction) == -1)
		error_exit("check_instruction");
	if (validate(pile_a) == 0)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	apply_fnct(&pile_a, &pile_b, instruction);
	if (validate(pile_a) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	char	*instruction;
	t_liste	*pile_a;
	t_liste	*pile_b;

	if (check_argv(argv, argc) == -1)
		error_exit("main");
	if (argc == 1)
		return (0);
	pile_a = arg_to_int(argv, argc);
	pile_b = NULL;
	instruction = malloc(1);
	*instruction = 0;
	while (get_next_line(&instruction, 0) > 0)
		if (check_instruction(instruction) == -1)
			error_exit("check_instruction");
	display_answer(instruction, pile_a, pile_b);
	return (0);
}
