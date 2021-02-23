#include <stdio.h>

extern void swap(int [], int, int);


int main() {
    int vec[] = { 33, 15, 2, 94, 6, 7, 15, 23};
    swap(vec,2,7);

    for (int i = 0; i < 8; i++)
        printf("%d ", vec[i]);

    printf("\n");
}

