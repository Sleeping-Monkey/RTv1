/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:17:29 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/05 15:40:36 by ssheba           ###   ########.fr       */
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
}

void		finish(t_sdl *win)
{
	free_objects(win);
	SDL_FreeSurface(win->img.img);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
	exit(0);
}