// smallest_div.s 

.global smallest_div
.cpu cortex-a53  // needed to use division
.text

smallest_div:
    // x is r0, y is r1
    mov r1, #2

beginwhile:
    sdiv r3, r0, r1    // q = x/y
    mul r4, r3, r1     // r4 = qy
    sub  r5, r0, r4    // r = x - qy
    cmp r5, #0
    beq endwhile
    add r1, r1, #1
    b beginwhile 
endwhile:
    mov r0, r1
    bx lr
