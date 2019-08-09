/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:54:54 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/07 13:22:01 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_object		*create_sphere(t_vec3 center, t_real r, t_color color, int ref)
{
	t_sphere	*new_sphere;
	t_object	*new_object;

	if (!(new_sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
	{
		free(new_sphere);
		return (NULL);
	}
	m3_zero(&new_sphere->axis);
	new_sphere->axis.r[0][0] = 1;
	new_sphere->axis.r[1][1] = 1;
	new_sphere->axis.r[2][2] = 1;
	m3_inv(&new_sphere->axis, &new_sphere->inv_axis);
	new_sphere->center = center;
	new_sphere->radius = r;
	new_sphere->color = color;
	new_sphere->reflection = ref;
	new_object->data = new_sphere;
	new_object->get_color = get_sphere_color;
	new_object->intersection = sphere_intersection;
	return (new_object);
}