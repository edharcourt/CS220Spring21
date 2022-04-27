
int xtoy(int x, int y) {
    if (y == 0)
        return 1;
    else if (y == 1)
        return x;
    else if (y == 2) 
        return x * x;
    else if (y % 2 == 0)
        return xtoy(xtoy(x, y / 2), 2);
    else 
        return x * xtoy(x, y - 1);
}
        
