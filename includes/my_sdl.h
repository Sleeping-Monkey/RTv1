/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:50:57 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/25 16:43:11 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SDL_H
# define MY_SDL_H

# include "SDL.h"
# include "geometry.h"

# define WIN_X 100
# define WIN_Y 100


typedef struct	s_point
{
	unsigned	x;
	unsigned	y;
	t_color		color;
}				t_point;

typedef struct	s_img
{
	SDL_Surface		*img;
	unsigned char	*pixels;
}				t_img;

typedef struct	s_sdl
{
	SDL_Window		*win;
	t_img			img;
	SDL_Event		e;
	t_object		*mas[10];
}				t_sdl;

void			set_pixel(t_sdl *win, t_point *pos);

void			start(void);
void			finish(t_sdl *win);

void			event(t_sdl *win);

int				init_objects(t_sdl *win);

void			trace(t_sdl *win);

#endif