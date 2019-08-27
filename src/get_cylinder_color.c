/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:14:27 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/27 18:08:46 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_color		get_cylinder_color(void *data, t_vec3 *pos, t_sdl *win, size_t id)
{
	t_cylinder	*cylinder;
	t_vec3		pnv[3];
	t_real		i;

	cylinder = (t_cylinder *)data;
	if (pos)
	{
		pnv[0] = *pos;
		m3v3_mul(&cylinder->axis, pos, pnv + 1);
		pnv[1].z = cylinder->o.z;
		v3_sub(pnv + 1, &cylinder->o, pnv + 1);
		//printf("n = (%Lf, %Lf, %Lf)\n", pnv[1].x, pnv[1].y, pnv[1].z);
		m3v3_mul(&cylinder->inv_axis, pnv + 1, pnv + 1);
		v3_sub(&win->view->o, pos, pnv + 2);
		i = get_lighting(win, pnv, cylinder->reflection, id);
		//printf("COLOR: p = (%Lf, %Lf, %Lf), n = (%Lf, %Lf, %Lf), v = (%Lf, %Lf, %Lf), i = %Lf\n", pnv[0].x, pnv[0].y, pnv[0].z, pnv[1].x, pnv[1].y, pnv[1].z, pnv[2].x, pnv[2].y, pnv[2].z, i);
		return (COLOR(i * cylinder->color.r, i * cylinder->color.g, i * cylinder->color.b, cylinder->color.a)); 
	}
	if (win->lamp_size && win->lamp[0]->type == AMBIENT)
		return (COLOR(255, 255, 255, 0));
	return (COLOR(0, 0, 0, 0));
}