/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:19:32 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/21 18:00:39 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"
#define TRANSLATION 100

void	event(t_sdl *win)
{
	while (1)
	{
		if(SDL_WaitEvent(&win->e) != 0)
		{
		//	printf("OK: type == %d ;  %d - %d\n", win->e.type, win->e.key.type, win->e.key.keysym.sym);
			if (win->e.type == SDL_QUIT)
				finish(win);
			if (win->e.type == SDL_KEYUP)
			{
			//	t_mat3	rot;

				if (win->e.key.keysym.sym == SDLK_RETURN)
				{
					win->view->o.z = 0;
					trace(win);
					SDL_UpdateWindowSurface(win->win);
				}
			//	if (win->e.key.keysym.sym == SDLK_w)
			//	{
			//		
			//	}
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
				printf("OK \n");
			}
		}
	//	SDL_RenderCopy(ren, img, NULL, NULL);
	//	SDL_RenderPresent(ren);
	}
}