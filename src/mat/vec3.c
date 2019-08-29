/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:47:26 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/07 13:01:42 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat.h"

t_vec3	*v3_add(t_vec3 *a, t_vec3 *b, t_vec3 *out)
{
	if (!a || !b || !out)
		return (NULL);
	out->x = a->x + b->x;
	out->y = a->y + b->y;
	out->z = a->z + b->z;
	return (out);
}

t_vec3	*v3_sub(t_vec3 *a, t_vec3 *b, t_vec3 *out)
{
	if (!a || !b || !out)
		return (NULL);
	out->x = a->x - b->x;
	out->y = a->y - b->y;
	out->z = a->z - b->z;
	return (out);
}

t_vec3	*v3s_mull(t_vec3 *v, t_real s, t_vec3 *out)
{
	if (!v || !out)
		return (NULL);
	out->x = v->x * s;
	out->y = v->y * s;
	out->z = v->z * s;
	return (out);
}

t_vec3	*v3s_add(t_vec3 *v, t_real s, t_vec3 *out)
{
	if (!v || !out)
		return (NULL);
	out->x = v->x + s;
	out->y = v->y + s;
	out->z = v->z + s;
	return (out);
}

t_vec3	*v3_copy(t_vec3 *v, t_vec3 *out)
{
	if (!v || !out)
		return (NULL);
	ft_memmove(out, v, sizeof(t_vec3));
	return (out);
}
