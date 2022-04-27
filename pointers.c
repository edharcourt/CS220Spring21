#include <stdio.h>

int main() {

    int x = 7;
    int *p = &x; // & address-of operatoro

    printf("%d %d\n", x, *p);

    printf("%p %p\n", px, &p);

    p = x;
    x = p;
    //&x = 88;
    *p = 33;
    x = 23;
    p = NULL;
}
