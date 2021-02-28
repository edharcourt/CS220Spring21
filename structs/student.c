#include <stdio.h>

typedef struct {

    char *first, *last;
    int grades[5];

} Student;

int main() {

    Student roster[10];

    roster[0].first = "Harry";
    roster[0].last = "Potter";
    roster[0].grades[0] = 80; 
    roster[0].grades[1] = 90; 
    roster[0].grades[2] = 80; 
    roster[0].grades[3] = 80; 
    roster[0].grades[4] = 80; 
    
}
