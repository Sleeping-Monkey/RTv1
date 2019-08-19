/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:57:37 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/19 17:38:04 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"
#include "reading.h"

int	init_objects(t_sdl *win, char *file_name)
{
	if (!(win->mas[0] = read_objinfo(file_name)))
		return (0);
	win->obj_size = 1;
	return (1);
}