#include <stdio.h>
#include <string.h>

int main() {

    char *s = "Hello";
    char t[] = "World";

    printf("s = %s t = %s\n", s, t);

    for (int i = 0; i < strlen(s); i++) {
        printf("%c %d\n", s[i], s[i]);
    }
}
