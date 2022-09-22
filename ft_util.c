#include "minitalk.h"

size_t ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);    
}

int ft_print(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
	return (i);
}



