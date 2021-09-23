#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <termios.h>

#define MAX_PWD_LEN 12
extern char *gets(char *s);

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

    password[strlen(password)-1] = '\0';
    return 0 == strcmp(password, "caddyshack");
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

