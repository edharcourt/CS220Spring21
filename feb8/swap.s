.global swap

/*
void swap(int vec[], int i, int j) {
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

*/
.text
swap:
    lsl r1, r1, #2   // multiply i by 4
    add r1, r0, r1   // vec + i*4 
    ldr r3, [r1]     // tmp = vec[i] r1 is the address of vec[i]
    
    lsl r2, r2, #2   // multiply j by 4
    add r2, r0, r2   // r2 is the address of vec[j]
    ldr r4, [r2]     // r4 = vec[j]
    str r4, [r1]     // vec[i] = r4 
    str r3, [r2]     // vec[j] = r3 
    bx lr
