/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:21:06 by gquence           #+#    #+#             */
/*   Updated: 2019/08/10 14:13:11 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
}				t_color;


typedef long double	t_real;
typedef struct	s_mat3
{
	t_real	r[3][3];
}				t_mat3;

typedef struct	s_vec3
{
	t_real	x;
	t_real	y;
	t_real	z;
}				t_vec3;

long double get_ldouble(char *str);

#endif