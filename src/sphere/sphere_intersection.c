/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:08:05 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 17:10:17 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int	sphere_intersection(void *data, t_ray *view, t_vec3 *pos, t_real *t)
{
	t_vec3		vec[2];
	t_ray		axis_view;
	t_real		sc[5];
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	v3_sub(m3v3_mul(&sphere->axis, &view->finish, &axis_view.finish), \
	m3v3_mul(&sphere->axis, &view->start, &axis_view.start), vec + 0);
	v3_sub(&axis_view.start, &sphere->o, vec + 1);
	sc[0] = v3_dot(vec + 0, vec + 0);
	sc[1] = v3_dot(vec + 0, vec + 1);
	sc[2] = v3_dot(vec + 1, vec + 1) - sphere->r * sphere->r;
	sc[3] = sc[1] * sc[1] - sc[0] * sc[2];
	if (sc[3] < 0)
		return (0);
//	sc[4] = (-sc[1] - sqrt(sc[3])) / sc[0] >= 0 ? \
//	(-sc[1] - sqrt(sc[3])) / sc[0] : (-sc[1] + sqrt(sc[3])) / sc[0];
	sc[4] = (-sc[1] - sqrt(sc[3])) / (sc[0]);
	if (t)
		*t = sc[4];
	if (sc[4] < 0)
		return (0);
	m3v3_mul(&sphere->inv_axis, \
	v3_add(&axis_view.start, v3s_mull(vec + 0, sc[4], pos), pos), pos);
	return (1);
}
