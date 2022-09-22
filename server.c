#include "minitalk.h"

void	handler(int signo, siginfo_t *info, void *context)
{
    /* 
        배열에 값을 저장 -> 127이 종료 신호이기 때문에 
        127이 나올 경우 End
    */
    static unsigned char chr;
    static int index;
    static int count;

    index++;
    if (signo == SIGUSR1)
        chr = (chr << 1) + 1;
    else if (signo == SIGUSR2)
        chr = (chr << 1);
}

bool print_pid() {
    char *pid_chr;
    
    pid_chr = ft_itoa(getpid());
    if (!pid_chr)
        return (0);
    ft_print("SERVER PID : ");
    ft_print(pid_chr);
    return (true);
}

int		main(void)
{
	struct sigaction	pkt;

	pkt.sa_sigaction = handler;
	pkt.sa_flags = SA_SIGINFO; // siginfo 해준 이유?

    if (!print_pid())
    {
        ft_print("malloc error");
        exit(1);
    }
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