/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:47:42 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/07 13:20:03 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMAT_H
# define TMAT_H

# include <stdlib.h>
# include <math.h>

# include "libft.h"

# define EPSILON 0.000001
# define R_ABS fabs
# define R_ROUND round
# define TO_RAD(a)((a)*(M_PI / 180.0))

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
# define VEC(x, y, z)((t_vec3){x, y, z})

/*
** Matrix3 ops
*/
t_mat3			*m3_mul(t_mat3 *a, t_mat3 *b, t_mat3 *out);
t_vec3			*m3v3_mul(t_mat3 *a, t_vec3 *b, t_vec3 *out);
t_mat3			*m3r_mul(t_mat3 *a, t_real r, t_mat3 *out);
t_mat3			*m3_copy(t_mat3 *m, t_mat3 *out);
void			m3_zero(t_mat3 *m);
t_real			m3_det(t_mat3 *m);
t_mat3			*m3_inv(t_mat3 *m, t_mat3 *out);
void			m3_rotx(t_mat3 *m, t_real alpha);
void			m3_roty(t_mat3 *m, t_real alpha);
void			m3_rotz(t_mat3 *m, t_real alpha);
t_mat3			*m3_trs(t_mat3 *m, t_mat3 *out);

/*
** Vec3 ops
*/
t_real			v3_len(t_vec3 *v);
t_vec3			*v3_add(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3			*v3_sub(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_vec3			*v3_cross(t_vec3 *a, t_vec3 *b, t_vec3 *out);
t_real			v3_dot(t_vec3 *a, t_vec3 *b);
t_vec3			*v3_norm(t_vec3 *v, t_vec3 *out);
t_vec3			*v3s_mull(t_vec3 *v, t_real s, t_vec3 *out);
t_vec3			*v3s_add(t_vec3 *v, t_real s, t_vec3 *out);
t_vec3			*v3_copy(t_vec3 *v, t_vec3 *out);

#endif
