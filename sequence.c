#include <stdio.h>

int sequence(int x) {
    int len = 0;
    long long int n = x;

    while (n != 1) {
        if (n & 1)
            n = 3 * n + 1;
        else
            n = n >> 1;
        len++;
    }

    return len + 1;
}

int longest() {
    int longest = 0;
    int longest_n = 1;

    for (int i = 1; i < 1000000; i++) {
        int x = sequence(i);
        if (x > longest) {
            longest = x;
            longest_n = i; 
        }
    }

    return longest_n;
}

int main() {
    printf("%d\n", longest());
    printf("%d\n", sequence(837799));
}