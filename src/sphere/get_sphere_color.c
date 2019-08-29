/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:05:26 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 17:10:38 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_color	get_sphere_color(void *data, t_vec3 *pos, t_sdl *win, size_t id)
{
	t_sphere	*sphere;
	t_vec3		pnv[3];
	t_real		i;

	sphere = (t_sphere *)data;
	if (pos)
	{
		v3_copy(pos, pnv + 0);
		v3_sub(&win->view->o, pos, pnv + 2);
		v3_norm(v3_sub(m3v3_mul(&sphere->axis, pos, pos), \
		&sphere->o, pnv + 1), pnv + 1);
		m3v3_mul(&sphere->inv_axis, pnv + 1, pnv + 1);
		i = get_lighting(win, pnv, sphere->reflection, id);
		return (COLOR(i * sphere->color.r, i * sphere->color.g, \
		i * sphere->color.b, sphere->color.a));
	}
	if (win->amb_flag)
		return (COLOR(255, 255, 255, 0));
	return (COLOR(0, 0, 0, 0));
}
