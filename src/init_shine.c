/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 09:57:51 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/09 09:42:00 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"
#include "geometry.h"

void	init_shine(t_sdl *win, int count)
{
	size_t		i;
	t_vec3	pos;

	if (count >= 0)
	{
		win->lamp[0] = (t_shine){AMBIENT, {0, 0, 0}, 1.0L / (count + 1)};
		win->lamp_size = count + 1;
		i = 1;
	}
	else
	{
		win->lamp_size = -count;
		i = 0;
	}
	//printf("%zu - %zu \n", i, win->lamp_size);
	srandom(time(NULL));
	while (i < win->lamp_size)
	{
		pos = VEC(WIN_X * 0.5, WIN_Y * 0.5, 0);
		win->lamp[i] = (t_shine){POINT, pos, 1.0L / (win->lamp_size)};
		i++;
	//	printf("%zu - %zu is ok\n", i, win->lamp_size);
	}
}