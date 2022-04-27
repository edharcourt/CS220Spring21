.global f2c, f3c
.arm
.arch armv6
.fpu vfp
.cpu cortex-a53
.syntax unified

.text

.align 2

f2c:
    ldr r0, =five      // load the address of 5.0
    vldr.f64 d1, [r0]
    
    ldr r0, =nine      // load the address of 9.0
    vldr.f64 d2, [r0]
    
    vdiv.f64 d1, d1, d2  // 5/9
    
    ldr r0, =thirtytwo  // load the address of 32.0
    vldr.f64 d2, [r0]
    
    vsub.f64 d0, d0, d2   // f - 32
    vmul.f64 d0, d1, d0
    bx lr

.align 3
.data
five: .double 5.0
nine: .double 9.0
thirtytwo: .double 32.0

