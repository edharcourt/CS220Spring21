#include <stdio.h>
#include <stdlib.h>

extern int find_smallest(int i, int vec[], int n);
extern void sort(int vec[], int n);
extern void print_array(int vec[], int n);

int main(int argc, char *argv[]) {

    //int vec[] = {9, 1, 3, 7, 6, 5, 8, 4};

    //int *vec = malloc((argc - 1) * sizeof(int));
    int vec[argc-1];
    for (int i = 0; i < argc - 1; i++)
        vec[i] = atoi(argv[i+1]);


    print_array(vec, argc - 1);
    sort(vec, argc - 1);
    print_array(vec, argc - 1); 

    //free(vec);

    //printf("%d\n", find_smallest(0, vec, 8) == 1);
    //printf("%d\n", find_smallest(7, vec, 8) == 7);
    //printf("%d\n", find_smallest(2, vec, 8) == 2);
}
