/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:57:37 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/16 19:17:40 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sdl.h"

int	init_objects(t_sdl *win)
{
//	printf("sphere - (%Lf, %Lf)\n", WIN_X / 3.0L, WIN_Y * 2.0L / 3.0);
	srandom(time(NULL));
	if (!(win->mas[0] = create_plane(VEC(0, WIN_Y * 0.9, 700), VEC(0, -1, 0), COLOR(0, 0, 255, 0), -1)))
		return (0);
	if (!(win->mas[1] = create_plane(VEC(0, 0, 1000), VEC(0, 0, -1), COLOR(0, 0, 255, 0), -1)))
		return (0);
	if (!(win->mas[2] = create_plane(VEC(WIN_X * 0.9, WIN_Y * 0.9, 0), VEC(-1, 0, 0), COLOR(0, 0, 255, 0), -1)))
		return (0);
	if (!(win->mas[3] = create_plane(VEC(0, WIN_Y * 0.9, 500), VEC(1, -1, 0), COLOR(0, 0, 255, 0), -1)))
		return (0);
	if (!(win->mas[4] = create_cone(VEC(WIN_X * 0.5, WIN_Y * 0.5, 100), VEC(1, 0, 0), 1, COLOR(150, 0, 0, 0), 10)))
		return (0);
	if (!(win->mas[5] = create_sphere(VEC(WIN_X * 0.8, WIN_Y * 0.3, 0), 50, COLOR(150, 0, 0, 0), 10)))
		return (0);
//	if (!(win->mas[1] = create_cylinder(VEC(0, 100, 300), VEC(0, 1, 0), 10, COLOR(0, 150, 0, 0), 10)))
//		return (0);
//	if (!(win->mas[2] = create_cylinder(VEC(10, 50, 1000), VEC(1, 0, 0), 100, COLOR(0, 0, 150, 0), 10)))
//		return (0);
//	if (!(win->mas[0] = create_cylinder(VEC(WIN_X * 0.5, WIN_Y * 0.5, 10), VEC(1, 1, 0), WIN_X * 0.1, COLOR(155, 0, 150, 0), 1)))
//		return (0);
//	if (!(win->mas[0] = create_cylinder(VEC(WIN_X * 0.5, WIN_Y * 0.5, 10), VEC(0, 1, 0), WIN_X * 0.1, COLOR(155, 0, 150, 0), 1)))
//		return (0);
//	if (!(win->mas[2] = create_cylinder(VEC(WIN_X * 0.5, WIN_Y * 0.5, 10), VEC(0, 0, 1), WIN_X * 0.1, COLOR(155, 0, 150, 0), 1)))
//		return (0);
//	if (!(win->mas[0] = create_sphere(VEC(WIN_X * 0.5, WIN_Y * 0.5, 700), 100, COLOR(150, 0, 0, 0), 1)))
//		return (0);
//	if (!(win->mas[4] = create_sphere(VEC(WIN_X * 0.6, WIN_Y * 0.5, 10), 50, COLOR(150, 0, 0, 0), 5)))
//		return (0);
//	if (!(win->mas[5] = create_sphere(VEC(WIN_X * 0.1, WIN_Y * 0.3, 0), 50, COLOR(150, 0, 0, 0), 10)))
//		return (0);
//	if (!(win->mas[3] = create_sphere(VEC(WIN_X * 0.9, WIN_Y * 0.3, 100), 50, COLOR(150, 0, 0, 0), 100)))
//		return (0);
//	if (!(win->mas[3] = create_sphere(VEC(WIN_X * 0.4, WIN_Y * 0.8, 50), 50, COLOR(150, 0, 0, 0), 1000)))
//		return (0);
//	if (!(win->mas[4] = create_sphere(VEC(WIN_X * 0.6, WIN_Y * 0.9, 10), 50, COLOR(150, 0, 0, 0), 500)))
//		return (0);
//	if (!(win->mas[4] = create_plane(VECTOR(0, WIN_Y - 10, 700), VECTOR(0, -1, 0), COLOR(0, 255, 0, 0), -1)))
//		return (0);	
	win->obj_size = 6;
	return (1);
}