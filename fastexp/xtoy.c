
/*
 *   y         y - 1
 * X   =  X * X
 *
 *
 *  x**y = x * x**(y-1)
 *
 * precondition: y >= 0
 */
int xtoy(int x, int y) {
   if (y == 0)
       return 1;
   else
       return x * xtoy(x, y - 1);
}    

