.global sqr  // .global is an assembler directive

.text        // the text segment (code)

sqr:         // r0 ia the first argument
    mul r0, r0, r0       // r0 is also the return value
    bx lr    // bx - branch and exchange, lr - link register
