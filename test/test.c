#include "minitalk.h"


int main() {
    static unsigned char buf[8];

    int a = 'a' ;//96
    int b = 'b' ;//97
    int index = 0;
    
    a &= b;

    int temp = 1;
    unsigned int zero = 0;

    // printf("buf : %s\n", buf);
    printf("temp : %d\n", (temp << 3 )+ 1);
    printf("reverse_ zero : %u\n", ~zero);
    // printf("%d, %c\n", index, index);

    // printf("a : %u, b: %d\n", a, b);
    // printf("a &=b : %u, %c\n", a, a);
    // printf("a &=b : %u, %c\n", a, 127);

    


    // printf("index : %d, buf : %s, chr : %c\n", index, buf, buf[index]);


    // printf("index : %d, buf : %s, chr : %c\n", index, buf, buf[index]);

    return (0);
}