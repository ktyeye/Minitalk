#include "minitalk.h"

void	handler(int signo)
{
    static unsigned char buffer[100];
    static int index; //문자수 
    static int bit; //현재 bit 수

    if (bit == 0){ //시작 지점
        bit = 8;
        index++;
    }
    if (signo == SIGUSR1)
        buffer[index] += 1 << --bit;
    else if (signo == SIGUSR2)
        --bit;
    if (bit == 0) {
        if (buffer[index] == 0 || index == 99)
        { 
            write(1, &buffer[1], index);
            if(buffer[index] == 0)
                write(1, "\n", 1);
            ft_bzero(buffer, 100);
            index = 0;
        }
    }
}

bool print_pid() {
    char *pid_chr;
    
    pid_chr = ft_itoa(getpid());
    if (!pid_chr)
        return (0);
    ft_print("SERVER PID : ");
    ft_print(pid_chr);
    write(1, "\n", 1);
    return (true);
}

int		main(void)
{
	// struct sigaction	pkt;

	// pkt.sa_sigaction = handler;
	// pkt.sa_flags = SA_SIGINFO; // siginfo 해준 이유?

    // if (!print_pid())
    // {
    //     ft_print("malloc error");
    //     exit(1);
    // }
	// if (sigaction(SIGUSR1, &pkt, NULL) != 0)
	// {
	// 	write(1, "Sigaction Error", 15);
	// 	exit(1);
	// }
	// if (sigaction(SIGUSR2, &pkt, NULL) != 0)
	// {
	// 	write(1, "Sigaction Error", 15);
	// 	exit(1);
	// }
    if (!print_pid())
    {
        ft_print("malloc error");
        exit(1);
    }
    if (signal(SIGUSR1, (void *)handler) != 0)
    {
        write(1, "SIGACTION ERROR", 15);
        exit(1);
    }
    if (signal(SIGUSR2, (void *)handler) != 0)
    {
        write(1, "SIGACTION ERROR", 15);
        exit(1);
    }
	while (1)
		;
	return (0);
}