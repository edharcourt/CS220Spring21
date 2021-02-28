
int xtoy(int x, int y) {
    int currsqr = x;
    int rv = 1;

    while (y > 0) {
        if (y & 1)
            rv *= currsqr;

        currsqr *= currsqr;
        y >>= 1;
    }
    return rv;
}
