/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:51:08 by ssheba            #+#    #+#             */
/*   Updated: 2019/09/05 18:07:55 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static void	odds_calc(t_real *sc, t_cone *cone, t_vec3 *vec)
{
	sc[0] = vec[1].x * vec[1].x + vec[1].y * vec[1].y \
	- cone->r_2 * vec[1].z * vec[1].z;
	sc[1] = vec[0].x * vec[1].x + vec[0].y * vec[1].y \
	- cone->r_2 * vec[0].z * vec[1].z;
	sc[2] = vec[0].x * vec[0].x + vec[0].y * vec[0].y \
	- cone->r_2 * vec[0].z * vec[0].z;
	sc[3] = sc[1] * sc[1] - sc[0] * sc[2];
}

int			cone_intersection(void *data, t_ray *view, t_vec3 *pos, t_real *t)
{
	t_vec3		vec[4];
	t_real		sc[5];
	t_cone		*cone;
	t_ray		axis_view;

	cone = (t_cone *)data;
	v3_sub(m3v3_mul(&cone->axis, &view->start, &axis_view.start), \
	&cone->o, vec + 0);
	v3_sub(m3v3_mul(&cone->axis, &view->finish, &axis_view.finish), \
	&axis_view.start, vec + 1);
	odds_calc(sc, cone, vec);
	if (sc[3] < 0)
		return (0);
	sc[4] = ((-sc[1] - sqrt(sc[3])) / sc[0]) >= 0 ? \
	((-sc[1] - sqrt(sc[3])) / sc[0]) : ((-sc[1] + sqrt(sc[3])) / sc[0]);
	if (sc[4] < 0)
		return (0);
	if (t)
		*t = sc[4];
	m3v3_mul(&cone->inv_axis, v3_add(&axis_view.start, \
	v3s_mull(vec + 1, sc[4], pos), pos), pos);
	return (1);
}
