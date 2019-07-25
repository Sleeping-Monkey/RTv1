/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:35:35 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/25 16:32:08 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

void	trace(t_sdl *win)
{
	t_point		pos;
	t_ray		ray;
	t_vector	inter;

	ray.start = VECTOR(WIN_X / 2, WIN_Y / 2, -100);
	pos.y = 0;
	while (pos.y < WIN_Y)
	{
		pos.x = 0;
		while (pos.x < WIN_X)
		{
			printf("(%d, %d):\n", pos.x, pos.y);
			ray.finish = VECTOR(pos.x, pos.y, 0);
			if ((win->mas[0]->intersection(win->mas[0]->data, &ray, &inter)))
				pos.color = win->mas[0]->get_color(win->mas[0]->data, &inter);
			else
			{
				printf("\t\tnot sphere\n");
				pos.color = win->mas[0]->get_color(win->mas[0]->data, NULL);
			}
			printf("\tgo set_pixel\n");
			set_pixel(win, &pos);
			printf("\t set_pixel is ok\n");
			pos.x++;
			printf("\n");
		}
		pos.y++;
	}
}