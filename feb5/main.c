#include <stdio.h>

//extern int ipow(int, int);
extern int between(int x, int y, int z);

int main() {
     //printf("%d\n", ipow(2,11));
     printf("%d\n", between(2,11,50)); // print 1
     printf("%d\n", between(2,2,50));  // boundary case 
     printf("%d\n", between(2,50,50));  // boundary case 
}
