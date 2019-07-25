/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:08:05 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/25 16:49:48 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int	sphere_intersection(void *data, t_ray *view, t_vector *pos)
{
	t_vector	vec[2];
	t_real		sc[5];
	t_sphere	*sphere;

	printf("\tstart sphere\n");
	sphere = (t_sphere *)data;
	printf("\t\t(%f, %f, %f) - %f\n", sphere->center.x, sphere->center.y, sphere->center.z, sphere->radius);
	vec[0] = sub_vec(&view->finish, &view->start);
	vec[1] = sub_vec(&view->start, &sphere->center);
	printf("\t\tFS = (%f, %f, %f), SO = (%f, %f, %f)\n", vec[0].x, vec[0].y, vec[0].z, vec[1].x, vec[1].y, vec[1].z);
	sc[0] = scalar_prod(vec + 0, vec + 0);
	sc[1] = scalar_prod(vec + 0, vec + 1);
	sc[2] = scalar_prod(vec + 1, vec + 1);
	sc[3] = sc[1] * sc[1] - sc[0] * sc[2];
	printf("\t\t%f -- %f -- %f\n\tdisc = %f\n", sc[0], sc[1], sc[2], sc[3]);
	if (sc[3] < 0)
		return (0);
	sc[4] = (-sc[1] + sqrt(sc[3])) / sc[0];
	*pos = mul_vec_real(vec + 0, sc[4]);
	*pos = add_vec(&view->start, pos);
	printf("\tpos = (%f, %f, %f)\n", pos->x, pos->y, pos->z);
	return (1);
}