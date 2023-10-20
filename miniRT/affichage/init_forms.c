/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:54:22 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:37:03 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	init_sq(t_sq *sq)
{
	t_vecteur n;

	n = vecteur_normal(sq->v);
	sq->p4.x = sq->p.x + (sq->v.x * sq->hauteur);
	sq->p4.y = sq->p.y + (sq->v.y * sq->hauteur);
	sq->p4.z = sq->p.z + (sq->v.z * sq->hauteur);
	sq->p2.x = sq->p.x + (n.x * sq->hauteur);
	sq->p2.y = sq->p.y + (n.y * sq->hauteur);
	sq->p2.z = sq->p.z + (n.z * sq->hauteur);
	sq->p3.x = sq->p2.x + (sq->v.x * sq->hauteur);
	sq->p3.y = sq->p2.y + (sq->v.y * sq->hauteur);
	sq->p3.z = sq->p2.z + (sq->v.z * sq->hauteur);
	sq->aire = sq->hauteur * sq->hauteur;
	sq->pl.eq = eq_plan(sq->p, sq->p2, sq->p3);
}

void	init_cy_values(t_cy *cy)
{
	t_vecteur n;

	n = vecteur_normal(cy->v_or);
	normalisation_vecteurs(&n);
	cy->p_opp.x = cy->p.x + (cy->haut * cy->v_or.x);
	cy->p_opp.y = cy->p.y + (cy->haut * cy->v_or.y);
	cy->p_opp.z = cy->p.z + (cy->haut * cy->v_or.z);
	cy->axe = vecteur(cy->p, cy->p_opp);
	cy->pc = p_fois_v(cy->p, n, cy->haut / 2);
	cy->eq_p.a = cy->v_or.x;
	cy->eq_p.b = cy->v_or.y;
	cy->eq_p.c = cy->v_or.z;
	cy->eq_p.d = cy->eq_p.a * cy->p.x + cy->eq_p.b *
	cy->p.y + cy->eq_p.c * cy->p.z;
	cy->eq_p_opp.a = cy->v_or.x;
	cy->eq_p_opp.b = cy->v_or.y;
	cy->eq_p_opp.c = cy->v_or.z;
	cy->eq_p_opp.d = cy->eq_p_opp.a * cy->p.x +
	cy->eq_p_opp.b * cy->p.y + cy->eq_p_opp.c * cy->p.z;
}

void	init_cam(t_c *cam, double largeur_ecran, double hauteur_ecran)
{
	t_vecteur	v_ref;

	init_vecteur(&v_ref, 0, 0, 1);
	cam->rax = ((cam->fov * 0.01745) / largeur_ecran);
	cam->raz = cam->rax;
	if (cam->v.x == 0 && cam->v.y == 0 && cam->v.z != 0)
	{
		init_vecteur(&cam->v_hor, 1, 0, 0);
		init_vecteur(&cam->v_ver, 0, 1, 0);
	}
	else
	{
		cam->v_hor = produit_vectoriel(v_ref, cam->v);
		cam->v_ver = produit_vectoriel(cam->v, cam->v_hor);
	}
	normalisation_vecteurs(&cam->v);
	normalisation_vecteurs(&cam->v_ver);
	normalisation_vecteurs(&cam->v_hor);
	cam->p2 = p_fois_v(cam->p1, cam->v_hor, largeur_ecran * cam->rax);
	cam->p4 = p_fois_v(cam->p1, cam->v_ver, hauteur_ecran * cam->rax);
	cam->p3 = p_fois_v(cam->p4, cam->v_hor, largeur_ecran * cam->rax);
	cam->pc = p_fois_v(cam->p1, cam->v_hor, (largeur_ecran / 2) * cam->rax);
	cam->pc = p_fois_v(cam->pc, cam->v_ver, (hauteur_ecran / 2) * cam->rax);
}

void	init_oeil(t_point *p, t_type *type, int i)
{
	*p = p_fois_v(type->c[i].pc, moins_v(type->c[i].v), 1);
}

void	init_droite(t_droite *d, t_point dp, t_point pcible)
{
	d->p = dp;
	d->v = vecteur(d->p, pcible);
}
