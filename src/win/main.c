/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:06:52 by ssheba            #+#    #+#             */
/*   Updated: 2019/08/29 18:10:23 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "geometry.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putendl(USG_MSG);
		return (0);
	}
	errno = 0;
	start(argv + 1, argc - 1);
	return (0);
}
