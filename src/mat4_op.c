/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:36:04 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/09 11:08:32 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat.h"

t_mat3			*m3_mul(t_mat3 *a, t_mat3 *b, t_mat3 *out)
{
	int		r;
	int		c;
	int		k;
	t_mat3	a_copy;
	t_mat3	b_copy;

	if ((!a || !b) || !out)
		return (NULL);
	a == out ? a = m3_copy(a, &a_copy) : 0;
	b == out ? b = m3_copy(b, &b_copy) : 0;
	r = 3;
	while (r--)
	{
		c = 3;
		while (c--)
		{
			k = 3;
			out->r[r][c] = 0;
			while (k--)
				if (a->r[r][k])
					out->r[r][c] += a->r[r][k] * b->r[k][c];
		}
	}
	return (out);
}

t_vec3			*m3v3_mul(t_mat3 *a, t_vec3 *b, t_vec3 *out)
{
	t_vec3	b_copy;

	if (!a || !b || !out)
		return (NULL);
	b == out ? b = v3_copy(b, &b_copy) : 0;
	out->x = (b->x * a->r[0][0] + b->y * a->r[0][1] + b->z * a->r[0][2]);
	out->y = (b->x * a->r[1][0] + b->y * a->r[1][1] + b->z * a->r[1][2]);
	out->z = (b->x * a->r[2][0] + b->y * a->r[2][1] + b->z * a->r[2][2]);
	return (out);
}

t_mat3			*m3r_mul(t_mat3 *a, t_real r, t_mat3 *out)
{
	t_mat3	a_copy;
	int		i;
	int		j;

	if (!a || !out)
		return (NULL);
	a == out ? a = m3_copy(a, &a_copy) : 0;
	i = 3;
	while (i--)
	{
		j = 3;
		while (j--)
			out->r[i][j] = a->r[i][j] * r;
	}	
	return (out);
}
