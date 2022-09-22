#include "minitalk.h"

void	handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	buf[100];
	static int				idx;
	static int				count;


	if (signo == SIGUSR1)
        write (1, "0", 1);
	else if (signo == SIGUSR2)
        write(0, "1", 1);
}

void print_pid() {
    char *pid = ft_itoa(getpid());
    ft_strlen(pid);
    
}



int		main(void)
{
	struct sigaction	pkt;

	pkt.sa_sigaction = handler;
	pkt.sa_flags = SA_SIGINFO; // siginfo 해준 이유.

    usleep(100);


	if (sigaction(SIGUSR1, &pkt, NULL) != 0)
	{
		write(1, "Sigaction Error", 15);
		exit(1);
	}
	if (sigaction(SIGUSR2, &pkt, NULL) != 0)
	{
		write(1, "Sigaction Error", 15);
		exit(1);
	}
	while (1)
		;
	return (0);
}