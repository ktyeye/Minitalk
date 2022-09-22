# ifndef MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>




char	*ft_binary_parser(int num);
size_t  ft_strlen(const char *str);
int     ft_print(const char *str);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
void	*ft_bzero(void *dest, size_t len);
int     ft_atoi(const char *str);


# endif