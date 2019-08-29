/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:53:54 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 16:19:02 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static void	get_ijk(t_vec3 *i, t_vec3 *j, t_vec3 *k)
{
	if ((k->x != 0 && k->z != 0) || k->y * k->y == 1 || k->z * k->z == 1)
	{
		if (k->y * k->y == 1 || k->z * k->z == 1)
			*j = VEC(0, k->z, k->y);
		else if (k->y == 0)
			*j = VEC(0, -1, 0);
		else
			*j = VEC(k->x / (1 + k->z), (k->y - k->z - 1) / (1 + k->z), k->y);
		v3_cross(j, k, i);
	}
	else
	{
		if (k->x * k->x == 1)
			*i = VEC(0, 0, k->x);
		else if (k->x == 0)
			*i = VEC(-1, 0, 0);
		else
			*i = VEC(-k->y * k->y, k->x * k->y, k->x);
		v3_cross(k, i, j);
	}
}

static void	init_axis(t_cylinder *cylinder, t_vec3 *k)
{
	t_vec3	i;
	t_vec3	j;

	get_ijk(&i, &j, k);
	cylinder->axis.r[0][0] = i.x;
	cylinder->axis.r[1][0] = i.y;
	cylinder->axis.r[2][0] = i.z;
	cylinder->axis.r[0][1] = j.x;
	cylinder->axis.r[1][1] = j.y;
	cylinder->axis.r[2][1] = j.z;
	cylinder->axis.r[0][2] = k->x;
	cylinder->axis.r[1][2] = k->y;
	cylinder->axis.r[2][2] = k->z;
	printf("[%Lf, %Lf, %Lf]\n", cylinder->axis.r[0][0], cylinder->axis.r[0][1], cylinder->axis.r[0][2]);
	printf("[%Lf, %Lf, %Lf]\n", cylinder->axis.r[1][0], cylinder->axis.r[1][1], cylinder->axis.r[1][2]);
	printf("[%Lf, %Lf, %Lf]\n\n", cylinder->axis.r[2][0], cylinder->axis.r[2][1], cylinder->axis.r[2][2]);
}

t_object	*create_cylinder(t_vec3 start, t_vec3 way, t_real r, t_color color, int ref)
{
	t_cylinder	*new_cylinder;
	t_object	*new_object;

	errno = 0;
	if (!(new_cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		msg_finish(MEM_MSG, NULL, errno);
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
		msg_finish(MEM_MSG, NULL, errno);
	v3_norm(&way, &way);
	init_axis(new_cylinder, &way);
	m3_inv(&new_cylinder->axis, &new_cylinder->inv_axis);
//	printf("[%Lf, %Lf, %Lf]\n", new_cylinder->inv_axis.r[0][0], new_cylinder->inv_axis.r[0][1], new_cylinder->inv_axis.r[0][2]);
//	printf("[%Lf, %Lf, %Lf]\n", new_cylinder->inv_axis.r[1][0], new_cylinder->inv_axis.r[1][1], new_cylinder->inv_axis.r[1][2]);
//	printf("[%Lf, %Lf, %Lf]\n\n", new_cylinder->inv_axis.r[2][0], new_cylinder->inv_axis.r[2][1], new_cylinder->inv_axis.r[2][2]);
	m3v3_mul(&new_cylinder->axis, &start, &new_cylinder->o);
	new_cylinder->radius = r;
	new_cylinder->color = color;
	new_cylinder->reflection = ref;
	new_object->data = new_cylinder;
	new_object->get_color = get_cylinder_color;
	new_object->intersection = cylinder_intersection;
	return (new_object);
}