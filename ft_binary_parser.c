#include "minitalk.h"

int count_binary_length(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num /= 2;
		i++;
	}
	return (i);
}

void    insert_binary(char *buffer, int num, int index)
{
    if (num / 2)
    {
        insert_binary(buffer, num / 2 , index - 1);
        buffer[index] = num % 2 + '0';
    }
    else
    {
        buffer[index] = num % 2 + '0';
    }
    printf("index : %d, num : %d, buffer : %d\n", index, num, num % 2); 
}

char	*ft_binary_parser(int num)
{
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * (32));
	if (!buffer)
		return (0);

    for (int i = 0; i < 32; i++) 
        buffer[i] = '0';
    insert_binary(buffer, num, 31);
    
    return buffer;
}


