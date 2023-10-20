/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 10:19:33 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/16 13:25:26 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct		s_caracteristique
{
	int flag;
	int value;
}					t_caracteristique;
typedef struct		s_flag
{
	t_caracteristique flag_p;
	t_caracteristique flag_m;
	t_caracteristique flag_l;
	t_caracteristique flag_0;
}					t_flag;
typedef struct		s_chaine
{
	int deb_zero;
	int end_space;
	int taille_chaine;
	int taille_var;
	int deb_space;
}					t_chaine;
typedef struct		s_arg
{
	int		flag;
	char	*arg;
}					t_arg;
int					ft_printf(const char *s,
					...) __attribute__((format(printf,1,2)));
typedef int			(*t_taille_chaine)(char *spe, t_flag flags, va_list *list);
unsigned int		ft_nbrlen(unsigned long long int i);
unsigned int		ft_nbrlen_hexa(unsigned int i);
int					find_chr(char *tab, char chr);
int					chr_spe(char *tab);
int					is_char_op(char c);
t_caracteristique	value_to_flag(char *tab, char c, va_list list, int *i);
int					value_to_flag_p(char *tab, char c, va_list list, int *i);
void				init_flags(t_flag *flag);
t_flag				exceptions_t_op(t_flag flags);
t_flag				exceptions_t_op_bis(t_flag flags);
t_flag				trait_op(char *spe, va_list list);
void				init_tchaine(t_chaine *chaine);
int					type_flag(char c);
t_taille_chaine		good_fnct(char c);
char				*itoh(unsigned long long int nbr);
int					is_etoile(char *tab, va_list list);
t_caracteristique	value_larg_min(char *tab, va_list list, int *i);
char				*ft_strjoin_bis(char *s1, char *s2);
char				*itoh_bis(unsigned int nbr, int a);
char				*isnull(char *tab);
t_arg				extract_arg(va_list *list, char c);
int					creat_char(t_chaine chaine, t_arg arg);
int					creat_char_int(t_chaine chaine, t_arg arg);
int					creat_char_0(t_chaine chaine);
int					ischar_spe(char c);
int					ischar_var(char c);
int					varlen(char *tab);
void				ft_putstr(char *str);
t_chaine			regle_x_bis(t_chaine chaine, t_flag flags, t_arg arg);
t_chaine			regle_x(t_chaine chaine, t_flag flags, t_arg arg);
int					t_chaine_x(char *spe, t_flag flags, va_list *list);
t_chaine			regle_i_bis(t_chaine chaine, t_flag flags, t_arg arg);
t_chaine			regle_i(t_chaine chaine, t_flag flags, t_arg arg);
int					t_chaine_i(char *spe, t_flag flags, va_list *list);
t_chaine			regle_str(t_chaine chaine, t_flag flags, t_arg arg);
int					t_chaine_str(char *spe, t_flag flags, va_list *list);
t_chaine			regle_chr(t_chaine chaine, t_flag flags, t_arg arg);
int					t_chaine_chr(char *spe, t_flag flags, va_list *list);
t_chaine			regle_ad(t_chaine chaine, t_flag flags, t_arg arg);
int					t_chaine_adrss(char *spe, t_flag flags, va_list *list);
int					ft_printf(const char *str, ...);
t_chaine			regle_u_bis(t_chaine chaine, t_flag flags, t_arg arg);
t_chaine			regle_u(t_chaine chaine, t_flag flags, t_arg arg);
int					t_chaine_u(char *spe, t_flag flags, va_list *list);
char				*ft_utoa(unsigned int n);
int					t_chaine_prct(char *spe, t_flag flags, va_list *list);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					t_chaine_error(char *spe, t_flag flags, va_list *list);
int					ft_nbrlen_int(int i);
#endif
