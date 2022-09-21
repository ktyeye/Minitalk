
#include "minitalk.h"

void *handler(int signum){
    if (signum == SIGUSR1) {
        write(1, "0", 1);
    }
    else if (signum == SIGUSR2) {
        write(1,"1", 1);
    }
}

int main() {

    printf("d : %d\n", getpid());
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    usleep(100);
    while(1) ;

    return 0;
}