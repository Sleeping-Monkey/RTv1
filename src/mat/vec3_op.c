/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:47:34 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/28 17:44:31 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat.h"

t_vec3	*v3_norm(t_vec3 *v, t_vec3 *out)
{
	t_real mag;

	if (!v || !out)
		return (NULL);
	mag = v3_len(v);
	if (!mag)
		return (NULL);
	out->x = v->x / mag;
	out->y = v->y / mag;
	out->z = v->z / mag;
	return (out);
}

t_real	v3_len(t_vec3 *v)
{
	return (sqrt(
			pow(v->x, 2) +
			pow(v->y, 2) +
			pow(v->z, 2)));
}

t_vec3	*v3_cross(t_vec3 *a, t_vec3 *b, t_vec3 *out)
{
	if (!a || !b || !out)
		return (NULL);
	out->x = a->y * b->z - a->z * b->y;
	out->y = a->z * b->x - a->x * b->z;
	out->z = a->x * b->y - a->y * b->x;
	return (out);
}

t_real	v3_dot(t_vec3 *a, t_vec3 *b)
{
	if (!a || !b)
		return (0);
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
