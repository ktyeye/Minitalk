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
	// 패킷 전송 및 확인

	int i;
	i = 0;
	while (pkt.packet[i])
	{
		post(pkt.pid, pkt.packet[i] - '0');
		i++;
	}
}

bool	send_msg(int pid, char *msg)
{
	int i;
	t_msg pkt;

	i = 0;
	pkt.pid = pid;
	while (msg[i])
	{
		pkt.packet = ft_binary_parser(ft_atoi(msg[i]));
		if (!send_packet(pkt))
		{
			continue ;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	else
	{
		ft_print("PID : ");
		ft_print(argv[1]);
		ft_print("\nMSG : ");
		ft_print(argv[2]);
		send_msg(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}