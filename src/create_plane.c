/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:34:28 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/07 16:14:50 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_object		*create_plane(t_vec3 pos, t_vec3 norm, t_color color, int ref)
{
	t_plane		*new_plane;
	t_object	*new_object;

	if (!(new_plane = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
	{
		free(new_plane);
		return (NULL);
	}
	m3_zero(&new_plane->axis);
	new_plane->axis.r[0][0] = 1;
	new_plane->axis.r[1][1] = 1;
	new_plane->axis.r[2][2] = 1;
	m3_inv(&new_plane->axis, &new_plane->inv_axis);
	new_plane->p = pos;
	v3_norm(&norm, &new_plane->norm);
//	printf("(%Lf, %Lf, %Lf) -- (%Lf, %Lf, %Lf)\n", norm.x, norm.y, norm.z, new_plane->norm.x, new_plane->norm.y, new_plane->norm.z);
	new_plane->color = color;
	new_plane->reflection = ref;
	new_object->data = new_plane;
	new_object->get_color = get_plane_color;
	new_object->intersection = plane_intersection;
	return (new_object);
}