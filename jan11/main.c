#include <stdio.h>

// Declare that countd is external to this file
extern int countd(int n, int digit);

int main() {
    int d, digit;
    printf("Enter an integer:");
    scanf("%d", &d); // & address-of 
    printf("Enter digit:");
    scanf("%d", &digit);
    printf("The number of %d in %d is %d \n", digit, d, countd(d,digit));
}
