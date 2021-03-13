#include <string.h>

typedef unsigned char byte;

byte div2(char *s, char *q, int *z) {

    *z = 1; // initialize z flag to true
    int p = 0;
    int r = s[0] - '0';  

    for (int i = 0; i < strlen(s); i++) {
        p = r/2; 
        if (p != 0) 
            *z = 0; 

        // q = q + chr(p + ord('0'))
        *q++ = p + '0';
    } 

}
