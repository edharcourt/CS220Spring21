
int smallest_div_c(int n) {

    int d = 2;

    while (n % d != 0)
        d = d + 1;

    return d;
}
