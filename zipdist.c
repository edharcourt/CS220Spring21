#include <stdio.h>
#include <string.h>
#include <math.h>

double to_radians(double degrees) {
    return degrees*M_PI/180.0;
}

// https://nathanrooy.github.io/posts/2016-09-07/haversine-with-python/
double distance(double lat1, double lon1,
                double lat2, double lon2) {

    double phi1 = to_radians(lat1);
    double phi2 = to_radians(lat2);
    double delta_phi = to_radians(lat2 - lat1);
    double delta_gamma = to_radians(lon2 - lon1);
 
    double x = pow(sin(delta_phi / 2), 2) + 
               cos(phi1) * cos(phi2) *
               pow(sin(delta_gamma / 2), 2);

    double y = 2 * atan2(sqrt(x), sqrt(1-x)); 

    double R = 3958.8; // miles
    
    return R * y;

}

// TODO break up main
int main(int argc, char *argv[]) {
    // Debug
    // printf("%d %s %s %s\n", argc, argv[0], argv[1], argv[2]);
    
    // Information for each zipcode
    char state1[3], state2[3], city1[30], city2[30];
    double lat1, lon1, lat2, lon2;

    // temp variables for reading
    char code[6], tstate[3], tcity[30];
    double tlat, tlon;

    // What can go wrong?
    FILE *f = fopen("zips.csv", "r");
 
    if (f == NULL) {
        printf("Error: could not open zips.csv\n");
        return 1;
    }

    int got = 0; // number of zipcodes found
    
    // TODO Add logi to quit at end of file
    while (got != 2) {

        // What can go wrong?  Poorly formatted file
        int eof = fscanf(f, "%5s,%2s,%[^,],%lf,%lf",
		   code, tstate, tcity, &tlat, &tlon);

        if (eof == EOF) 
            break;
            
        // TODO DRY - don't repeat yourself
        // Refactoring 
        if (strcmp(argv[1],code) == 0) {
            strcpy(state1, tstate);  
            strcpy(city1, tcity);  
            lat1 = tlat;
            lon1 = tlon;
            got++;
        }	

        if (strcmp(argv[2],code) == 0) {
            strcpy(state2, tstate);  
            strcpy(city2, tcity);  
            lat2 = tlat;
            lon2 = tlon;
            got++;
        }	
    } // while

    printf("%s %s, %s, (Latitude) %lf, (Longitude) %lf\n", 
            argv[1], city1, state1, lat1, lon1);  
    printf("%s %s, %s, (Latitude) %lf, (Longitude) %lf\n", 
            argv[2], city2, state2, lat2, lon2);  

    double d = distance(lat1, lon1, lat2, lon2);
    printf("The distance between %s, %s and %s, %s, is %.1lf miles.\n", 
            city1, state1, city2, state2, d);

} // main
