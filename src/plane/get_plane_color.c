/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:57:40 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 17:09:11 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_color	get_plane_color(void *data, t_vec3 *pos, t_sdl *win, size_t id)
{
	t_plane		*plane;
	t_vec3		pnv[3];
	t_real		i;

	plane = (t_plane *)data;
	if (pos)
	{
		pnv[0] = *pos;
		m3v3_mul(&plane->inv_axis, &plane->norm, pnv + 1);
		v3_sub(&win->view->o, pos, pnv + 2);
		i = get_lighting(win, pnv, plane->reflection, id);
		return (COLOR(i * plane->color.r, i * plane->color.g, \
		i * plane->color.b, plane->color.a));
	}
	if (win->lamp_size && win->lamp[0]->type == AMBIENT)
		return (COLOR(255, 255, 255, 0));
	return (COLOR(0, 0, 0, 0));
}
