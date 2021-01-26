#include <stdio.h>
#include <string.h>

int main() {

    char input[100];
    char smallest[100];
    memset(smallest, 0xFF, 100);

    while (1) {
        int rc = scanf("%s", input);
        if (rc == EOF) 
            break;

        if (strcmp(input,smallest) < 0) {
           strcpy(smallest,input);
        }
    }

    printf("Smallest = %s\n", smallest);

}
