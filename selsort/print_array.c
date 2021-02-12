#include <stdio.h>

void print_array(int vec[], int n) {

    for (int i = 0; i < n - 1; i++) 
        printf("%d, ", vec[i]);

    printf("%d\n", vec[n-1]);
}
