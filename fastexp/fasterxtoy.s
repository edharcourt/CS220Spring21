.global xtoy

/*
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

*/

.text 
xtoy:
    mov r2, r0   // currsqr
    mov r3, #1   // return val
    push { r4} 

while:
    cmp r1, #0
    ble endwhile
    and r4, r1, #1
    cmp r4, #0
    beq endif
    mul r3, r3, r2     
endif:
    mul r2, r2, r2
    lsr r1, r1, #1
    b while
endwhile:
    mov r0, r3
    pop { r4 }
    bx lr 
    
