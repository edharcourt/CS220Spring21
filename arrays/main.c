#include <stdio.h>

extern void scale(int *vec, int s, int n);

void print_array(int *vec, int n) {
    for (int i = 0; i < n; i++)
        printf("%d\n", vec[i]);
}

int main() {

    int vec[] = {1, 2, 3, 4};
    scale(vec, 2, 4);
    print_array(vec, 4);

    return 0;
}
