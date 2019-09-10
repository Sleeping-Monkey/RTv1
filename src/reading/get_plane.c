/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:25 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/31 10:54:02 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"

t_object	*get_plane(char **splitted)
{
	t_vec3	pos;
	t_vec3	norm;
	t_color	color;
	int		refl;
	int		i;

	i = 0;
	while (splitted[i])
	{
		if (ft_strcmp(splitted[i], "pos\0") == ':')
			pos = get_vector(splitted[i] + 4);
		else if (ft_strcmp(splitted[i], "norm\0") == ':')
			norm = get_vector(splitted[i] + 5);
		else if (ft_strcmp(splitted[i], "color\0") == ':')
			color = get_color(splitted[i] + 6, &color);
		else if (ft_strcmp(splitted[i], "refl\0") == ':')
			refl = ft_atoi(splitted[i] + 5);
		else
			msg_finish(ERR_VAL_MSG, NULL, 0);
		i++;
	}
	return (create_plane(pos, norm, color, refl));
}
