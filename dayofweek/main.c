#include <stdio.h>
#include <stdlib.h>

// m - month
// y - year
// d - day

// function prototype. 
extern int dow(int m, int d, int y);

int main(int argc, char *argv[]) {
    
    if (argc < 4) {
        printf("usage: dow month day year\n");
        return 1;
    }

    int m = atoi(argv[1]);
    int d = atoi(argv[2]);
    int y = atoi(argv[3]);
    int day = dow(m,d,y);

    char *days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", 
                     "Thursday", "Friday", "Saturday"};

    printf("%s\n", days[day]);
}
