/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:21:06 by gquence           #+#    #+#             */
/*   Updated: 2019/08/29 16:22:27 by ssheba           ###   ########.fr       */
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

void		print_color(t_color color);
void		print_vector(t_vec3 vect);
long double	get_ldouble(char *str);
int			ft_fatoi(char **pstr, int *result);
t_color		get_color(char *str, t_color *res);
t_vec3		get_vector(char *str);
t_object	*read_objinfo(int fd);
t_shine		*read_shineinfo(int fd);
t_person	*read_personinfo(int fd);

int			get_fd(char *filename);
#endif
