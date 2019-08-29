#include <stdio.h>
#include "geometry.h"

int main(int argc, char **argv)
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
