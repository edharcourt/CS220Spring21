#include <stdio.h>

//extern int max(int,int);
extern int smallest_div(int n);

int main() {
    printf("%d\n", smallest_div(77));
    printf("%d\n", smallest_div(7448759));
    //printf("%d\n", max(4,6));
    //printf("%d\n", max(9,3));
}
