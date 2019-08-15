/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:52:09 by gquence           #+#    #+#             */
/*   Updated: 2019/08/15 14:53:46 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reading.h"
#include "libft.h"
#include "geometry.h"

static double   get_mod(char *str)
{
	double  res;
	double  counter;

	if (!str || !*str)
		return (0.0);
	res = 0.0;
	counter = 10.0;
	while (*str && ft_isdigit(*str))
	{		
		res += (double)(*str - '0') / counter;
		counter *= 10.0;
		str++;
	}
	return (res);
}

static double   get_div(char **pstr)
{
	double  res;
	char    *str;


	if (!pstr || !*pstr || !**pstr)
		return (0.0);
	str = *pstr;
	res = 0.0;
	while (*str && ft_isdigit(*str))
	{
		res *= 10.0;
		res += (double)(*str - '0');
		str++;
	}
	*pstr = str;
	return (res);
}

long double get_ldouble(char *str)
{
	int         isposit;
	long double res;

	if (!str || !*str)
		return (0.0);
	while (*str == ' ' || *str == '\t')
		str++;
	isposit = 0;
	if (*str == '-')
	{
		isposit = 1;
		str++;
	}
	res = (long double)get_div(&str);
	if (*str == '.')
		res += (long double)get_mod(++str);
	if (isposit)
		res = -res;
	return (res);
}
