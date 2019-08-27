/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:09:11 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/27 18:02:32 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "geometry.h"

void			set_pixel(t_sdl *win, t_point *pos)
{
//	SDL_LockSurface(win->img.img);

 	win->img.pixels[4 * (pos->y * win->img.img->w + pos->x) + 0] = pos->color.b; // b
	win->img.pixels[4 * (pos->y * win->img.img->w + pos->x) + 1] = pos->color.g; // g
	win->img.pixels[4 * (pos->y * win->img.img->w + pos->x) + 2] = pos->color.r; // r
	win->img.pixels[4 * (pos->y * win->img.img->w + pos->x) + 3] = pos->color.a; // a

//	SDL_UnlockSurface(win->img.img);
}