/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:35:35 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/08 10:08:13 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"
#define THREADS	WIN_Y

void	*thread_func(void *f_all)
{
	t_f_t		*all;
	t_point		pos;
	t_vec3		fpos[3];
	size_t		i;
	t_real		t;
//	static int	thr = 0;

	all = (t_f_t *)f_all;
	pos.y = all->line;
	//printf("start %d thread\n", thr++);
	pos.x = 0;
	while (pos.x < WIN_X)
	{ 
		//printf("(%d, %d):\n", pos.x, pos.y);
		all->ray.finish = VEC(pos.x - WIN_X * 0.5 + all->win->view->o.x, pos.y - WIN_Y * 0.5 + all->win->view->o.y, WIN_X + all->win->view->o.z);
		m3v3_mul(&all->win->view->inv_axis, &all->ray.finish, &all->ray.finish);
		i = 0;
		all->pos.z = (int)1e9;
		while (i < all->win->obj_size)
		{
			if (all->win->mas[i]->intersection(all->win->mas[i]->data, &all->ray, fpos + 0, &t) == 1)
			{
			//	printf("%zu: (%d, %d) -- (%Lf, %Lf, %Lf)\n", i, pos.x, pos.y, fpos[0].x, fpos[0].y, fpos[0].z);
				v3_sub(&all->win->view->o, fpos + 0, fpos + 1);
				v3_sub(&all->win->view->o, &all->pos, fpos + 2);
				if ((all->pos.z == (int)1e9) || v3_len(fpos + 1) < v3_len(fpos + 2))
				{
					all->pos = fpos[0];
					pos.color = all->win->mas[i]->get_color(all->win->mas[i]->data, &all->pos, all->win, i);
				}
			}
			else if (i == 0)
			{
			//	printf("%zu: (%d, %d) -- %Lf\n", i, pos.x, pos.y, t);
				pos.color = all->win->mas[i]->get_color(all->win->mas[i]->data, NULL, all->win, i);
			}
			i++;
		}
		set_pixel(all->win, &pos);
		pos.x++;
	}
	pthread_exit(NULL);
}

void	trace(t_sdl *win)
{
	int			y;
	t_ray		ray;
	pthread_t	thread[THREADS];
	t_f_t		*for_thread;
	int			res;

	if (!(for_thread = (t_f_t *)malloc(sizeof(t_f_t) * THREADS)))
		return ;
	ray.start = win->view->o;
	ray.finish = VEC(0, 0, 0);
	y = 0;
	while (y < THREADS)
	{
		for_thread[y] = (t_f_t){win, ray, {0, 0, 0}, y, 0};
		res = pthread_create(&thread[y], NULL, thread_func, for_thread + y);
		if (res)
			printf("Thread %d is not start\n", y);
	//	else
	//		printf("Thread %d start\n", y);
		y++;
	}
	y = 0;
	while (y < THREADS)
	{
		pthread_join(thread[y++], NULL);
	//	printf("thread %d finish\n", y);
	}
	//pthread_exit(NULL);
}