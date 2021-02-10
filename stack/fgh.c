#include <stdio.h>
#include <stdlib.h>

int h(int x) {
    int y = 3;
    return x*y;
}

int g(int z) { 
    return h(z+z);
}

int f(int w) { 
    int x = rand() % 5;
    return g(x) + g(w); 
}

int main() {
    printf("%d\n", f(11));
    return 0;
}
