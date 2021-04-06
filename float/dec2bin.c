#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
     float x = atof(argv[1]);

     int *y = (int *) &x;  // pure evil    

     printf("%x\n", *y);

}
