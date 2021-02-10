/*
int dow(int m, int d, int y) {
    int y0 = y - (14 - m) / 12;
    int x = y0 + y0 / 4 - y0 / 100 + y0 / 400;
    int m0 = m + 12 * ((14 - m)/12) - 2;
    int d0 = (d + x + (31 * m0) / 12) % 7;
    return d0;
}
*/

.global dow   // make dow visible outside this file
.cpu cortex-a53  // ARM's application series processor
.text         // text segement (code)

// r0 through r3 contain the first four arguments to the function
// r0 - month
// r1 - day 
// r2 - year
dow:          // label that marks the function and its name

   // save registers we use on the stack sp they can be restored
   // for the caller.
   push { r4, r5, r6, r7, r8, r9, r10 }
   mov r3, #14
   mov r5, #12
   sub r4, r3, r0    // flexible second argument
   sdiv r4, r4, r5   // sdiv does not have a flexible second argument 
   sub r6, r2, r4    // r6 is y0  

   // calculate x
   lsr r7, r6, #2    // y0/4  logical shift right
   mov r9, #100
   sdiv r8, r6, r9   // y0/100
   mov r10, #400
   sdiv r9, r6, r10  // y0/400 don't need r9 any longer
   add r10, r6, r7   // y0 + y0/4  r7 no longer needed
   sub r10, r10, r8  // subtract out y0/100
   add r10, r10, r9  // addin y0/400  

   // calculate m0
   mul r6, r5, r4
   add r6, r0, r6
   sub r6, r6, #2

   // calculate d0
   mov r8, #7           
   mov r9, #31
   mul r9, r9, r6
   sdiv r9, r9, r5
   add r9, r9, r10
   add r9, r1, r9    

   // compute r9 % 7
   sdiv r1, r9, r8
   mul r1, r1, r8
   sub r0, r9, r1   // almost done! 

   // restore r4 - r10 to their original value
   pop { r4-r10 }
   bx lr   // identical to bx lr
