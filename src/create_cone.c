/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:47:11 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/13 16:04:44 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static void	init_axis(t_cone *cone, t_vec3 *o, t_vec3 *k)
{
	t_vec3	i;
	t_vec3	j;

(void)o;
	if (k->z * k->z != 1)
			i = VEC((k->x * k->x * k->z + k->y * k->y) / (k->z * k->z - 1), (k->x * k->y * k->z + k->y * k->x) / (k->z * k->z - 1), k->x);
	else
		i = VEC(1, 0, 0);
	v3_norm(&i, &i);
	v3_cross(k, &i, &j);
	cone->axis.r[0][0] = i.x;
	cone->axis.r[1][0] = i.y;
	cone->axis.r[2][0] = i.z;
	cone->axis.r[0][1] = j.x;
	cone->axis.r[1][1] = j.y;
	cone->axis.r[2][1] = j.z;
	cone->axis.r[0][2] = k->x;
	cone->axis.r[1][2] = k->y;
	cone->axis.r[2][2] = k->z;
	printf("[%Lf, %Lf, %Lf]\n", cone->axis.r[0][0], cone->axis.r[0][1], cone->axis.r[0][2]);
	printf("[%Lf, %Lf, %Lf]\n", cone->axis.r[1][0], cone->axis.r[1][1], cone->axis.r[1][2]);
	printf("[%Lf, %Lf, %Lf]\n\n", cone->axis.r[2][0], cone->axis.r[2][1], cone->axis.r[2][2]);
}

t_object	*create_cone(t_vec3 start, t_vec3 way, t_real r, t_color color, int ref)
{
	t_cone	*new_cone;
	t_object	*new_object;

	if (!(new_cone = (t_cone *)malloc(sizeof(t_cone))))
		return (NULL);
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
	{
		free(new_cone);
		return (NULL);
	}
	v3_norm(&way, &way);
	init_axis(new_cone, &start, &way);
	m3_inv(&new_cone->axis, &new_cone->inv_axis);
//	printf("[%Lf, %Lf, %Lf]\n", new_cylinder->inv_axis.r[0][0], new_cylinder->inv_axis.r[0][1], new_cylinder->inv_axis.r[0][2]);
//	printf("[%Lf, %Lf, %Lf]\n", new_cylinder->inv_axis.r[1][0], new_cylinder->inv_axis.r[1][1], new_cylinder->inv_axis.r[1][2]);
//	printf("[%Lf, %Lf, %Lf]\n\n", new_cylinder->inv_axis.r[2][0], new_cylinder->inv_axis.r[2][1], new_cylinder->inv_axis.r[2][2]);
	m3v3_mul(&new_cone->axis, &start, &new_cone->o);
	new_cone->radius = r;
	new_cone->color = color;
	new_cone->reflection = ref;
	new_object->data = new_cone;
	new_object->get_color = get_cone_color;
	new_object->intersection = cone_intersection;
	return (new_object);
}