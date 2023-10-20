/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:02:04 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 07:53:40 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_norm2
{
	t_list	*instruc;
	t_list	*tmp;
	t_list	*run;
}				t_norm2;

typedef struct s_norm
{
	int		pos;
	int		min;
	int		max;
	int		i;
	int		offset;
	int		size;
}				t_norm;

typedef struct s_liste
{
	int				nb;
	struct s_liste	*previous;
	struct s_liste	*next;
}				t_liste;

typedef struct s_instruc
{
	char			*instruction;
	struct s_liste	*next;
}				t_instruc;

typedef void	(*t_fnct)(t_liste **pile_a, t_liste **pile_b);
int		get_next_line(char **line, int fd);
int		check_argv(char **argv, int argc);
int		check_instruction(char *instruction);
void	add_front(t_liste **alst, t_liste *new);
void	add_back(t_liste **alst, t_liste *new);
void	keep_first(t_liste **pile, t_liste *first);
int		find_min(t_liste *a);
int		find_max(t_liste *a);
void	sa_fnct(t_liste **pile_a, t_liste **pile_b);
void	sb_fnct(t_liste **pile_a, t_liste **pile_b);
void	ss_fnct(t_liste **pile_a, t_liste **pile_b);
void	pa_fnct(t_liste **pile_a, t_liste **pile_b);
void	pb_fnct(t_liste **pile_a, t_liste **pile_b);
void	ra_fnct(t_liste **pile_a, t_liste **pile_b);
void	rb_fnct(t_liste **pile_a, t_liste **pile_b);
void	rr_fnct(t_liste **pile_a, t_liste **pile_b);
void	rra_fnct(t_liste **pile_a, t_liste **pile_b);
void	rrb_fnct(t_liste **pile_a, t_liste **pile_b);
void	rrr_fnct(t_liste **pile_a, t_liste **pile_b);
int		lstsize(t_liste *pile);
void	rm_el(t_liste **pile, t_liste *el);
void	display_pile(t_liste *pile, char *mess);
void	display_N_el(t_liste *liste, int num);
void	*find_last_el(t_liste *liste);
t_fnct	call_fnct(char *instruction);
void	error_exit(char *fnct);
t_liste	*arg_to_int(char **argv, int argc);
void	display_tab_int(int *tab, int size);
int		validate(t_liste *pile);
void	display_stacks(t_liste *a, t_liste *b);
t_list	*sort_2el(t_liste **pile_a, t_liste **pile_b);
t_list	*sort_3el(t_liste **pile_a, t_liste **pile_b);
t_list	*sort_5el(t_liste **pile_a, t_liste **pile_b);
t_list	*sort(t_liste **pile_a, t_liste **pile_b);
t_liste	*lastel(t_liste *liste);
t_list	*go_on_top_a(int pos, t_liste **pile_a, t_liste **pile_b);
t_list	*go_on_top_b(int pos, t_liste **pile_a, t_liste **pile_b);
void	add_instruction(t_list **instruc, t_list **tmp, char *fnct_name);
void	display_list(t_list *list);
t_list	*back_on_top_a(t_liste **pile_a, t_liste **pile_b, int pos, int way);
t_list	*back_on_top_b(t_liste **pile_a, t_liste **pile_b, int pos, int way);
int		find_path(t_liste *liste, int pos);
int		wich_closer(t_liste *pile_a, int min, int max);
t_list	*sort_piles(t_liste **pile_a, t_liste **pile_b);
void	display_pile_in_line(t_liste *pile);
int		find_offset(int size, int *min, int *max);
int		max(t_liste *pile);
void	error_exit(char *fnct);
int		check_pile(t_liste *pile_a);
#endif
