#include <stdio.h>

void avg_sum(double a[], int n, double *avg, double *sum) {
    *sum = 0.0;
    for (int i = 0; i < n; i++)
        *sum += a[i];
    *avg = *sum / n;
}

int main() {
    double grades[] = {98.2, 78.9, 99.0, 83.6};
    double mean, total;
    avg_sum(grades, 4, &mean, &total);
    printf("mean = %lf, sum = %lf\n", mean, total);
}

int main() {
    double grades[] = {98.2, 78.9, 99.0, 83.6};
    double *mean, *total, m, t;
    mean =  &m;
    total = &t;
    avg_sum(grades, 4, mean, total);
    printf("mean = %lf, sum = %lf\n", *mean, *total);
}


