#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
def dec2bin(f: float) -> str:

    r = ""

    for i in range(64):
        f = 2*f
        if f >= 1.0:
            r = r + '1'
            f = f - 1
        else:
            r = r + '0'

    return r
*/

char *dec2bin(double f) {
    char *r = (char *) malloc(100);
    memset(r, 0, 100);

    for (int i = 0; i < 99; i++) {
        f = 2*f;
        if (f >= 1.0) {
            strncat(r,"1",100);             
            f = f - 1.0;
        }
        else {
            strncat(r, "0", 100);
       }
        
       if (f == 0) 
           break;
    }
    return r;
}

int main(int argc, char *argv[]) {
    
     //float x = atof(argv[1]);

     //int *y = (int *) &x;  // pure evil    

     //printf("%x\n", *y);

     printf("%s\n", dec2bin(atof(argv[1])));
}
