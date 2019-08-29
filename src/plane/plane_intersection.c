/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:41:07 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 17:08:57 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int	plane_intersection(void *data, t_ray *view, t_vec3 *pos, t_real *t)
{
	t_vec3		vec;
	t_real		sc[5];
	t_plane		*plane;
	t_ray		axis_view;

	plane = (t_plane *)data;
	v3_sub(m3v3_mul(&plane->axis, &view->finish, &axis_view.finish), \
	m3v3_mul(&plane->axis, &view->start, &axis_view.start), &vec);
	sc[0] = v3_dot(&plane->norm, &plane->p);
	sc[1] = v3_dot(&plane->norm, &axis_view.start);
	sc[2] = v3_dot(&plane->norm, &vec);
	if (sc[2] == 0)
		return (0);
	sc[4] = (sc[0] - sc[1]) / sc[2];
	if (sc[4] < 0)
		return (0);
	if (t)
		*t = sc[4];
	m3v3_mul(&plane->inv_axis, v3_add(&axis_view.start, \
	v3s_mull(&vec, sc[4], pos), pos), pos);
	return (1);
}
