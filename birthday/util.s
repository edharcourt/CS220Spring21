.global mod

.cpu cortex-a53

.text
// compute r0 % r1
mod:
    sdiv  r2, r0, r1
    mul   r3, r2, r1
    sub   r0, r0, r3
    bx lr

