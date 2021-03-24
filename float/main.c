#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern double mysqrt(double);

int main(int argc, char *argv[]) {
    printf("%.9f %.9f\n", mysqrt(atof(argv[1])), 
                          sqrt(atof(argv[1])));
}
