/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_shine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:43:12 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/27 18:21:53 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

t_shine     *get_shine(char **splitted)
{
	int		i;
	char	*str;
	t_shine	*res;
	
	i = 0;
    if (!(res = (t_shine *)malloc(sizeof(t_shine))))
        msg_finish(MEM_MSG);
	while (i < 3)
	{
		str = (char *)splitted[i];
		if (ft_strcmp(str, "shine\0") == ':')
			res->type = ft_atoi(str + 6);
		else if (ft_strcmp(str, "pos\0") == ':')
			res->pos = get_vector(str + 4);
		else if (ft_strcmp(str, "bright\0") == ':')
			res->bright = get_ldouble(str + 7);
		i++;
	}
	printf("type = %d\n", res->type);
	print_vector(res->pos);
	printf("bright = %LF", res->bright);
	return (res);
}

t_shine	    *read_shineinfo(char *filename)
{
	int			fd;
	char		str[BUFF_SIZE + 1];
	char		**splitted_strs;
	int			tmp;
	t_shine 	*obj;

	if (filename != NULL && *filename != 0)
	{
		if ((fd = open(filename, O_RDONLY)) < 0)
			msg_finish(NO_FILE_MSG);
		if ((tmp = read(fd, &str, BUFF_SIZE)) == -1)
			return (NULL);
		str[tmp] = 0;
		splitted_strs = ft_strsplit(str, '\n');
		obj = get_shine(splitted_strs);
		free_char_arr(&splitted_strs);
		return (obj);
	}
	else
		ft_putendl("filename is not found");
	return (NULL);
}