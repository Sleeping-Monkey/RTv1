/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:59:21 by gquence           #+#    #+#             */
/*   Updated: 2019/08/29 16:19:52 by ssheba           ###   ########.fr       */
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

t_object	*get_plane(const char **splitted)
{
	t_vec3	pos;
	t_vec3	norm;
	t_color	color;
	int		refl;
	char	*str;

	while (splitted)
	{
		str = (char *)(*splitted);
		if (ft_strcmp(str, "pos\0") == ':')
			pos = get_vector(str + 4);
		else if (ft_strcmp(str, "norm\0") == ':')
			norm = get_vector(str + 5);
		else if (ft_strcmp(str, "color\0") == ':')
			color = get_color(str + 6, &color);
		else if (ft_strcmp(str, "refl\0") == ':')
			refl = ft_atoi(str + 5);
		else if (!ft_strcmp(str, ">>"))
			break ;
		splitted++;
	}
	if (color.r == 0 && color.g == 0 && color.b == 0 && color.a == 0)
		color = COLOR(255, 0, 0, 0);
	print_vector(pos);
	print_vector(norm);
	print_color(color);
	printf("refl = %d", refl);
	return (create_plane(pos, norm, color, refl));
}

t_object	*get_sphere(const char **splitted)
{
	int		i;
	char	*str;
	t_vec3	center;
	t_real	rad;
	t_color	color;
	int		refl;

	i = 0;
	while (i < 4)
	{
		str = (char *)splitted[i];
		if (ft_strcmp(str, "center\0") == ':')
			center = get_vector(str + 7);
		else if (ft_strcmp(str, "rad\0") == ':')
			rad = get_ldouble(str + 4);
		else if (ft_strcmp(str, "color\0") == ':')
			color = get_color(str + 6, &color);
		else if (ft_strcmp(str, "refl\0") == ':')
			refl = ft_atoi(str + 5);
		else if (!ft_strcmp(str, ">>"))
			break ;
		i++;
	}
	if (color.r == 0 && color.g == 0 && color.b == 0 && color.a == 0)
		color = COLOR(255, 0, 0, 0);
	print_vector(center);
	printf("rad = %LF\n", rad);
	print_color(color);
	printf("refl = %d", refl);
	return (create_sphere(center, rad, color, refl));
}

t_object	*get_cylinder(const char **splitted)
{
	int		i;
	char	*str;
	t_vec3	start;
	t_vec3	way;
	t_real	rad;
	t_color	color;
	int		refl;

	i = 0;
	while (i < 5)
	{
		str = (char *)splitted[i];
		if (ft_strcmp(str, "start\0") == ':')
			start = get_vector(str + 6);
		else if (ft_strcmp(str, "way\0") == ':')
			way = get_vector(str + 4);
		else if (ft_strcmp(str, "rad\0") == ':')
			rad = get_ldouble(str + 4);
		else if (ft_strcmp(str, "color\0") == ':')
			color = get_color(str + 6, &color);
		else if (ft_strcmp(str, "refl\0") == ':')
			refl = ft_atoi(str + 5);
		else if (!ft_strcmp(str, ">>"))
			break ;
		i++;
	}
	if (color.r == 0 && color.g == 0 && color.b == 0 && color.a == 0)
		color = COLOR(255, 0, 0, 0);
	print_vector(start);
	print_vector(way);
	printf("rad = %LF\n", rad);
	print_color(color);
	printf("refl = %d", refl);
	return (create_cylinder(start, way, rad, color, refl));
}

t_object	*get_cone(const char **splitted)
{
	int		i;
	char	*str;
	t_vec3	start;
	t_vec3	way;
	t_color	color;
	int		refl;
	t_real	rad;

	i = 0;
	while (i < 4)
	{
		str = (char *)splitted[i];
		if (ft_strcmp(str, "start\0") == ':')
			start = get_vector(str + 6);
		else if (ft_strcmp(str, "way\0") == ':')
			way = get_vector(str + 4);
		else if (ft_strcmp(str, "color\0") == ':')
			color = get_color(str + 6, &color);
		else if (ft_strcmp(str, "rad\0") == ':')
			rad = get_ldouble(str + 4);
		else if (ft_strcmp(str, "refl\0") == ':')
			refl = ft_atoi(str + 5);
		i++;
	}
	print_vector(start);
	print_vector(way);
	print_color(color);
	printf("refl = %d", refl);
	return (create_cone(start, way, rad, color, refl));
}

t_object	*get_fig_info(const int figtype, const char **splitted)
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
	obj = get_fig_info(tmp, (const char **)&splitted_strs[1]);
	free_char_arr(&splitted_strs);
	return (obj);
}
