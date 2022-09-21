#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void *zero_handler(int pid) {
    write(1, "0", 1);
    kill(pid, SIGUSR1);
}

void *num_handler(int pid) {
    write(1, "1", 1);
    kill(pid, SIGUSR2);
}


int main(int argc, char *argv[]) {
    char *a = "0101 1111";

    if (argc <= 1) {
        printf("인수 입력\n");
        return 0;
    }

    int pid = atoi(argv[1]);

    printf("pid : %d\n", pid);

    for (int i = 0; i < 10; i++) {
        printf("%c", a[i]);
    }
    printf("\n");

    int count = 0;
    while(*a) {
        if (*a == '0') {
            signal(*a, zero_handler(pid));
        }
        else if (*a == '1') {
            signal(*a, num_handler(pid));
        }
        else {
            write(1, a, 1);
        }
        count++;
        a++;
    }
    printf("\ncount : %d", count);

    return 0;
}