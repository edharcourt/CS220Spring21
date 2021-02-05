/*
    Compute x raised to the y power where 
    x and y are integers and y is non-negtive
*/

int ipow(int x, int y) {

    int r = 1;

    while (y > 0) {
        r = r * x;
        y--;
    }

    return r;
}
