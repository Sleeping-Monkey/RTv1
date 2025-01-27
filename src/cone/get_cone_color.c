/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:58:30 by ssheba            #+#    #+#             */
/*   Updated: 2019/09/05 16:35:34 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static void	get_normal(t_cone *cone, t_vec3 *pos, t_vec3 *norm)
{
	t_mat3	m[4];
	t_vec3	oz;
	t_vec3	tmp;
	t_real	len;

	if (pos->x == cone->o.x && pos->y == cone->o.y && pos->z == cone->o.z)
	{
		*norm = VEC(0, 0, 0);
		return ;
	}
	v3_sub(pos, &cone->o, norm);
	len = v3_len(norm);
	m3_rotz(m + 0, norm->x / len, norm->y / len);
	oz = VEC(0, 0, norm->z > 0 ? 1 : -1);
	v3_cross(&oz, norm, &tmp);
	v3s_mull(&tmp, 1.0 / len, &tmp);
	m3_rotx(m + 1, v3_dot(&oz, norm) / len, oz.z * v3_len(&tmp));
	m3_trs(m + 0, m + 2);
	m3_mul(m + 0, m + 1, m + 3);
	m3_mul(m + 3, m + 2, m + 3);
	norm->z = 0;
	v3_norm(norm, norm);
	m3v3_mul(m + 3, norm, norm);
}

t_color		get_cone_color(void *data, t_vec3 *pos, t_sdl *win, size_t id)
{
	t_cone		*cone;
	t_vec3		pnv[3];
	t_real		i;

	cone = (t_cone *)data;
	if (pos)
	{
		pnv[0] = *pos;
		m3v3_mul(&cone->axis, pos, pos);
		get_normal(cone, pos, pnv + 1);
		m3v3_mul(&cone->inv_axis, pos, pos);
		m3v3_mul(&cone->inv_axis, pnv + 1, pnv + 1);
		v3_sub(&win->view->o, pos, pnv + 2);
		i = get_lighting(win, pnv, cone->reflection, id);
		return (COLOR(i * cone->color.r, i * cone->color.g, \
		i * cone->color.b, cone->color.a));
	}
	if (win->amb_flag)
		return (COLOR(255, 255, 255, 0));
	return (COLOR(0, 0, 0, 0));
}
