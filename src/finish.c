/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:17:29 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/27 16:46:59 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

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
}

void		finish(t_sdl *win)
{
	free_objects(win);
	free(win->lamp);
	free(win->view);
	SDL_FreeSurface(win->img.img);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
	exit(0);
}

void		msg_finish(char *msg)
{
	ft_putendl_fd(2, msg);
	exit(1);
}