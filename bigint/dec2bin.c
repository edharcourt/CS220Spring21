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

        // out of bounds error
        if (i < strlen(s) - 1)
            r = (r - 2*p) * 10 + (s[i+1] - '0');
    } 

    r = r - 2*p;
    return r;
}

/* 
def dec2bin(q: str) -> str:
    digs = ""

    while True:
        (q, r, z) = div2(q)
        digs = chr(r + ord('0')) + digs  # str(r)

        # check if quotient is all zeros
        if z:
            break

    return digs

*/
// caller should free result when done with it
char *dec2bin(char *s) {
    char * rslt = malloc(4*strlen(s) + 1);
    char q[strlen(s) + 1];    
    uint8_t z = 0;   

    while (1) {
        int r = div2(s, q, &z);   
        strcpy(s, q);
        *rslt++ = r + '0';

        if (z) 
            break;
    }

    *rslt = 0;
    return rslt;

}

