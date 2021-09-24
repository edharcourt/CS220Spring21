/*
 * 35004,AL,ACMAR,86.51557,33.584132
 */

#include <stdio.h>

int main() {

    FILE *f = fopen("../../CS220_data/zips.csv", "r");

    char code[6], state[3], city[30];
    double lat, lon;

    fscanf(f, "%5s,%2s,%[^,],%lf,%lf", code, state, city, &lat, &lon);

    printf("zip = %s\n", code);
    printf("state = %s\n", state);
    printf("city = %s\n", city);
    printf("latitude = %lf\n", lat);
    printf("longitude = %lf\n", lon);

}
