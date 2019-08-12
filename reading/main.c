/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:59:21 by gquence           #+#    #+#             */
/*   Updated: 2019/08/10 16:23:57 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"
#include "geometry.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

void   errs_exit(char *err, void *ptr)
{
    if (!ptr)
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
    if (!ft_strcmp(*str, "plane"))
        return (1);
    if (!ft_strcmp(*str, "sphere"))
        return (2);
    if (!ft_strcmp(*str, "cylinder"))
        return (3);
    return (0);
}

int			ft_fatoi(char **pstr, int *result)
{
	long long int	a;
	int				sign;
	char			*str;

	a = 0;
	sign = 0;
	str = *pstr;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? 1 : 0;
	while (ft_isdigit(*str))
		a = a * 10 + (*str++ - '0');
	if (*str && *str != ',')
		return (0);
	*result = (sign ? -a : a);
	*pstr = str;
	return (1);
}

t_vec3	get_vector(char *str)
{
	t_vec3	res;

	res.x = get_ldouble(str);
	while (*(++str) != ' ' && *str == '\t');
	res.y = get_ldouble(str);
	while (*(++str) != ' ' && *str == '\t');
	res.z = get_ldouble(str);
	return (res);
}

t_color	get_color(char *str, t_color *res)
{
	ft_fatoi(&str, (int *)(&res->r));
	ft_fatoi(&str, (int *)(&res->g));
	ft_fatoi(&str, (int *)(&res->b));
	ft_fatoi(&str, (int *)(&res->a));
	return (*res);
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

t_object	*get_plane(const int fd)
{
	int		i;
	char	*str;
	t_vec3	pos;
	t_vec3	norm;
	t_color	color;
	int		refl;

	i = 0;
	while (i < 4 && get_next_line(fd, &str))
	{
		if (ft_strcmp("pos\0", str) == ':')
			pos = get_vector(&(str + 4));
		else if (ft_strcmp("norm\0", str) == ':')
			norm = get_vector(&(str + 5));
		else if (ft_strcmp("color\0", str) == ':')
			color = get_color(&(str + 6), &color);
		else if (ft_strcmp("refl\0", str) == ':')
			refl = ft_atoi(&(str + 5));
		else
		{
			free(str);
			return (NULL);
		}
		free(str);
		i++;
	}
	return (create_plane(pos, norm, color, refl));
}

t_object	*get_sphere(const int fd)
{
	int		i;
	char	*str;
	t_vec3	center;
	t_real	rad;
	t_color	color;
	int		refl;

	i = 0;
	while (i < 4 && get_next_line(fd, &str))
	{
		if (ft_strcmp("center\0", str) == ':')
			center = get_vector(&(str + 7));
		if (ft_strcmp("rad:\0", str) == ':')
			rad = get_ldouble(str);
		else if (ft_strcmp("color\0", str) == ':')
			color = get_color(&(str + 6), &color);
		else if (ft_strcmp("refl\0", str) == ':')
			refl = ft_atoi(&(str + 5));
		else
		{
			free(str);
			return (NULL);
		}
		free(str);
		i++;
	}
	return (create_sphere(center, rad, color, refl));
}

t_object    *get_fig_info(const int figtype, const int fd)
{
    if (figtype == 1)
        return (get_plane(fd));
    if (figtype == 2)
        return (get_sphere(fd));
}



int main(int ac, char **av)
{
    int			fd;
    char		*str;
    int			tmp;
	t_object	*obj;

    if (ac == 2)
    {
        if (fd = open(av[1], O_RDONLY) < 0)
            err_exit("nofile", NULL);
        while (get_next_line(fd, &str))
        {
            if (!(tmp = check_figuretype(str)))
                errs_exit("check_figtype", str);
            
        }
    }
    else
        ft_putendl("filename is not found");
    return (0);
}