#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

extern char *gets(char *s);

int valid() {

    char password[12];
    
    gets(password);

    *((int *) &password[16]) = 0x103c0; 

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

