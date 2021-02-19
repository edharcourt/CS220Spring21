.global simulate
/*
int simulate(int n, int i) {

    const int DAYS = 366;
    int cal[DAYS];

    memset(cal, 0, DAYS * sizeof(int));

    srand(time(NULL) + i);

    int j = 0;
    while (j < n) {
        cal[rand() % DAYS]++;
        j++;
    }

    // are there any entries > 1
    j = 0;
    while (j < DAYS) {
        if (cal[j] > 1)
            return 1;
        j++;
    }

    return 0;
}
*/
.cpu cortex-a53
.text
simulate:
    push { r4-r8, r11, lr }
    mov r4, r0    // n is in r4
    mov r5, r1    // i is in r5
    mov r6, #366

    sub sp, sp, r6, lsl #2
    mov r7, sp    // r7 contains the base address of cal
    
    // call memset
    mov r0, r7
    mov r1, #0
    mov r2, r6, lsl #2
    bl memset

    mov r0, #0   // set up call to time
    bl time
    add r0, r0, r5
    bl srand
    
    // fill cal with random birthdays
    mov r8, #0
while1:
    cmp r8, r4     // j < n
    bge endwhile1
    bl rand               // cal[rand() % DAYS]++;
    mov r1, r6
    bl mod
    add r0, r7, r0, lsl #2  // computer address into cal
    ldr r1, [r0]            // read
    add r1, r1, #1          // modify
    str r1, [r0]            // write 
    add r8, r8, #1
    b while1

endwhile1:
    mov r8, #0
while2:
    cmp r8, r6
    bge endwhile2
    add r0, r7, r8, lsl #2   // cal[j]
    ldr r0, [r0]
    cmp r0, #1
    ble endif
    mov r0, #1
    b return
endif:
    add r8, r8, #1
    b while2
endwhile2:
    mov r0, #0
return:
    add sp, sp, r6, lsl #2
    pop { r4-r8, r11, lr }
    bx lr    











