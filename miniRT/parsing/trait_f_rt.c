/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_f_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:53:32 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/13 15:38:53 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	init_type_tab(t_nbtype *nb_type, t_type *type)
{
	type->c = malloc(sizeof(t_c) * (nb_type->c.value + 1));
	type->l = malloc(sizeof(t_l) * (nb_type->l.value + 1));
	type->pl = malloc(sizeof(t_pl) * (nb_type->pl.value + 1));
	type->sp = malloc(sizeof(t_sp) * (nb_type->sp.value + 1));
	type->sq = malloc(sizeof(t_sq) * (nb_type->sq.value + 1));
	type->cy = malloc(sizeof(t_cy) * (nb_type->cy.value + 1));
	type->tr = malloc(sizeof(t_tr) * (nb_type->tr.value + 1));
}

int		ft_isalpha_str(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if ((str[i] < 65 || str[i] > 90) && (str[i] > 122 || str[i] < 97))
			return (0);
	return (1);
}

int		check_buff(char *tab)
{
	int i;
	int compt;

	i = -1;
	compt = 0;
	while (tab[++i + 1])
	{
		compt++;
		if ((ft_isalpha(tab[i]) != 1) && space(tab[i]) != 1 && tab[i] != '\n' &&
		tab[i] != '-' && ft_isdigit(tab[i]) == 0 && tab[i] != '.' &&
		tab[i] != ',' && tab[i])
			return (-1);
	}
	return (0);
}

char	**recup_el(int argc, char **argv)
{
	int		res;
	char	*buff;
	char	**tab;

	buff = take_buff(argc, argv);
	if (!buff)
	{
		ft_putstr("error: fd open failed\n");
		return (0);
	}
	if ((res = check_buff(buff)) == -1)
	{
		ft_putstr("erreur dans le fichier .rt\n");
		tab = NULL;
		return (tab);
	}
	tab = ft_split(buff, '\n');
	free(buff);
	return (tab);
}

int		trait_tab(char **tab, t_type *type)
{
	int			err;
	t_nbtype	nb_type;
	char		*liste[5];

	liste[1] = "error_config: id mal placés / inexistant";
	liste[2] = "error_config: mauvais nbr d'ID";
	liste[3] = "error_config: nb error";
	liste[4] = "error_config: ligne imcomplete";
	if ((err = check_error(tab)) != 0)
	{
		ft_putstr(liste[-err]);
		return (-1);
	}
	nb_type_init(&nb_type, tab);
	if (nb_type.r.value != 1)
	{
		ft_putstr("Error\npas de resolution\n");
		return (-1);
	}
	init_type_tab(&nb_type, type);
	init_last_structs(nb_type, type);
	return (0);
}
