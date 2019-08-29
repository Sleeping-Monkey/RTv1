/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lighting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 09:13:07 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/27 18:07:44 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

int		check_shadow(t_sdl *win, t_ray *ray, size_t id)
{
	size_t		i;
	t_vec3		pos;
	t_real		t;

	i = 0;
	while (i < win->obj_size)
	{
		if (i != id && win->mas[i]->intersection(win->mas[i]->data, ray, &pos, &t) == 1 && (t < 1))
			return (1);
		i++;
	}
	return (0);
}

t_real	get_lighting(t_sdl *win, t_vec3 *pnv, int power, size_t id)
{
	size_t		i;
	t_real		res;
	t_vec3		l[2];
	t_real		dot;
	t_ray		ray;

	i = 0;
	res = 0;
	ray.start = pnv[0];
	while (i < win->lamp_size)
	{
		if (win->lamp[i]->type == AMBIENT)
			res += win->lamp[i]->bright;
		else
		{
			ray.finish = win->lamp[i]->pos;
			if (!check_shadow(win, &ray, id))
			{
				v3_sub(&win->lamp[i]->pos, pnv + 0, l + 0);
				dot = v3_dot(pnv + 1, pnv + 2);
				if (dot > 0)
					res += win->lamp[i]->bright * dot / (v3_len(pnv + 1) * v3_len(pnv + 2));
				if (power != -1)
				{
					v3s_mull(pnv + 1, 2 * v3_dot(pnv + 1, l + 0), l + 1);
					v3_sub(l + 1, l + 0, l + 1);
					dot = v3_dot(l + 1, pnv + 2);
					if (dot > 0)
						res += win->lamp[i]->bright * pow(dot / (v3_len(l + 1) * v3_len(pnv + 2)), power);
				}
			}
		}
		i++;
	}
	return (res > 1 ? 1 : res);
}