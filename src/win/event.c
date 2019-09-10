/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:19:32 by ssheba            #+#    #+#             */
/*   Updated: 2019/09/09 17:56:27 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#define TRANSLATION 40

void	event(t_sdl *win)
{
	while (1)
		if (SDL_WaitEvent(&win->e) != 0)
		{
			if (win->e.type == SDL_QUIT || (win->e.type == SDL_KEYDOWN
			&& win->e.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				finish(win);
			if (win->e.type == SDL_KEYUP && \
			win->e.key.keysym.sym == SDLK_RETURN)
			{
				win->view->o.z = 0;
				trace(win);
				SDL_UpdateWindowSurface(win->win);
			}
			if (win->e.type == SDL_MOUSEWHEEL)
			{
				m3v3_mul(&win->view->axis, &win->view->o, &win->view->o);
				if (win->e.wheel.y > 0)
					win->view->o.z += TRANSLATION;
				else if (win->e.wheel.y < 0)
					win->view->o.z -= TRANSLATION;
				m3v3_mul(&win->view->inv_axis, &win->view->o, &win->view->o);
				trace(win);
				SDL_UpdateWindowSurface(win->win);
			}
		}
}
