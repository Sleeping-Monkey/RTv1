#include "reading.h"

t_person    *get_person(char **splitted)
{
	int		i;
	char	*str;
	t_vec3	arr[3];

	i = 0;
	
	while (i < 3)
	{
		str = (char *)splitted[i];
		if (ft_strcmp(str, "o\0") == ':')
			arr[0] = get_vector(str + 2);
		else if (ft_strcmp(str, "x\0") == ':')
			arr[1] = get_vector(str + 2);
		else if (ft_strcmp(str, "y\0") == ':')
			arr[2] = get_vector(str + 2);
		i++;
	}
	return (create_person(arr[0], arr[1], arr[2]));
}