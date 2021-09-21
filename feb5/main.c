
#include <stdio.h>
#include <stdlib.h>

extern int ipow(int x, int y);

int main(int argc, char *argv[]) {

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    printf("%d\n", ipow(x,y));
    return 0;
} 
