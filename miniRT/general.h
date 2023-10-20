/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:24:05 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/03 09:23:53 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef	struct	s_img
{
	int		endian;
	int		bpp;
	int		size_line;
	int		*img_data;
	void	*img_ptr;
	char	check[2];
}				t_img;

typedef	struct	s_deplacement
{
	int x;
	int z;
}				t_deplacement;

typedef	struct	s_color
{
	int	o;
	int	r;
	int	g;
	int	b;
	int	final;
}				t_color;

typedef struct	s_obj
{
	int value;
	int flag_m;
}				t_obj;

typedef struct	s_nbtype
{
	t_obj r;
	t_obj a;
	t_obj c;
	t_obj l;
	t_obj pl;
	t_obj sp;
	t_obj sq;
	t_obj cy;
	t_obj tr;
}				t_nbtype;

typedef struct	s_id
{
	void	*mlx_ptr;
	void	*wd_ptr;
	t_img	*img;
}				t_id;

typedef struct	s_vecteur
{
	double x;
	double y;
	double z;
}				t_vecteur;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	char	check[2];
}				t_point;

typedef struct	s_eqplan
{
	double a;
	double b;
	double c;
	double d;
}				t_eqplan;

typedef	struct	s_pl
{
	t_color		color;
	t_point		p;
	t_eqplan	eq;
	t_vecteur	v_or;
	char		check[2];
}				t_pl;

typedef struct	s_sq
{
	t_color		color;
	t_point		p;
	t_point		p2;
	t_point		p3;
	t_point		p4;
	t_vecteur	v;
	t_pl		pl;
	double		hauteur;
	double		diagonale;
	double		aire;
	char		check[2];
}				t_sq;

typedef struct	s_tr
{
	t_color		color;
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_pl		pl;
	char		check[2];
}				t_tr;

typedef	struct	s_sp
{
	t_color		color;
	t_point		p;
	t_vecteur	v;
	double		diam;
	char		check[2];
}				t_sp;

typedef	struct	s_cy
{
	t_color		color;
	double		diam;
	double		haut;
	t_point		p;
	t_point		p_opp;
	t_point		pc;
	t_vecteur	v_or;
	t_vecteur	axe;
	t_eqplan	eq_p;
	t_eqplan	eq_p_opp;
	char		check[2];
}				t_cy;

typedef struct	s_droite
{
	t_vecteur	v;
	t_point		p;
}				t_droite;

typedef	struct	s_l
{
	t_color	color;
	t_point p;
	double	ra_lum;
	char	check[2];
}				t_l;

typedef	struct	s_c
{
	t_vecteur	v_ver;
	t_vecteur	v_hor;
	t_point		pc;
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		p4;
	t_vecteur	v;
	double		rax;
	double		raz;
	double		fov;
	char		check[2];
}				t_c;

typedef	struct	s_a
{
	t_color	color;
	double	ra;
}				t_a;

typedef struct	s_r
{
	int largeur;
	int hauteur;
}				t_r;

typedef struct	s_type
{
	t_sq		*sq;
	t_sp		*sp;
	t_tr		*tr;
	t_cy		*cy;
	t_pl		*pl;
	t_l			*l;
	t_c			*c;
	t_r			r;
	t_a			a;
	t_id		id;
	int			nb_cam;
	char		*args;
}				t_type;

typedef struct	s_inter
{
	t_point		p;
	double		dist;
	t_eqplan	eq;
	char		check[2];
	t_color		color;
	t_droite	d_ray;
	double		angle;

}				t_inter;

double			taille_vecteur(t_vecteur v);
t_vecteur		vecteur_normal(t_vecteur u);
double			produit_scalaire(t_vecteur v, t_vecteur u);
t_vecteur		vecteur(t_point a, t_point b);
t_vecteur		produit_vectoriel(t_vecteur v, t_vecteur u);
t_vecteur		vecteur_normal(t_vecteur v);
double			distance_pt_pl(t_point pt, t_eqplan eq);
t_point			projete_ortho(t_point p, t_vecteur n, t_eqplan eq);
t_point			projete_ortho_dr(t_droite d, t_point pt);
int				equ_sp(t_point *pt, t_point centre, double diam);
double			angle_horiz(t_vecteur v);
double			angle_uv(t_vecteur v, t_vecteur u);
double			angle_surz(t_vecteur u);
double			angle_sury(t_vecteur u);
double			angle_surx(t_vecteur u);
double			sin1(double nb);
double			cos1(double nb);
double			distance_pt_pt(t_point p_ref, t_point p2);
double			min(double a, double b, double c);
double			max(double a, double b, double c);
double			distance(double start, double end);
void			max_min(double *max, double *min);
t_vecteur		calcul_matriciel(t_vecteur u, double *angle_y, double *angle_z);
t_vecteur		calcul_matriciel2(t_vecteur u, double angle_z, t_vecteur v_fin);
t_point			calcul_matriciel3(t_point p, double angle_y, double angle_z);
t_vecteur		calcul_matriciel4(t_vecteur u, double angle_y, double angle_z);
double			angle_surx(t_vecteur u);
double			angle_sury(t_vecteur u);
double			angle_surz(t_vecteur u);
t_point			inter_pl(t_droite d, t_pl *pl);
t_eqplan		eq_plan(t_point p1, t_point p2, t_point p3);
t_vecteur		v_from_eq(t_eqplan eq);
t_vecteur		addition_vecteurs(t_vecteur v1, t_vecteur v2);
void			normalisation_vecteurs(t_vecteur *v);
t_point			p_fois_v(t_point pt, t_vecteur v, double t);
t_vecteur		moins_v(t_vecteur v);
double			eq_2deg(double part_a, double part_b, double part_c);
typedef void	(*t_init_val)(char *tab, t_type type);
int				check_buff(char *tab);
char			**recup_el(int argc, char **argv);
int				trait_tab(char **tab, t_type *type);
void			init_t_nbtype(t_nbtype *nb_type);
int				traitement_id(char *str);
void			trait_type(char *tab, t_obj *obj, int i);
void			nb_type_init(t_nbtype *nb_type, char **tab);
int				too_val(char **tab);
int				check_error(char **tab);
int				space(char c);
int				check_tab(char **tab);
int				is_id(char *c);
char			**trait_lign(char *ligne);
void			init_type_values(t_type *type, char **tab, int len);
void			init_r_val(char *tab, t_type *type);
void			init_a_val(char *tab, t_type *type);
void			init_c_val(char *tab, t_type *type);
void			init_l_val(char *tab, t_type *type);
void			init_pl_val(char *tab, t_type *type);
void			init_cy_val(char *tab, t_type *type);
void			init_sp_val(char *tab, t_type *type);
void			init_tr_val(char *tab, t_type *type);
void			init_sq_val(char *tab, t_type *type);
void			init_sq(t_sq *sq);
void			init_cy_values(t_cy *cy);
void			init_type_tab(t_nbtype *nb_type, t_type *type);
void			init_last_structs(t_nbtype nbtype, t_type *type);
void			init_cam(t_c *cam, double largeur_ecran, double hauteur_ecran);
void			init_oeil(t_point *p, t_type *type, int i);
void			init_droite(t_droite *d, t_point dp, t_point pcible);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putstr(const char *str);
int				close_window(int key, t_type *type);
int				exit_hook(t_type *type);
int				gestion_window(int key, t_type *type);
int				is_single(char *str);
int				is_eq_cylindre(t_point *m, t_cy *cy);
t_point			idoubler(t_droite d, t_tr *tr);
t_point			is_sphere(t_sp *sp, t_droite d);
t_point			is_sq(t_droite d, t_sq *sq);
t_point			is_pl(t_droite d, t_pl *pl);
t_point			is_cy(t_droite d, t_cy *cy);
double			isintr(t_point a, t_point b, t_point c, t_point m);
int				is_between(t_point p, t_sq sq);
void			is_qqch3(t_type *type, t_droite d, t_inter *inter);
void			is_qqch2(t_type *type, t_droite d, t_inter *inter);
t_inter			is_qqch(t_type *type, t_droite d, double lum_dist);
void			take_info2(t_sq sq, t_inter *inter,
				t_point pt_check, t_droite d);
void			take_info(t_cy cy, t_inter *inter,
				t_point pt_check, t_droite d);
double			find_ptcommun_sp(t_droite d, t_sp *sp);
double			find_ptcommun_cy(t_droite d, t_cy *cy);
double			find_ptcommun_cir(t_droite d, t_cy *cy);
int				aff_pixel(int key, t_type *type);
int				aff_sur_cam(t_type *type);
t_eqplan		eq_plan2(t_vecteur n, t_point p);
int				check_eqpl(t_pl pl, t_point p);
int				color_value(t_color color);
t_color			spot2(t_type *type, t_inter inter);
t_point			p_fois_v(t_point pt, t_vecteur v, double t);
double			find_ptcommun_cy2(t_droite d, t_cy *cy);
double			find_ptcommun_cy3(t_droite d, t_cy *cy);
int				aff_cy(int key, t_type *type);
int				enregistrement(t_type type);
t_point			is_tr(t_droite d, t_tr *tr);
void			init_point(t_point *p, double x, double y, double z);
void			init_vecteur(t_vecteur *v, double x, double y, double z);
void			init_color(t_color *c, double x, double y, double z);
t_color			lum_pond(t_color color, double res_ps);
t_color			color_max(t_color *lum_tab, int len);
t_color			addition_color(t_color c1, t_color c2);
t_color			couleur_moyenne(t_color *color_tab,
				double res_ps, double side, int len);
t_droite		ray(t_inter inter, t_vecteur v);
int				check_filling(char **tab);
int				size_file(const char *file);
char			*take_buff(int argc, char **argv);
#endif
