#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

/*
 * 1) buffer problem
 * 2) cleartext password in code
 * 3) characters echoed at console
 * 
 */

extern char *gets(char *s);

int valid() {

    char password[12];
    
    gets(password);

    //*((int *) &password[16]) = 0x103c0; 

    return 0 == strcmp(password, "goodpass");
}

int main(void) {

    int status;
    puts("Enter password:");

    status = valid();
    
    if (!status) {
        puts("Access denied");    
        exit(-1);
    }
    else {
        puts("Logged on");    
    }    
}

