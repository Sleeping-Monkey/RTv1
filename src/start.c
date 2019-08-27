/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:12:03 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/27 17:01:52 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

/* static void	init_param(t_sdl *win, char **av, int ac)
{
	int	i;
	int	j;

	if (ac < 6 || av[0][0] != '-' || av[0][1] != 'p' || av[0][2] != '\0' || \
	av[2][0] != '-' || av[2][1] != 'l' || av[2][2] != '\0')
		msg_finish(USG_MSG);
	if (av[1][0] == '!' && av[1][1] == '\0')
		win->view = create_person(VEC(WIN_X * 0.5, WIN_Y * 0.5, -WIN_X), \
		VEC(WIN_X * 0.5 + 1, WIN_Y * 0.5, -WIN_X), \
		VEC(WIN_X * 0.5, WIN_Y * 0.5 + 1, -WIN_X));
	i = 3;
	while (i < ac && av[i][0] != '-')
		i++;
	if (i == ac)
		msg_finish(USG_MSG);
	win->lamp_size = i - 3;
	if (!(win->lamp = (t_shine *)malloc(sizeof(t_shine) * (win->lamp_size))))
		msg_finish(MEM_MSG);
	j = -1;
	i = 3;
	while (++j < win->lamp_size)
		win->lamp[j] = get_lamp(av[i++]); // как-то так пока-что...
	if (av[i][1] != 'o' || av[i][2] != '\0')
		msg_finish(USG_MSG);
	win->obj_size = ac - ++i;
	init_objects(win, av + i, win->obj_size);
}
*/

void	start(char **file_name, int size)
{
	t_sdl	win;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		msg_finish(SDL_MSG);
	win.win = SDL_CreateWindow("RTv1", 100, 100, WIN_X, WIN_Y, SDL_WINDOW_SHOWN);
	if (win.win == NULL)
		msg_finish(SDL_MSG);
	if (!(init_objects(&win, file_name, size)))
		finish(&win);
	win.img.img = SDL_GetWindowSurface(win.win);
	SDL_FillRect(win.img.img, NULL, SDL_MapRGBA(win.img.img->format, 0x00, 0xFF, 0x00, 0x00));
	SDL_UpdateWindowSurface(win.win);
	win.img.pixels = (unsigned char *)win.img.img->pixels;
	init_shine(&win, 10);
	win.view = create_person(VEC(WIN_X * 0.5, WIN_Y * 0.5, -WIN_X), VEC(WIN_X * 0.5 + 1, WIN_Y * 0.5, -WIN_X), \
	VEC(WIN_X * 0.5, WIN_Y * 0.5 + 1, -WIN_X));
	trace(&win);
	SDL_UpdateWindowSurface(win.win);
	event(&win);
//	win.img.pixels = (unsigned char *)win.img.img->pi
}
