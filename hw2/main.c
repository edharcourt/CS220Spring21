#include <stdio.h>

int unique_region(int arr[], int n) {
        return -1;
}

int main() {

    int test1[] = {1, 1, 1, 1, 1, 1};
    printf("%d\n", unique_region(test1, 6) == 1);

    int test2[] = {1, 1, 2, 3, 4, 5, 3};
    printf("%d\n", unique_region(test2, 7) == 5);

    int test3[] = {129, 990000000, 12345, 99};
    printf("%d\n", unique_region(test3, 4) == 4);
}
