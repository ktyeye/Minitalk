/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeykim <taeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:56:51 by taeykim           #+#    #+#             */
/*   Updated: 2022/09/23 01:11:30 by taeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo)
{
	static unsigned char	buffer[100];
	static int				index;
	static int				bit;

	if (bit == 0)
	{
		bit = 8;
		index++;
	}
	if (signo == SIGUSR1)
		buffer[index] += 1 << --bit;
	else if (signo == SIGUSR2)
		--bit;
	if (bit == 0)
	{
		if (buffer[index] == 0 || index == 99)
		{
			write(1, &buffer[1], index);
			if (buffer[index] == 0)
				write(1, "\n", 1);
			ft_bzero(buffer, 100);
			index = 0;
		}
	}
}

bool	print_pid(void)
{
	char	*pid_chr;

	pid_chr = ft_itoa(getpid());
	if (!pid_chr)
		return (0);
	ft_print("SERVER PID : ");
	ft_print(pid_chr);
	write(1, "\n", 1);
	return (true);
}

int	main(void)
{
	if (!print_pid())
	{
		ft_print("malloc error");
		exit(1);
	}
	if (signal(SIGUSR1, handler) != 0)
	{
		write(1, "SIGACTION ERROR", 15);
		exit(1);
	}
	if (signal(SIGUSR2, handler) != 0)
	{
		write(1, "SIGACTION ERROR", 15);
		exit(1);
	}
	while (1)
		;
	return (0);
}
