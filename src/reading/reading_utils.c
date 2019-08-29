/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:36:56 by gquence           #+#    #+#             */
/*   Updated: 2019/08/23 20:02:36 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "reading.h"
#include "libft.h"

void	print_vector(t_vec3 vect)
{
	printf("vector: x=%LF y=%LF z=%LF\n", vect.x, vect.y, vect.z);
}

void	print_color(t_color color)
{
	printf("color: r=%d g=%d b=%d a=%d\n", (int)color.r, (int)color.g,
	(int)color.b, (int)color.a);
}

int		ft_fatoi(char **pstr, int *result)
{
	long long int	a;
	int				sign;
	char			*str;

	a = 0;
	sign = 0;
	str = *pstr;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? 1 : 0;
	while (ft_isdigit(*str))
		a = a * 10 + (*str++ - '0');
	*result = (sign ? -a : a);
	*pstr = str;
	return (1);
}

t_color	get_color(char *str, t_color *res)
{
	ft_fatoi(&str, (int *)(&res->r));
	ft_fatoi(&str, (int *)(&res->g));
	ft_fatoi(&str, (int *)(&res->b));
	ft_fatoi(&str, (int *)(&res->a));
	return (*res);
}

t_vec3	get_vector(char *str)
{
	t_vec3	res;

	res.x = get_ldouble(str);
	str++;
	while (*str != ' ' && *str != '\t')
		str++;
	res.y = get_ldouble(str);
	str++;
	while (*str != ' ' && *str != '\t')
		str++;
	res.z = get_ldouble(str);
	return (res);
}
