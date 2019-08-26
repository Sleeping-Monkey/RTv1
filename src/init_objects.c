/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:57:37 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/26 20:36:56 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"
#include "reading.h"

int	init_objects(t_sdl *win, char **file_name, int size)
{
	int	i;

	i = 0;
	if (!(win->mas = (t_object **)malloc(sizeof(t_object *) * size)))
		return (0);
	while (i < size)
	{
		if (!(win->mas[i] = read_objinfo(file_name[i])))
			return (0);
		i++;
	}
	win->obj_size = (size_t)size;
	return (1);
}