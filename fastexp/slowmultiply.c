
int multiply(int x, int y) {
    int s = 0;

    while (y > 0) {
        s = s + x;
        y--;
    }
    return s;
}
