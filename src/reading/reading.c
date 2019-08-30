/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:24:01 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/30 17:24:03 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"
#include "libft.h"

int			check_figuretype(char *str)
{
	if (!ft_strcmp(str, "plane"))
		return (1);
	if (!ft_strcmp(str, "sphere"))
		return (2);
	if (!ft_strcmp(str, "cylinder"))
		return (3);
	if (!ft_strcmp(str, "cone"))
		return (4);
	return (0);
}

/*
** template of filling file:
**
**vectors: x y z
**t_color: r g b a
**
**#1
**"plane
**pos: 1.0 2.0 3.0
**norm: 0 0 1
**color: 0-255 0-255 0-255 0-255
**refl: 1-3"
*/

t_object	*get_fig_info(const int figtype, char **splitted)
{
	if (figtype == 1)
		return (get_plane(splitted));
	if (figtype == 2)
		return (get_sphere(splitted));
	if (figtype == 3)
		return (get_cylinder(splitted));
	if (figtype == 4)
		return (get_cone(splitted));
	return (NULL);
}

t_object	*read_objinfo(int fd)
{
	char		str[BUFF_SIZE + 1];
	char		**splitted_strs;
	int			tmp;
	t_object	*obj;

	errno = 0;
	if ((tmp = read(fd, &str, BUFF_SIZE)) == -1)
		msg_finish(NO_FILE_MSG, NULL, errno);
	str[tmp] = 0;
	splitted_strs = ft_strsplit(str, '\n');
	if (!(tmp = check_figuretype(splitted_strs[0])))
		msg_finish(ERR_FIG_MSG, NULL, errno);
	obj = get_fig_info(tmp, &splitted_strs[1]);
	free_char_arr(&splitted_strs);
	return (obj);
}
