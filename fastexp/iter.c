int xtoy(int x, int y) {
   int rv = 1;
   int curr_pow = x;

   while (y > 0) {
       if (y & 0x1)
           rv = rv * curr_pow;
       y = y >> 1;
       curr_pow = curr_pow * curr_pow;   
   }
   return rv;
}
