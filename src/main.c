#include <stdio.h>
#include "my_sdl.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl(USG_MSG);
		return (0);
	}
	start(argv[1]);

	return (0);
}
