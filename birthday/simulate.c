#include <string.h>
#include <stdlib.h>
#include <time.h>

// Write a function simulate, that takes n, the number of people,
// returns 1 (true) if someone shared a birthday, 0 (false) otherwise.

int simulate(int n, int i) {

    const int DAYS = 366;
    int cal[DAYS];

    memset(cal, 0, DAYS * sizeof(int));

    srand(time(NULL) + i);
    
    for (int i = 0; i < n; i++)
        cal[rand() % DAYS]++; 

    // are there any entries > 1
    for (int i = 0; i < DAYS; i++)
        if (cal[i] > 1)
            return 1; 
         
    return 0;
}
