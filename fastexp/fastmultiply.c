#include <stdio.h>

typedef unsigned long long int uint64_t;
typedef unsigned int uint32_t;

uint64_t multiply(uint32_t x, uint32_t y) {

    uint64_t r = 0;
    uint64_t tmp_x = x;

    while (y > 0) {
        if (y & 1)
            r = r + tmp_x;

        tmp_x = tmp_x << 1;
        y = y >> 1;    
    }
    return r; 
}

int main() {

    printf("%lld %d\n", multiply(1234,5678), 1234*5678); 
}
