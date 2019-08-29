/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:57:37 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:13:25 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

int	init_objects(t_sdl *win, char **file_name, int size)
{
	int	i;

	i = 0;
	errno = 0;
	if (!(win->mas = (t_object **)malloc(sizeof(t_object *) * size)))
		msg_finish(MEM_MSG, NULL, errno);
	while (i < size)
	{
		win->mas[i] = read_objinfo(get_fd(file_name[i]));
		i++;
	}
	win->obj_size = (size_t)size;
	return (1);
}
