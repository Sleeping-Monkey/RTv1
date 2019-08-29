/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:17:29 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 16:08:36 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

static void	free_objects(t_sdl *win)
{
	size_t	i;

	i = 0;
	while (i < win->obj_size)
	{
		free(win->mas[i]->data);
		free(win->mas[i]);
		i++;
	}
	free(win->mas);
	i = 0;
	while (i < win->lamp_size)
	{
		free(win->lamp[i]);
		i++;
	}
	free(win->lamp);
}

void		finish(t_sdl *win)
{
	free_objects(win);
	free(win->view);
	SDL_FreeSurface(win->img.img);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
	exit(0);
}

void		msg_finish(char *msg, char *filename, int flag)
{
	if (flag)
		perror(strerror(errno));
	else
	{
		ft_putendl_fd(msg, 2);
		if (filename)
			ft_putendl_fd(filename, 2);
	}
	exit(1);
}