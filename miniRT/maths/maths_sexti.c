/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_sexti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:48:00 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:49:44 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

double		eq_2deg(double part_a, double part_b, double part_c)
{
	double discriminant;
	double t;

	discriminant = pow(part_b, 2) - (4 * part_a * part_c);
	if (discriminant < 0)
		return (-1);
	t = (-part_b - sqrt(discriminant)) / (2 * part_a);
	if (t <= 0)
	{
		t = (-part_b + sqrt(discriminant)) / (2 * part_a);
		if (t <= 0)
			t = -1;
	}
	return (t);
}

t_vecteur	calcul_matriciel(t_vecteur u, double *angle_y, double *angle_z)
{
	t_vecteur v_res;
	t_vecteur v_res_fin;

	if (*angle_y < 0)
		*angle_y = angle_sury(u);
	v_res.x = cos1(*angle_y) * u.x - sin1(*angle_y) * u.y;
	v_res.y = (sin1(*angle_y) * u.x) + (cos1(*angle_y) * u.y);
	v_res.z = (u.z);
	if (*angle_z < 0)
		*angle_z = angle_surz(v_res);
	v_res_fin.x = v_res.x;
	v_res_fin.y = (v_res.y * cos1(*angle_z)) - (sin1(*angle_z) * v_res.z);
	v_res_fin.z = (v_res.y * sin1(*angle_z)) - (cos1(*angle_z) * v_res.z);
	return (v_res_fin);
}

t_vecteur	calcul_matriciel2(t_vecteur u, double angle_z, t_vecteur v_fin)
{
	t_vecteur	v_res;
	t_vecteur	v_res_fin;
	double		angle_x;

	v_fin.z = 0;
	v_fin.x = 0;
	v_res.x = u.x;
	v_res.y = cos1(angle_z) * u.y - sin1(angle_z) * u.z;
	v_res.z = (sin1(angle_z) * u.x) + (cos1(angle_z) * u.y);
	angle_x = acos((produit_scalaire(v_res, v_fin) /
	(taille_vecteur(v_res) * taille_vecteur(v_fin)))) / 0.0174533;
	v_res_fin.x = (v_res.x * cos1(angle_x)) + (sin1(angle_x) * v_res.z);
	v_res_fin.y = v_res.y;
	v_res_fin.z = -(v_res.x * sin1(angle_x)) + (cos1(angle_x) * v_res.z);
	return (v_res_fin);
}

t_point		calcul_matriciel3(t_point p, double angle_y, double angle_z)
{
	t_point p_res;
	t_point p_res_fin;

	p_res.x = cos1(angle_y) * p.x - sin1(angle_y) * p.y;
	p_res.y = (sin1(angle_y) * p.x) + (cos1(angle_y) * p.y);
	p_res.z = (p.z);
	p_res_fin.x = p_res.x;
	p_res_fin.y = (p_res.y * cos1(angle_z)) - (sin1(angle_z) * p_res.z);
	p_res_fin.z = (p_res.y * sin1(angle_z)) - (cos1(angle_z) * p_res.z);
	return (p_res_fin);
}

t_vecteur	calcul_matriciel4(t_vecteur u, double angle_y, double angle_z)
{
	t_vecteur v_res;
	t_vecteur v_res_fin;

	v_res.x = cos1(angle_y) * u.x - sin1(angle_y) * u.y;
	v_res.y = (sin1(angle_y) * u.x) + (cos1(angle_y) * u.y);
	v_res.z = (u.z);
	v_res_fin.x = v_res.x;
	v_res_fin.y = (v_res.y * cos1(angle_z)) - (sin1(angle_z) * v_res.z);
	v_res_fin.z = (v_res.y * sin1(angle_z)) - (cos1(angle_z) * v_res.z);
	return (v_res_fin);
}
