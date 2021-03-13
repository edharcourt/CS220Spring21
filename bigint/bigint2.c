// A big integer library

#include <stdlib.h>  // malloc/free
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "bigint.h"

// precondition: x is valid hex character
int hexval(char x) {
    if ('0' <= x && x <= '9')
        return x - '0';
    else if ('A' <= x && x <= 'F')
        return x - 'A' + 10;
    else if ('a' <= x && x <= 'f')  // 'a' <= x <= 'f'
        return x - 'a' + 10;
    else
        return 0; // error in hex string
}

// make_int("F1D7")
// make_int("F1D")
BigInt *make_int(const char *x) {
    BigInt *b = malloc(sizeof(BigInt));
    int lenx = strlen(x);  // length of the hex string
    b->n = ceil(strlen(x)/2.0);
    b->ds = malloc(b->n);

    for (int i = 0; i < lenx; i += 2) { 
        b->ds[i/2] = hexval(x[lenx - i - 1]); 

        // guard against out of bounds on odd length strings
        if (lenx - i - 2 >= 0)
            b->ds[i/2] |= (hexval(x[lenx - i - 2]) << 4);
    }

    return b;
}

// make a BigInt, n is size of array
BigInt *make_zero(int n) {
    char tmp[2*n + 1];
    memset(tmp, '0', 2*n);
    tmp[2*n] = 0;
    return make_int(tmp);
}

// add two bigints
BigInt *add(const BigInt *x, const BigInt *y) {
    
    const BigInt *longer, *shorter;

    if (x->n > y->n) {
        longer = x;
        shorter = y;
    }
    else {
        longer = y;
        shorter = x;
    }

    BigInt *r = make_zero(longer->n + 1); 
    int c = 0; // carry
    int i = 0;
    while (i < shorter->n) {
      uint16_t s = x->ds[i] + y->ds[i] + c;
      r->ds[i] = s & 0xFF;  // % 256
      c = s >> 8;
      i++;
    }

    // copying the rest of the longer number
    while (i < longer->n) {
        uint16_t s = longer->ds[i] + c;
        c = s >> 8;
        r->ds[i] = s & 0xFF;
        i++;
    }
         
    r->ds[i] = c;  // don't forget about last carry
    return r;
    
}


void print_int(const BigInt *b) {
    for (int i = b->n - 1; i > -1; i--)
        printf("%02hhx", b->ds[i]);
}

void println_int(const BigInt *b) {
    print_int(b);
    printf("\n");
}

