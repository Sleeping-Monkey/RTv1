/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:12:03 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/19 17:30:02 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

void	start(char *file_name)
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
	if (!(init_objects(&win, file_name)))
		finish(&win);
	win.img.img = SDL_GetWindowSurface(win.win);
	SDL_FillRect(win.img.img, NULL, SDL_MapRGBA(win.img.img->format, 0x00, 0xFF, 0x00, 0x00));
	SDL_UpdateWindowSurface(win.win);
	win.img.pixels = (unsigned char *)win.img.img->pixels;
	init_shine(&win, 10);
	win.view = create_person(VEC(WIN_X * 0.5, WIN_Y * 0.5, -WIN_X), VEC(WIN_X * 0.5 + 1, WIN_Y * 0.5, -WIN_X), \
	VEC(WIN_X * 0.5, WIN_Y * 0.5 + 1, -WIN_X));
	printf("start init is ok\n");
	event(&win);
//	win.img.pixels = (unsigned char *)win.img.img->pi
}
