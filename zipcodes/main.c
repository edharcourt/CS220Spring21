
#include <stdio.h>

int main() {

    char code[6], state[3], city[100];
    double lat, lon;

    FILE *f = fopen("../../CS220_data/zips.csv", "r");
    int lc = 0;
    
    while (1) {
        int x = fscanf(f, "%5s,%2s,%[^,],%lf,%lf", code, state, city, 
		       &lat, &lon);
	if (x == EOF) 
	    break;	
	lc++;
    }
    //printf("%s %s %s %g %g\n", code, state, city, lat, lon);
    printf("Line count: %d\n", lc); 

}
