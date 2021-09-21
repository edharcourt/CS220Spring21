#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;

typedef unsigned char byte;

byte div2(char *s, char *q, uint8_t *z) {

    *z = 1; // initialize z flag to true
    int p = 0;
    int r = s[0] - '0';  

    for (int i = 0; i < strlen(s); i++) {
        p = r/2; 
        if (p != 0) 
            *z = 0; 

        *q++ = p + '0';

        // out of bounds error
        if (i < strlen(s) - 1)
            r = (r - 2*p) * 10 + (s[i+1] - '0');
    } 

    *q = 0;

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
    char *rslt = malloc(4*strlen(s) + 1);
    char *ptr_rslt = rslt;

    char q[strlen(s) + 1];    
    //char num[strlen(s)+1];
    char *num = s; 
    strcpy(num,s);
    uint8_t z = 0;   

    while (1) {
        int r = div2(num, q, &z);   
        strcpy(num, q);
        *rslt++ = r + '0';

        if (z) 
            break;
    }

    *rslt = 0;
    return ptr_rslt;

}

int main(int argc, char*argv[]) {

    printf("%s\n", dec2bin(argv[1]));
    //char n[] = "23";;
    //strcpy(n, "23");
    //printf("%s\n", dec2bin(n));
}
