#include "minitalk.h"


void post(int pid, int bit) {
	if (bit == 1)
		kill(pid, SIGUSR1);
	else if (bit == 0)
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send_packet(int pid, int num, int index)
{
	if (!num)
	{
		while (index < 8)
		{
			post(pid, 0);
			index++;
		}
		return ;
	}
	else
	{
		send_packet(pid, num / 2, ++index);
		post(pid, num % 2);
	}
}

void	send_msg(int pid, char *msg)
{
	int i;
	int temp;

	i = 0;
	while (msg[i])
	{
		printf("%c, %d\n", msg[i], msg[i]);
		send_packet(pid, msg[i], 0);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	else
	{
		ft_print("\nPID : ");
		ft_print(argv[1]);
		ft_print("\nMSG : ");
		ft_print(argv[2]);
		ft_print("\n");
		send_msg(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}