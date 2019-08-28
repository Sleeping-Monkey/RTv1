/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:47:52 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/28 17:44:43 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat.h"

t_mat3			*m3_copy(t_mat3 *m, t_mat3 *out)
{
	if (!m || !out)
		return (NULL);
	ft_memmove(out, m, sizeof(t_mat3));
	return (out);
}

static void		coefficient(t_mat3 *m, t_mat3 *out)
{
	out->r[0][0] = m->r[1][1] * m->r[2][2] - m->r[2][1] * m->r[1][2];
	out->r[1][0] = -1 * (m->r[1][0] * m->r[2][2] - m->r[1][2] * m->r[2][0]);
	out->r[2][0] = m->r[1][0] * m->r[2][1] - m->r[1][1] * m->r[2][0];
	out->r[0][1] = -1 * (m->r[0][1] * m->r[2][2] - m->r[2][1] * m->r[0][2]);
	out->r[1][1] = m->r[0][0] * m->r[2][2] - m->r[0][2] * m->r[2][0];
	out->r[2][1] = -1 * (m->r[0][0] * m->r[2][1] - m->r[0][1] * m->r[2][0]);
	out->r[0][2] = m->r[0][1] * m->r[1][2] - m->r[1][1] * m->r[0][2];
	out->r[1][2] = -1 * (m->r[0][0] * m->r[1][2] - m->r[0][2] * m->r[1][0]);
	out->r[2][2] = m->r[0][0] * m->r[1][1] - m->r[0][1] * m->r[1][0];
}

t_mat3			*m3_inv(t_mat3 *m, t_mat3 *out)
{
	t_real d;

	if (!m || !out)
		return (NULL);
	d = m3_det(m);
	coefficient(m, out);
	if (d == 0)
		return (NULL);
	d = 1 / d;
	m3r_mul(out, d, out);
	return (out);
}

t_real			m3_det(t_mat3 *m)
{
	return (m->r[0][0] * m->r[1][1] * m->r[2][2] \
	+ m->r[0][1] * m->r[1][2] * m->r[2][0] \
	+ m->r[0][2] * m->r[1][0] * m->r[2][1] \
	- m->r[0][0] * m->r[1][2] * m->r[2][1] \
	- m->r[0][1] * m->r[1][0] * m->r[2][2] \
	- m->r[0][2] * m->r[1][1] * m->r[2][0]);
}

void			m3_zero(t_mat3 *m)
{
	int	i;
	int	j;

	i = 3;
	while (i--)
	{
		j = 3;
		while (j--)
			m->r[i][j] = 0;
	}
}
