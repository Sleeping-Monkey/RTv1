/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:21:06 by gquence           #+#    #+#             */
/*   Updated: 2019/08/15 14:57:35 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include "geometry.h"

void    	print_color(t_color color);
void	    print_vector(t_vec3 vect);
long double get_ldouble(char *str);
int	        ft_fatoi(char **pstr, int *result);
t_color	    get_color(char *str, t_color *res);
t_vec3  	get_vector(char *str);
t_object    *read_objinfo(char *filename);

#endif