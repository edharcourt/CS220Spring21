.global ipow

/*
int ipow(int x, int y) {

    int r = 1;

    while (y > 0) {
        r = r * x;
        y--;
    }

    return r;
}
*/
.text
ipow:
    nop
    mov r2, #1   // r = 1
while:
    cmp r1, #0
    ble endwhile
    mul r2, r2, r0   // r = r * x 
    sub r1, r1, #1 
    b while
endwhile:
    mov r0, r2
    bx lr
