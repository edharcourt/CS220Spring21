#include <stdio.h>

#include "bigint.h"

extern void f();

int main() {

    BigInt *b = make_int("12345678987654321");
    BigInt *c = make_int("111111");

    println_int(add(b,c));
}
