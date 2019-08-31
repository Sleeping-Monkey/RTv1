/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:12:03 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/31 09:45:52 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "reading.h"

static void	norm_lamp(t_sdl *win)
{
	t_real	sum;
	size_t	i;

	sum = 0;
	i = 0;
	win->amb_flag = 0;
	while (i < win->lamp_size)
	{
		if (win->lamp[i]->type == AMBIENT)
			win->amb_flag = 1;
		sum += win->lamp[i++]->bright;
	}
	i = 0;
	while (i < win->lamp_size)
		win->lamp[i++]->bright /= sum;
}

static void	init_param(t_sdl *win, char **av, int ac)
{
	int		i;
	size_t	j;

	errno = 0;
	if (ac < 6 || av[0][0] != '-' || av[0][1] != 'p' || av[0][2] != '\0' || \
	av[2][0] != '-' || av[2][1] != 'l' || av[2][2] != '\0')
		msg_finish(USG_MSG, NULL, 0);
	win->view = read_personinfo(get_fd(av[1]));
	printf("person is ok\n");
	i = 3;
	while (i < ac && av[i][0] != '-')
		i++;
	if (i == ac)
		msg_finish(USG_MSG, NULL, 0);
	win->lamp_size = i - 3;
	if (!(win->lamp = (t_shine **)malloc(sizeof(t_shine *) * (win->lamp_size))))
		msg_finish(MEM_MSG, NULL, errno);
	j = (size_t)-1;
	i = 3;
	while (++j < win->lamp_size)
		win->lamp[j] = read_shineinfo(get_fd(av[i++]));
	norm_lamp(win);
	printf("shine is ok\n");
	if (av[i][1] != 'o' || av[i][2] != '\0')
		msg_finish(USG_MSG, NULL, 0);
	win->obj_size = ac - ++i;
	init_objects(win, av + i, win->obj_size);
}

void		start(char **file_name, int size)
{
	t_sdl	win;

	errno = 0;
	init_param(&win, file_name, size);
	printf("after init\n");
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		msg_finish(SDL_MSG, NULL, errno);
	win.win = SDL_CreateWindow("RTv1", 100, 100, WIN_X, WIN_Y, \
	SDL_WINDOW_SHOWN);
	if (win.win == NULL)
		msg_finish(SDL_MSG, NULL, errno);
	win.img.img = SDL_GetWindowSurface(win.win);
	SDL_FillRect(win.img.img, NULL, \
	SDL_MapRGBA(win.img.img->format, 0x00, 0xFF, 0x00, 0x00));
	SDL_UpdateWindowSurface(win.win);
	win.img.pixels = (unsigned char *)win.img.img->pixels;
	printf("Prefer trace\n");
	trace(&win);
	SDL_UpdateWindowSurface(win.win);
	event(&win);
}
