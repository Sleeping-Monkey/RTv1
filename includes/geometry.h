/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:16:46 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/30 16:57:04 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <pthread.h>
# include <errno.h>

# ifdef __APPLE__
#  include "SDL.h"
# else
#  include <SDL2/SDL.h>
# endif
# include "mat.h"

# define WIN_X	1000
# define WIN_Y	1000
# define USG_MSG    "Usage: ./RTv1 -p person_file -l shine_files -o obj_files"

# define MEM_MSG    "No memory =("
# define SDL_MSG    "It is SDL problem"
# define PTH_MSG	"Pthreads error"

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
}				t_color;
# define COLOR(r, g, b, a)((t_color){r, g, b, a})

typedef struct	s_ray
{
	t_vec3	start;
	t_vec3	finish;
}				t_ray;

typedef struct	s_sphere
{
	t_mat3		axis;
	t_mat3		inv_axis;
	t_vec3		o;
	t_real		r;
	t_color		color;
	int			reflection;
}				t_sphere;

typedef struct	s_plane
{
	t_mat3		axis;
	t_mat3		inv_axis;
	t_vec3		p;
	t_vec3		norm;
	t_color		color;
	int			reflection;
}				t_plane;

typedef struct	s_cylinder
{
	t_mat3		axis;
	t_mat3		inv_axis;
	t_vec3		o;
	t_real		r;
	t_real		r_2;
	t_color		color;
	int			reflection;
}				t_cylinder;

typedef struct	s_cone
{
	t_mat3		axis;
	t_mat3		inv_axis;
	t_vec3		o;
	t_real		r;
	t_real		r_2;
	t_color		color;
	int			reflection;
}				t_cone;

typedef enum	e_type_shine
{
	AMBIENT = 1,
	POINT = 2,
	DIRECTIONAL = 3
}				t_type_shine;

typedef struct	s_shine
{
	t_type_shine	type;
	t_vec3			pos;
	t_real			bright;
}				t_shine;

typedef struct s_f_t	t_f_t;
typedef struct s_sdl	t_sdl;

typedef struct	s_object
{
	void				*data;
	t_color				(*get_color)(void *data, t_vec3 *pos,
													t_sdl *win, size_t id);
	int					(*intersection)(void *data, t_ray *view,
													t_vec3 *pos, t_real *t);
}				t_object;

typedef struct	s_point
{
	unsigned	x;
	unsigned	y;
	t_color		color;
}				t_point;

typedef struct	s_img
{
	SDL_Surface		*img;
	unsigned char	*pixels;
}				t_img;

typedef struct	s_person
{
	t_mat3	axis;
	t_mat3	inv_axis;
	t_vec3	o;
}				t_person;

struct			s_sdl
{
	SDL_Window		*win;
	t_img			img;
	SDL_Event		e;
	t_shine			**lamp;
	size_t			lamp_size;
	char			amb_flag;
	t_object		**mas;
	size_t			obj_size;
	t_person		*view;
};

struct			s_f_t
{
	t_sdl		*win;
	t_ray		ray;
	t_vec3		pos;
	size_t		line;
	size_t		id;
};

t_object		*create_sphere(t_vec3 center, t_real r, t_color color, int ref);
t_color			get_sphere_color(void *data, t_vec3 *pos,
													t_sdl *win, size_t id);
int				sphere_intersection(void *data, t_ray *view,
													t_vec3 *pos, t_real *t);

t_object		*create_plane(t_vec3 pos, t_vec3 norm, t_color color, int ref);
t_color			get_plane_color(void *data, t_vec3 *pos, t_sdl *win, size_t id);
int				plane_intersection(void *data, t_ray *view,
													t_vec3 *pos, t_real *t);

t_object		*create_cylinder(t_vec3 *sw, t_real r, t_color color, int ref);
t_color			get_cylinder_color(void *data, t_vec3 *pos,
													t_sdl *win, size_t id);
int				cylinder_intersection(void *data, t_ray *view,
													t_vec3 *pos, t_real *t);

t_object		*create_cone(t_vec3 *sw, t_real r, t_color color, int ref);
t_color			get_cone_color(void *data, t_vec3 *pos, t_sdl *win, size_t id);
int				cone_intersection(void *data, t_ray *view,
											t_vec3 *pos, t_real *t);

void			init_shine(t_sdl *win, int count);
t_real			get_lighting(t_sdl *win, t_vec3 *pnv, int power, size_t id);

t_person		*create_person(t_vec3 o, t_vec3 x, t_vec3 y);

void			set_pixel(t_sdl *win, t_point *pos);

void			start(char **file_name, int size);
void			finish(t_sdl *win);
void			msg_finish(char *msg, char *filename, int flag);

void			event(t_sdl *win);

int				init_objects(t_sdl *win, char **file_name, int size);

void			trace(t_sdl *win);

#endif
