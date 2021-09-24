#include <stdio.h>

int main() {

    char last[20];
    char first[20];

    printf("Enter name: ");
    scanf("%[^,],%s", last, first); 
    printf("First name is %s\n", first);
    printf("Last name is %s\n", last);

}
