/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:11:54 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 16:12:09 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

int	get_fd(char *filename)
{
	int	fd;

	errno = 0;
	if (filename != NULL && *filename != 0)
	{
		if ((fd = open(filename, O_RDONLY)) < 0)
			msg_finish(NO_FILE_MSG, filename, errno);
		return (fd);
	}
	return (-1);
}
