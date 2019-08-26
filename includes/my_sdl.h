/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:50:57 by ssheba            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/16 20:23:29 by gquence          ###   ########.fr       */
=======
/*   Updated: 2019/08/22 17:37:17 by ssheba           ###   ########.fr       */
>>>>>>> cf98c15545818802e27ea3cdf04cfcf963801e12
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SDL_H
# define MY_SDL_H

# include "geometry.h"

# define WIN_X	500
# define WIN_Y	500
# define USG_MSG    "Usage: ./RTv1 file_name.obj"

void			set_pixel(t_sdl *win, t_point *pos);

void			start(char **file_name, int size);
void			finish(t_sdl *win);

void			event(t_sdl *win);

int				init_objects(t_sdl *win, char **file_name, int size);

void			trace(t_sdl *win);

#endif