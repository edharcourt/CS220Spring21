// A big integer library

#include <stdlib.h>  // malloc/free
#include <string.h>
#include <stdio.h>

#include "bigint.h"

BigInt *make_int(const char *x) {
    BigInt *b = malloc(sizeof(BigInt));
    b->n = strlen(x);
    b->ds = malloc(b->n);

    for (int i = 0; i < b->n; i++) 
        b->ds[i] = x[b->n - i - 1] - '0'; 

    return b;
}

// make a BigInt of n zeros
BigInt *make_zero(int n) {
    char tmp[n];
    memset(tmp, '0', n);
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
      byte s = x->ds[i] + y->ds[i] + c;
      r->ds[i] = s % 10;
      c = s / 10;
      i++;
    }

    // copying the rest of the longer number
    while (i < longer->n) {
        byte s = longer->ds[i] + c;
        c = s / 10;
        r->ds[i] = s % 10;
        i++;
    }
         
    r->ds[i] = c;  // don't frget about last carry
    return r;
    
}


void print_int(const BigInt *b) {
    for (int i = b->n - 1; i > -1; i--)
        printf("%hhd", b->ds[i]);
}

void println_int(const BigInt *b) {
    print_int(b);
    printf("\n");
}

