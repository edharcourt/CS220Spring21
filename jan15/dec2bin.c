#include <stdio.h>

void printbin(int n) {

    if (n == 0) {
        printf("0");
    }
    else {
        printbin(n >> 1);
        printf("%d", n & 1);
    }
}

// broken because number comes out backwards
void dec2bin(int n) {

    while (n > 0) {
	printf("%d", n % 2);
        n = n / 2;
    }

    printf("\n");
}

int main() {

    dec2bin(333); // 101001101
    printbin(333);
    return 0;
}
