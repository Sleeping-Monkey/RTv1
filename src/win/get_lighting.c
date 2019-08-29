/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lighting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 09:13:07 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:33:16 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static int		check_shadow(t_sdl *win, t_ray *ray, size_t id)
{
	size_t		i;
	t_vec3		pos;
	t_real		t;

	i = 0;
	while (i < win->obj_size)
	{
		if (i != id && \
		win->mas[i]->intersection(win->mas[i]->data, ray, &pos, &t) == 1 \
		&& (t < 1))
			return (1);
		i++;
	}
	return (0);
}

static t_real	calc(t_sdl *win, t_vec3 *pnv, int power, size_t i)
{
	t_real	res;
	t_real	dot;
	t_vec3	l[2];

	res = 0;
	v3_sub(&win->lamp[i]->pos, pnv + 0, l + 0);
	if ((dot = v3_dot(pnv + 1, pnv + 2)) > 0)
		res += win->lamp[i]->bright * dot / (v3_len(pnv + 1) * v3_len(pnv + 2));
	if (power != -1)
	{
		v3_sub(v3s_mull(pnv + 1, 2 * v3_dot(pnv + 1, l + 0), l + 1), \
		l + 0, l + 1);
		if ((dot = v3_dot(l + 1, pnv + 2)) > 0)
			res += win->lamp[i]->bright * pow(dot / (v3_len(l + 1) \
			* v3_len(pnv + 2)), power);
	}
	return (res);
}

t_real			get_lighting(t_sdl *win, t_vec3 *pnv, int power, size_t id)
{
	size_t		i;
	t_real		res;
	t_ray		ray;

	i = (size_t)-1;
	res = 0;
	ray.start = pnv[0];
	while (++i < win->lamp_size)
		if (win->lamp[i]->type == AMBIENT)
			res += win->lamp[i]->bright;
		else
		{
			ray.finish = win->lamp[i]->pos;
			if (!check_shadow(win, &ray, id))
				res += calc(win, pnv, power, i);
		}
	return (res > 1 ? 1 : res);
}
