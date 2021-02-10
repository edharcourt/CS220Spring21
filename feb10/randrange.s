.global randrange
.cpu cortex-a53

/**
 * Generate a random integer in [x,y)
 * precond: x < y
int randrange_c(long int x, long int y) {
   	return rand() % (y - x) + x;
}
*/

mod:
    sdiv  r2, r0, r1
    mul   r3, r2, r1
    sub   r0, r0, r3
    bx lr
    
randrange:
    push { r4, r5, lr }
    mov r4, r0  // save x
    mov r5, r1  // save y
    
    bl rand
    sub r1, r5, r4  // r1 = y - x
    bl mod          // rand() % (y - x)
    add r0, r0, r4
    
    pop { r4, r5, lr }
    bx lr

