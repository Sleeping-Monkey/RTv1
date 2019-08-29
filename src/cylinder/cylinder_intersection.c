/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:58:32 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/09 09:40:46 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int	cylinder_intersection(void *data, t_ray *view, t_vec3 *pos, t_real *t)
{
	t_vec3		vec[4];
	t_real		sc[5];
	t_cylinder	*cylinder;
	t_ray		axis_view;

	cylinder = (t_cylinder *)data;
	v3_sub(m3v3_mul(&cylinder->axis, &view->start, &axis_view.start), &cylinder->o, vec + 0);
	v3_sub(m3v3_mul(&cylinder->axis, &view->finish, &axis_view.finish), &axis_view.start, vec + 1);
	sc[0] = vec[1].x * vec[1].x + vec[1].y * vec[1].y;
	sc[1] = vec[0].x * vec[1].x + vec[0].y * vec[1].y;
	sc[2] = vec[0].x * vec[0].x + vec[0].y * vec[0].y - cylinder->radius * cylinder->radius;
	sc[3] = sc[1] * sc[1] - sc[0] * sc[2];
	if (sc[3] < 0)
		return (0);
	sc[4] = (-sc[1] - sqrt(sc[3])) / (sc[0]) >= 0 ? (-sc[1] - sqrt(sc[3])) / (sc[0]) : (-sc[1] + sqrt(sc[3])) / (sc[0]);
	if (sc[4] < 0)
		return (0);
	if (t)
		*t = sc[4];
	m3v3_mul(&cylinder->inv_axis, v3_add(&axis_view.start, v3s_mull(vec + 1, sc[4], pos), pos), pos);
	return (1);
}