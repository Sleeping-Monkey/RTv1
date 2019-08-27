/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:50:57 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/27 16:56:43 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SDL_H
# define MY_SDL_H

# include "geometry.h"

# define WIN_X	500
# define WIN_Y	500
# define USG_MSG    "Usage: ./RTv1 file_name.obj"
# define MEM_MSG    "No memory =("
# define SDL_MSG    "It is SDL problem"

void			set_pixel(t_sdl *win, t_point *pos);

void			start(char **file_name, int size);
void			finish(t_sdl *win);
void		    msg_finish(char *msg);

void			event(t_sdl *win);

int				init_objects(t_sdl *win, char **file_name, int size);

void			trace(t_sdl *win);

#endif