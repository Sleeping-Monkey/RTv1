/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:05:26 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/25 16:28:20 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_color	get_sphere_color(void *data, t_vector *pos)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	if (pos)
		return (sphere->color);
	return (COLOR(255, 255, 255));
}
