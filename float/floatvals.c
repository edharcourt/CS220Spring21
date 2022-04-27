#include <math.h>
#include <stdio.h>

int main() {
    float x = 0.0/0.0;
    float y = 3.14159/0.0;
    float z = sqrt(-1.0); 
    int d = 0x00000001;
    float *df = (float *) &d;
    printf("%f %f %f %f %d\n", x, y, -y, z, isnormal(*df));  // nan inf -inf nan
}
