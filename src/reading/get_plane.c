/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:25 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:30:10 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

t_object	*get_plane(char **splitted)
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
	return (create_plane(pos, norm, color, refl));
}
