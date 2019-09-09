/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:34:28 by ssheba            #+#    #+#             */
/*   Updated: 2019/09/04 17:45:41 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

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
	m3_zero(&new_plane->axis);
	new_plane->axis.r[0][0] = 1;
	new_plane->axis.r[1][1] = 1;
	new_plane->axis.r[2][2] = 1;
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
