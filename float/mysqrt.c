#include <math.h>
#include <stdio.h>

double mysqrt(double n) {
    double r = n;
    double epsilon = 1e-9;  // .000001
    while (fabs(r*r - n) > epsilon) { 
        r = (r + n/r)/2.0;
    }
    return r;
}
