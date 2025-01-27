/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:35:35 by ssheba            #+#    #+#             */
/*   Updated: 2019/09/09 18:01:03 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#define THREADS	WIN_Y

static void	thread_obj(t_f_t *all, t_point *pos)
{
	t_vec3		fpos[3];
	size_t		i;
	t_real		t;

	i = 0;
	while (i < all->win->obj_size)
	{
		if (all->win->mas[i]->intersection(all->win->mas[i]->data, \
		&all->ray, fpos + 0, &t) == 1)
		{
			v3_sub(&all->win->view->o, fpos + 0, fpos + 1);
			v3_sub(&all->win->view->o, &all->pos, fpos + 2);
			if ((all->pos.z == (int)1e9) || v3_len(fpos + 1) < v3_len(fpos + 2))
			{
				all->pos = fpos[0];
				pos->color = \
				all->win->mas[i]->get_color(all->win->mas[i]->data, \
				&all->pos, all->win, i);
			}
		}
		else if (i == 0)
			pos->color = all->win->mas[i]->get_color(all->win->mas[i]->data, \
			NULL, all->win, i);
		i++;
	}
}

static void	*thread_func(void *f_all)
{
	t_f_t		*all;
	t_point		pos;

	all = (t_f_t *)f_all;
	pos.y = all->line;
	pos.x = 0;
	while (pos.x < WIN_X)
	{
		all->ray.finish = VEC(pos.x - WIN_X * 0.5 + all->win->view->o.x, \
		pos.y - WIN_Y * 0.5 + all->win->view->o.y, WIN_X + all->win->view->o.z);
		m3v3_mul(&all->win->view->inv_axis, &all->ray.finish, &all->ray.finish);
		all->pos.z = (int)1e9;
		thread_obj(all, &pos);
		set_pixel(all->win, &pos);
		pos.x++;
	}
	pthread_exit(NULL);
}

void		trace(t_sdl *win)
{
	int			y;
	t_ray		ray;
	pthread_t	thread[THREADS];
	t_f_t		*for_thread;
	int			res;

	errno = 0;
	if (!(for_thread = (t_f_t *)malloc(sizeof(t_f_t) * THREADS)))
		msg_finish(MEM_MSG, NULL, errno);
	m3v3_mul(&win->view->inv_axis, &win->view->o, &ray.start);
	ray.finish = VEC(0, 0, 0);
	y = 0;
	while (y < THREADS)
	{
		for_thread[y] = (t_f_t){win, ray, {0, 0, 0}, y, 0};
		if ((res = pthread_create(&thread[y], NULL, thread_func, \
		for_thread + y)))
			msg_finish(PTH_MSG, NULL, errno);
		y++;
	}
	y = 0;
	while (y < THREADS)
		pthread_join(thread[y++], NULL);
	free(for_thread);
}
