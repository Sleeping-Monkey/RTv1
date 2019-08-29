/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:13:08 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:30:18 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

t_object	*get_sphere(char **splitted)
{
	int		i;
	t_vec3	center;
	t_real	rad;
	t_color	color;
	int		refl;

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(splitted[i], "center\0") == ':')
			center = get_vector(splitted[i] + 7);
		else if (ft_strcmp(splitted[i], "rad\0") == ':')
			rad = get_ldouble(splitted[i] + 4);
		else if (ft_strcmp(splitted[i], "color\0") == ':')
			color = get_color(splitted[i] + 6, &color);
		else if (ft_strcmp(splitted[i], "refl\0") == ':')
			refl = ft_atoi(splitted[i] + 5);
		else if (!ft_strcmp(splitted[i], ">>"))
			break ;
		i++;
	}
	if (color.r == 0 && color.g == 0 && color.b == 0 && color.a == 0)
		color = COLOR(255, 0, 0, 0);
	return (create_sphere(center, rad, color, refl));
}
