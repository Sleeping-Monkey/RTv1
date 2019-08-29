/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:34:28 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:11:54 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static void	init_axis(t_plane *plane, t_vec3 *k)
{
	t_vec3	i;
	t_vec3	j;

	if (!k->z)
		i = VEC(0, 0, 1);
	else if (!k->y)
		i = VEC(0, 1, 0);
	else if (!k->x)
		i = VEC(1, 0, 0);
	else
		i = VEC(k->x, k->y, -(k->x * k->x + k->y * k->y) / k->z);
	v3_norm(&i, &i);
	v3_cross(k, &i, &j);
	plane->axis.r[0][0] = i.x;
	plane->axis.r[1][0] = i.y;
	plane->axis.r[2][0] = i.z;
	plane->axis.r[0][1] = j.x;
	plane->axis.r[1][1] = j.y;
	plane->axis.r[2][1] = j.z;
	plane->axis.r[0][2] = k->x;
	plane->axis.r[1][2] = k->y;
	plane->axis.r[2][2] = k->z;
}

t_object	*create_plane(t_vec3 pos, t_vec3 norm, t_color color, int ref)
{
	t_plane		*new_plane;
	t_object	*new_object;

	errno = 0;
	if (!(new_plane = (t_plane *)malloc(sizeof(t_plane))))
		msg_finish(MEM_MSG, NULL, errno);
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
		msg_finish(MEM_MSG, NULL, errno);
	v3_norm(&norm, &norm);
	init_axis(new_plane, &norm);
	m3_inv(&new_plane->axis, &new_plane->inv_axis);
	m3v3_mul(&new_plane->axis, &pos, &new_plane->p);
	m3v3_mul(&new_plane->axis, &norm, &new_plane->norm);
	new_plane->color = color;
	new_plane->reflection = ref;
	new_object->data = new_plane;
	new_object->get_color = get_plane_color;
	new_object->intersection = plane_intersection;
	return (new_object);
}
