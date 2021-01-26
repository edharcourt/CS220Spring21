#include <stdio.h>
#include <string.h>

int main() {

    char input[100];
    char *smallest = NULL;

    while (1) {
        int rc = scanf("%s", input);
        if (rc == EOF) 
            break;

        if (smallest == NULL || (strcmp(input,smallest) < 0)) {
            smallest = input;
        }
    }

    printf("Smallest = %s\n", smallest);

}
