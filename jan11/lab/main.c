#include <stdio.h>

extern int checksum(int n);

int main() {

    int x;

    while (1) {
       printf("Enter an integer: ");
       scanf("%d", &x);
       if (x == -1)
           break;
       printf("The checksum of %d is %d\n", x, checksum(x));
    }
}
