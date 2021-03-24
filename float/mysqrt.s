.global mysqrt
/*
double mysqrt(double n) {
    double r = n;
    double epsilon = 1e-9;  // .000001
    while (fabs(r*r - n) > epsilon) {
        r = (r + n/r)/2.0;
    }
    return r;
}
*/

.align 3
.data
epsilon: .double 1e-9
two: .double 2.0 

.align 2  // instruction on 4 byte boundary
.text 
.fpu vfp
.cpu cortex-a53

mysqrt:
    push { r11, lr }
    vpush { d8, d9, d10, d11 }     // save d11 
    vmov.f64 d11, d0
    ldr r0, =epsilon   // put the address of the constant in r0
    vldr.f64 d9, [r0]
    vmov.f64 d8, d0    // r = n
    ldr r0, =two
    vldr.f64 d10, [r0]  // d10 = 2.0 
while:
    vmul.f64 d0, d8, d8  // r*r
    vsub.f64 d0, d0, d11   // r*r - n
    bl fabs
    vcmp.f64 d0, d9
    vmrs APSR_nzvc, FPSCR  // move the result of the compare into 
                           // the floating-point comparison flags
     
    ble endwhile
    vdiv.f64 d0, d11, d8   // n/r 
    vadd.f64 d0, d0, d8
    vdiv.f64 d8, d0, d10
    b while

endwhile:
    vmov.f64 d0, d8    // return result
    vpop { d8, d9, d10, d11 }
    pop { r11, lr }
    bx lr
    
