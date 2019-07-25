/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:19:32 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/25 16:39:36 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

void	event(t_sdl *win)
{
	while (1)
	{
		while(SDL_PollEvent(&win->e))
		{
			printf("OK: type == %d ;  %d - %d\n", win->e.type, win->e.key.type, win->e.key.keysym.sym);
			if (win->e.type == SDL_QUIT)
				finish(win);
			if (win->e.type == SDL_KEYUP)
			{
				trace(win);
				SDL_UpdateWindowSurface(win->win);
		//		printf("OK: %d\n", win->e.key);
			}
		}
	//	SDL_RenderCopy(ren, img, NULL, NULL);
	//	SDL_RenderPresent(ren);
	}
}