.global scale
/*
void scale(int *vec, int s, int n) {
    int i = 0;
    while (i < n) {
        vec[i] = vec[i] * s;
        i++;
    }
}
*/
.text
scale:
    mov r3, #0

while:
    cmp r3, r2
    bge endwhile
    // vec + i*4   r0 + (r3 << 2)    
    lsl r4, r3, #2 // r4 is the offset into the array   
    add r4, r0, r4 // address of element i
    ldr r5, [r4]   // vec[i]
    mul r5, r5, r1
    str r5, [r4]
    add r3, r3, #1
    b while 

endwhile:
    bx lr
