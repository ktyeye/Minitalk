#include "minitalk.h"

typedef struct s_msg
{
	int		pid;
	char	*packet;
} t_msg;

void post(int pid, int bit) {
	if (bit == 1)
		kill(pid, SIGUSR1);
	else if (bit == 0)
		kill(pid, SIGUSR2);
	usleep(100);
}

bool	send_packet(t_msg pkt)
{
	int i;
	i = 0;
	printf("pkt : %s\n", pkt.packet);
	while (pkt.packet[i])
	{
		post(pkt.pid, pkt.packet[i] - '0');
		i++;
	}
	return (true);
}

bool	send_msg(int pid, char *msg)
{
	int i;
	t_msg pkt;
	int temp;

	i = 0;
	pkt.pid = pid;
	while (msg[i])
	{
		printf("%c, %d\n", msg[i], msg[i]);
		pkt.packet = ft_binary_parser(msg[i]);
		if (!pkt.packet)
			return (0);
		if (!send_packet(pkt))
			continue ;
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