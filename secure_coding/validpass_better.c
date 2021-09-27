#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <termios.h>
#include "sha256.h"

// Compile line 
//  gcc -o vp validpass_better.c -lsha256 -lcrypto -L.

#define MAX_PWD_LEN 12

void echo(int flag) {
    struct termios termInfo, save;
    int c = tcgetattr(0,&termInfo);

    if (c == -1) {
        perror("tcgetattr");
        exit(0);
    }

    if (flag) {
        termInfo.c_lflag |= ECHO;
    }
    else {
        termInfo.c_lflag &= ~ECHO;
    }    

    c = tcsetattr(0,TCSANOW, &termInfo);

    if (c == -1) {
        perror("tcsetattr");
        exit(0);
    }
}

// return true if the user entered the magic password
// false otherwise
// https://passwordrecovery.io/sha256/
// sha256("caddyshack") == 3e711846f05d70a6fe5c0ed0a81449c65f27493ff1270ab37b3b841292f4fdd0
int valid() {

    char password[MAX_PWD_LEN];

    // if you esnt to echo '*' on input then you need to read a character
    // at a time and manually print an '*' for each character read.
    echo(0);
    if (NULL == fgets(password, MAX_PWD_LEN, stdin)) {
        return 0;
    }
    echo(1);

    //*((int *) &password[16]) = 0x103c0; 

    // replace newline with null byte?
    password[strlen(password)-1] = '\0';
    char buff[65];
    return 0 == strcmp(sha256(password, buff), "3e711846f05d70a6fe5c0ed0a81449c65f27493ff1270ab37b3b841292f4fdd0");
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

