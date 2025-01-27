/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:06:50 by ssheba            #+#    #+#             */
/*   Updated: 2019/09/05 16:16:14 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat.h"

void	m3_rotx(t_mat3 *m, t_real cos_a, t_real sin_a)
{
	m->r[0][0] = 1;
	m->r[0][1] = 0;
	m->r[0][2] = 0;
	m->r[1][0] = 0;
	m->r[1][1] = cos_a;
	m->r[1][2] = -sin_a;
	m->r[2][0] = 0;
	m->r[2][1] = sin_a;
	m->r[2][2] = cos_a;
}

void	m3_roty(t_mat3 *m, t_real cos_a, t_real sin_a)
{
	m->r[0][0] = cos_a;
	m->r[0][1] = 0;
	m->r[0][2] = sin_a;
	m->r[1][0] = 0;
	m->r[1][1] = 1;
	m->r[1][2] = 0;
	m->r[2][0] = -sin_a;
	m->r[2][1] = 0;
	m->r[2][2] = cos_a;
}

void	m3_rotz(t_mat3 *m, t_real cos_a, t_real sin_a)
{
	m->r[0][0] = cos_a;
	m->r[0][1] = -sin_a;
	m->r[0][2] = 0;
	m->r[1][0] = sin_a;
	m->r[1][1] = cos_a;
	m->r[1][2] = 0;
	m->r[2][0] = 0;
	m->r[2][1] = 0;
	m->r[2][2] = 1;
}

t_mat3	*m3_trs(t_mat3 *m, t_mat3 *out)
{
	t_mat3	m_copy;
	int		i;
	int		j;

	if (!m || !out)
		return (NULL);
	m == out ? m = m3_copy(m, &m_copy) : 0;
	i = 3;
	while (i--)
	{
		j = 3;
		while (j--)
			out->r[j][i] = m->r[i][j];
	}
	return (out);
}
