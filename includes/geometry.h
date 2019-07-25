/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:16:46 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/25 16:26:49 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef double t_real; 

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;
# define COLOR(r, g, b)((t_color){r, g, b})

typedef struct	s_vector
{
	t_real	x;
	t_real	y;
	t_real	z;
}				t_vector;
# define VECTOR(x, y, z)((t_vector){x, y, z})

typedef struct	s_ray
{
	t_vector	start;
	t_vector	finish;
}				t_ray;

typedef struct	s_sphere
{
	t_vector	center;
	t_real		radius;
	t_color		color;
}				t_sphere;

typedef struct	s_object
{
	void		*data;
	t_color		(*get_color)(void *data, t_vector *pos);
	int			(*intersection)(void *data, t_ray *view, t_vector *pos);
}				t_object;

t_object		*create_sphere(t_vector center, t_real r, t_color color);
t_color			get_sphere_color(void *data, t_vector *pos);
int				sphere_intersection(void *data, t_ray *view, t_vector *pos);

t_real			scalar_prod(t_vector *a, t_vector *b);
t_vector		sub_vec(t_vector *a, t_vector *b);
t_vector		add_vec(t_vector *a, t_vector *b);
t_vector		mul_vec_real(t_vector *a, t_real r);

#endif