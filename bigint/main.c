#include <stdio.h>

#include "bigint.h"

int main() {

    BigInt *b = make_int("12345678987654321");
    BigInt *c = make_int("111111");

    BigInt *d = make_int10("273625384950684783637854859659696997");

    println_int(add(b,c));
}
