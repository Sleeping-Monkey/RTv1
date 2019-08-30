/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:36:56 by gquence           #+#    #+#             */
/*   Updated: 2019/08/30 16:46:47 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "reading.h"
#include "libft.h"

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
