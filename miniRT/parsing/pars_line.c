/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:49 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/13 16:22:58 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

char	**trait_lign(char *ligne)
{
	char **tab;

	tab = ft_split(ligne, ' ');
	return (tab);
}

void	init_type_values(t_type *type, char **tab, int len)
{
	int			i;
	int			j;
	void		(*f[9]) (char *, t_type *);

	f[0] = &init_r_val;
	f[1] = &init_a_val;
	f[2] = &init_c_val;
	f[3] = &init_l_val;
	f[4] = &init_sp_val;
	f[5] = &init_pl_val;
	f[6] = &init_sq_val;
	f[7] = &init_cy_val;
	f[8] = &init_tr_val;
	i = 0;
	j = 0;
	while (tab[j] && j < len)
	{
		i = traitement_id(tab[j]) - (is_single(tab[j]));
		if (i > 10)
			i -= 10;
		f[i - 1](tab[j], type);
		j++;
	}
}
