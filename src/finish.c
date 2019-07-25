/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:17:29 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/23 16:27:32 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

void	finish(t_sdl *win)
{
	SDL_FreeSurface(win->img.img);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
	exit(0);
}