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

        // q = q + chr(p + ord('0'))
        *q++ = p + '0';

        // out of bounds error
        if (i < strlen(s) - 1)
            r = (r - 2*p) * 10 + (s[i+1] - '0');
    } 

    *q = 0;  // null terminate!!!!!!!!!
    r = r - 2*p;
    return r;
}


// reverse in place without using more memory
char *reverse(char *s) {

    int n = strlen(s);

    for (int i = 0; i < n/2; i++) {
        char tmp = s[i];
        s[i] = s[n - i - 1]; 
        s[n - i - 1] = tmp; 
    }

    return s;
}

// caller should free result when done with it
// s is modified if passed a constant wil crash
// make a copy of s
char *dec2bin(char *s) {
    char * rslt = malloc(4*strlen(s) + 1);
    char * beg_rslt = rslt;  // keep a pointer to the beginning
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
    return reverse(beg_rslt);
}

int main(int argc, char *argv[]) {
    printf("%s\n", dec2bin(argv[1]));
}
