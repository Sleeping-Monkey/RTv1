/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:12:03 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/25 16:38:58 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

void	start(void)
{
	t_sdl	win;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Error 0\n");
		return ;
	}   
	win.win = SDL_CreateWindow("RTv1", 100, 100, WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	if (win.win == NULL)
	{
		printf("Error 1\n");
		return ;
	}
	if (!(init_objects(&win)))
		finish(&win);
	win.img.img = SDL_GetWindowSurface(win.win);
	SDL_FillRect(win.img.img, NULL, SDL_MapRGB(win.img.img->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(win.win);
	win.img.pixels = (unsigned char *)win.img.img->pixels;
	event(&win);
//	win.img.pixels = (unsigned char *)win.img.img->pi
}
