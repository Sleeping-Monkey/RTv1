/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_person.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:52:25 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 17:52:28 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

t_person	*get_person(char **splitted)
{
	int		i;
	char	*str;
	t_vec3	arr[3];

	i = 0;
	while (i < 3)
	{
		str = (char *)splitted[i];
		if (ft_strcmp(str, "o\0") == ':')
			arr[0] = get_vector(str + 2);
		else if (ft_strcmp(str, "x\0") == ':')
			arr[1] = get_vector(str + 2);
		else if (ft_strcmp(str, "y\0") == ':')
			arr[2] = get_vector(str + 2);
		i++;
	}
	return (create_person(arr[0], arr[1], arr[2]));
}

t_person	*read_personinfo(int fd)
{
	char		str[BUFF_SIZE + 1];
	char		**splitted_strs;
	int			tmp;
	t_person	*obj;

	errno = 0;
	if ((tmp = read(fd, &str, BUFF_SIZE)) == -1)
		msg_finish(NO_FILE_MSG, NULL, errno);
	close(fd);
	str[tmp] = 0;
	splitted_strs = ft_strsplit(str, '\n');
	obj = get_person(splitted_strs);
	free_char_arr(&splitted_strs);
	return (obj);
}
