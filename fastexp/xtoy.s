.global xtoy

/*
int xtoy(int x, int y) {
   if (y == 0)
       return 1;
   else
       return x * xtoy(x, y - 1);
}
*/
.text
xtoy:
    push { r4, r5, lr }
    mov r4, r0   // r4 is x
    mov r5, r1   // r5 is y

    cmp r5, #0
    bne else
    mov r0, #1
    b return
else: 
    mov r0, r4       // put x in to r0
    sub r1, r5, #1   // put y-1 in to r1
    bl xtoy
    mul r0, r4, r0
return:
    pop { r4, r5, lr }
    bx lr
