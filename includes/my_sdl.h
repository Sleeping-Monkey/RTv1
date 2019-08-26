/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:50:57 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/16 20:23:29 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SDL_H
# define MY_SDL_H

# include "geometry.h"

# define WIN_X	500
# define WIN_Y	500

void			set_pixel(t_sdl *win, t_point *pos);

void			start(void);
void			finish(t_sdl *win);

void			event(t_sdl *win);

int				init_objects(t_sdl *win);

void			trace(t_sdl *win);

#endif