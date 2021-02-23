
int xtoy(int x, int y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 1)
        return x * xtoy(x, y - 1);
    else {
        int tmp = xtoy(x, y/2);
        return tmp * tmp;
    }
}
        
