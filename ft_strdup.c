#include "minitalk.h"

char	*ft_strdup(const char *str)
{
	char	*temp;
	size_t	index;

	temp = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!temp)
		return (0);
	index = 0;
	while (index < ft_strlen(str))
	{
		temp[index] = str[index];
		index++;
	}
	temp[index] = 0;
	return (temp);
}