

max:
    mov r2, r1  // r = b
    cmp r0, r1
    ble endif
    mov r2, r0
endif:
    mov r0, r2
    bx lr
