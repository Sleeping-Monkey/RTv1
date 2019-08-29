/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:09:11 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:08:12 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void	set_pixel(t_sdl *win, t_point *pos)
{
	win->img.pixels[4 * (pos->y * win->img.img->w + pos->x) + 0] = pos->color.b;
	win->img.pixels[4 * (pos->y * win->img.img->w + pos->x) + 1] = pos->color.g;
	win->img.pixels[4 * (pos->y * win->img.img->w + pos->x) + 2] = pos->color.r;
	win->img.pixels[4 * (pos->y * win->img.img->w + pos->x) + 3] = pos->color.a;
}
