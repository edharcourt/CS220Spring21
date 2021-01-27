#include <stdio.h>

int main() {

    int x = 7;
    int *px = &x; // & address-of operatoro

    printf("%d %d\n", x, *px);

    printf("%p %p\n", px, &px);

}
