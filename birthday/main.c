#include <stdio.h>
#include <stdlib.h>

extern int simulate(int n, int i);

int main(int argc, char *argv[]) {

     int n = atoi(argv[1]);

     int sum = 0;

     for (int i = 0; i < 10000; i++)
         sum = sum + simulate(n, i);

     printf("%.1f\n", sum/((double) 10000) * 100);
}
