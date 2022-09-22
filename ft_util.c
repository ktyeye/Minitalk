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
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	*ft_bzero(void *dest, size_t len)
{
	unsigned char	*temp;
	size_t			index;

	index = 0;
	temp = (unsigned char *)dest;
	while (index < len)
	{
		temp[index] = 0;
		index++;
	}
	return (dest);
}
