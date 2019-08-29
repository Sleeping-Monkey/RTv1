/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_person.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:58:57 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:14:03 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_person	*create_person(t_vec3 o, t_vec3 x, t_vec3 y)
{
	t_person	*new_person;
	t_vec3		i;
	t_vec3		j;
	t_vec3		k;

	errno = 0;
	if (!(new_person = (t_person *)malloc(sizeof(t_person))))
		msg_finish(MEM_MSG, NULL, errno);
	v3_norm(v3_sub(&x, &o, &i), &i);
	v3_norm(v3_sub(&y, &o, &j), &j);
	v3_cross(&i, &j, &k);
	new_person->axis.r[0][0] = i.x;
	new_person->axis.r[1][0] = i.y;
	new_person->axis.r[2][0] = i.z;
	new_person->axis.r[0][1] = j.x;
	new_person->axis.r[1][1] = j.y;
	new_person->axis.r[2][1] = j.z;
	new_person->axis.r[0][2] = k.x;
	new_person->axis.r[1][2] = k.y;
	new_person->axis.r[2][2] = k.z;
	m3_inv(&new_person->axis, &new_person->inv_axis);
	new_person->o = o;
	return (new_person);
}
