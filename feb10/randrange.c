#include <stdlib.h>

int randrange(long int x, long int y) {
    return rand() % (y - x) + x;
}
