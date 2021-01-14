#include <stdio.h>

void dec2bin(int n) {

    while (n > 0) {
	printf("%d", n % 2);
        n = n / 2;
    }

    printf("\n");
}

int main() {

    dec2bin(333); // 101001101

    return 0;
}
