/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:13:54 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:30:24 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

t_object	*get_cylinder(char **splitted)
{
	int		i;
	t_vec3	sw[2];
	t_real	rad;
	t_color	color;
	int		refl;

	i = -1;
	while (++i < 5)
	{
		if (ft_strcmp(splitted[i], "start\0") == ':')
			sw[0] = get_vector(splitted[i] + 6);
		else if (ft_strcmp(splitted[i], "way\0") == ':')
			sw[1] = get_vector(splitted[i] + 4);
		else if (ft_strcmp(splitted[i], "rad\0") == ':')
			rad = get_ldouble(splitted[i] + 4);
		else if (ft_strcmp(splitted[i], "color\0") == ':')
			color = get_color(splitted[i] + 6, &color);
		else if (ft_strcmp(splitted[i], "refl\0") == ':')
			refl = ft_atoi(splitted[i] + 5);
		else if (!ft_strcmp(splitted[i], ">>"))
			break ;
	}
	if (color.r == 0 && color.g == 0 && color.b == 0 && color.a == 0)
		color = COLOR(255, 0, 0, 0);
	return (create_cylinder(sw, rad, color, refl));
}
