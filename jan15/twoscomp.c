#include <stdio.h>

int main() {

    int x = 7; // 0b00000000000000000000000000000111
    int y = 0b111;

    printf("%d\n", ~x + 1);

    signed char z = 127;
    z = z + 1; // overflow
    printf("%d\n", z);

    int a = 0b01111111111111111111111111111111;
    printf("%d %d\n", a, a + 1);
}
