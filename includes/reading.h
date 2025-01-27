/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:31:20 by ssheba            #+#    #+#             */
/*   Updated: 2019/09/09 19:31:28 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "geometry.h"

# define BUFF_SIZE 2000
# define NO_FILE_MSG    "Problem with file:"
# define ERR_FIG_MSG    "Use only cylinder, sphere, plane or cone"
# define ERR_VAL_MSG	"Wrong description"

long double	get_ldouble(char *str);
int			ft_fatoi(char **pstr, int *result);

t_color		get_color(char *str, t_color *res);
t_vec3		get_vector(char *str);

t_object	*get_plane(char **splitted);
t_object	*get_sphere(char **splitted);
t_object	*get_cylinder_or_cone(char **splitted, int type);

t_object	*read_objinfo(int fd);
t_shine		*read_shineinfo(int fd);
t_person	*read_personinfo(int fd);

int			get_fd(char *filename);
#endif
