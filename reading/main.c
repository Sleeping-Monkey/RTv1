/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:59:21 by gquence           #+#    #+#             */
/*   Updated: 2019/08/15 15:01:45 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"
#include "geometry.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

void   errs_exit(char *err, void *ptr)
{
    if (ptr)
        free(ptr);
    if (!ft_strcmp("check_figtype", err))
        ft_putendl("There is no figure like this!(in using: cylinder, sphere, plane, cone)");
    else if (!ft_strcmp("nofile", err))
        ft_putendl("There is no file with this filename in this directory");
    else
        return ;
    exit(1);   
}

int check_figuretype(char *str)
{
    if (!ft_strcmp(str, "plane"))
        return (1);
    if (!ft_strcmp(str, "sphere"))
        return (2);
    if (!ft_strcmp(str, "cylinder"))
        return (3);
    return (0);
}

/*
** template of filling file:

vectors: x y z
t_color: r g b a

#1
"plane
pos: 1.0 2.0 3.0
norm: 0 0 1
color: 0-255 0-255 0-255 0-255
refl: 1-3"
*/

t_object	*get_plane(const char **splitted)
{
	int		i;
	t_vec3	pos;
	t_vec3	norm;
	t_color	color;
	int		refl;
	char	*str;

	i = 0;
	while (i < 4)
	{
		str = (char *)splitted[i];
		if (ft_strcmp(str, "pos\0") == ':')
			pos = get_vector(str + 4);
		else if (ft_strcmp(str, "norm\0") == ':')
			norm = get_vector(str + 5);
		else if (ft_strcmp(str, "color\0") == ':')
			color = get_color(str + 6, &color);
		else if (ft_strcmp(str, "refl\0") == ':')
			refl = ft_atoi(str + 5);
		i++;
	}
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
		i++;
	}
	print_vector(center);
	printf("rad = %LF\n", rad);
	print_color(color);
	printf("refl = %d", refl);
	return (create_sphere(center, rad, color, refl));
}

t_object    *get_fig_info(const int figtype, const char **splitted)
{
    if (figtype == 1)
        return (get_plane(splitted));
    if (figtype == 2)
        return (get_sphere(splitted));
	return (NULL);
}

t_object *read_objinfo(char *filename)
{
    int			fd;
    char		str[200];
	char		**splitted_strs;
    int			tmp;
	t_object	*obj;

	if (filename != NULL && *filename != 0)
	{
        if ((fd = open(filename, O_RDONLY)) < 0)
            errs_exit("nofile", NULL);
		if ((tmp = read(fd, &str, 199)) == -1)
			return (NULL);
		str[tmp] = 0;
		splitted_strs = ft_strsplit(str, '\n');
        if (!(tmp = check_figuretype(splitted_strs[0])))
                errs_exit("check_figtype", str);
        obj = get_fig_info(tmp, (const char **)&splitted_strs[1]);
		free_char_arr(&splitted_strs);
		return (obj);
    }
    else
        ft_putendl("filename is not found");
    return (NULL);
}
/*
int main(int ac, char **av)
{
	if (ac == 2)
		read_objinfo(av[1]);
	return (0);	
}*/
