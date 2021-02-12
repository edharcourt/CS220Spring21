#include<stdio.h>

extern int find_smallest(int i, int vec[], int n);
extern void sort(int vec[], int n);
extern void print_array(int vec[], int n);

int main() {

    int vec[] = {9, 1, 3, 7, 6, 5, 8, 4};

    print_array(vec, 8);
    sort(vec, 8);
    print_array(vec, 8); 

    //printf("%d\n", find_smallest(0, vec, 8) == 1);
    //printf("%d\n", find_smallest(7, vec, 8) == 7);
    //printf("%d\n", find_smallest(2, vec, 8) == 2);
}
