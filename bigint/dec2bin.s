	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"dec2bin.c"
	.text
	.align	2
	.global	div2
	.arch armv6
	.syntax unified
	.arm
	.fpu vfp
	.type	div2, %function
div2:
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #32
	str	r0, [fp, #-24]
	str	r1, [fp, #-28]
	str	r2, [fp, #-32]
	ldr	r3, [fp, #-32]
	mov	r2, #1
	strb	r2, [r3]
	mov	r3, #0
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-24]
	ldrb	r3, [r3]	@ zero_extendqisi2
	sub	r3, r3, #48
	str	r3, [fp, #-12]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L2
.L5:
	ldr	r3, [fp, #-12]
	lsr	r2, r3, #31
	add	r3, r2, r3
	asr	r3, r3, #1
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	beq	.L3
	ldr	r3, [fp, #-32]
	mov	r2, #0
	strb	r2, [r3]
.L3:
	ldr	r3, [fp, #-8]
	uxtb	r2, r3
	ldr	r3, [fp, #-28]
	add	r1, r3, #1
	str	r1, [fp, #-28]
	add	r2, r2, #48
	uxtb	r2, r2
	strb	r2, [r3]
	ldr	r0, [fp, #-24]
	bl	strlen
	mov	r3, r0
	sub	r2, r3, #1
	ldr	r3, [fp, #-16]
	cmp	r2, r3
	bls	.L4
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #1
	ldr	r2, [fp, #-12]
	sub	r2, r2, r3
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #1
	mov	r1, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	ldr	r2, [fp, #-24]
	add	r3, r2, r3
	ldrb	r3, [r3]	@ zero_extendqisi2
	sub	r3, r3, #48
	add	r3, r1, r3
	str	r3, [fp, #-12]
.L4:
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L2:
	ldr	r0, [fp, #-24]
	bl	strlen
	mov	r2, r0
	ldr	r3, [fp, #-16]
	cmp	r2, r3
	bhi	.L5
	ldr	r3, [fp, #-28]
	mov	r2, #0
	strb	r2, [r3]
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #1
	ldr	r2, [fp, #-12]
	sub	r3, r2, r3
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-12]
	uxtb	r3, r3
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
	.size	div2, .-div2
	.align	2
	.global	reverse
	.syntax unified
	.arm
	.fpu vfp
	.type	reverse, %function
reverse:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	str	r0, [fp, #-24]
	ldr	r0, [fp, #-24]
	bl	strlen
	mov	r3, r0
	str	r3, [fp, #-12]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L8
.L9:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-24]
	add	r3, r2, r3
	ldrb	r3, [r3]
	strb	r3, [fp, #-13]
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-8]
	sub	r3, r2, r3
	sub	r3, r3, #1
	ldr	r2, [fp, #-24]
	add	r2, r2, r3
	ldr	r3, [fp, #-8]
	ldr	r1, [fp, #-24]
	add	r3, r1, r3
	ldrb	r2, [r2]	@ zero_extendqisi2
	strb	r2, [r3]
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-8]
	sub	r3, r2, r3
	sub	r3, r3, #1
	ldr	r2, [fp, #-24]
	add	r3, r2, r3
	ldrb	r2, [fp, #-13]
	strb	r2, [r3]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L8:
	ldr	r3, [fp, #-12]
	lsr	r2, r3, #31
	add	r3, r2, r3
	asr	r3, r3, #1
	mov	r2, r3
	ldr	r3, [fp, #-8]
	cmp	r3, r2
	blt	.L9
	ldr	r3, [fp, #-24]
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
	.size	reverse, .-reverse
	.align	2
	.global	dec2bin
	.syntax unified
	.arm
	.fpu vfp
	.type	dec2bin, %function
dec2bin:
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, fp, lr}
	add	fp, sp, #8
	sub	sp, sp, #36
	str	r0, [fp, #-40]
	mov	r3, sp
	mov	r4, r3
	ldr	r0, [fp, #-40]
	bl	strlen
	mov	r3, r0
	lsl	r3, r3, #2
	add	r3, r3, #1
	mov	r0, r3
	bl	malloc
	mov	r3, r0
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-16]
	str	r3, [fp, #-20]
	ldr	r0, [fp, #-40]
	bl	strlen
	mov	r3, r0
	add	ip, r3, #1
	mov	r3, ip
	sub	r3, r3, #1
	str	r3, [fp, #-24]
	mov	r0, ip
	mov	r1, #0
	mov	r2, #0
	mov	r3, #0
	lsl	r3, r1, #3
	orr	r3, r3, r0, lsr #29
	lsl	r2, r0, #3
	mov	r0, ip
	mov	r1, #0
	mov	r2, #0
	mov	r3, #0
	lsl	r3, r1, #3
	orr	r3, r3, r0, lsr #29
	lsl	r2, r0, #3
	add	r3, ip, #7
	lsr	r3, r3, #3
	lsl	r3, r3, #3
	sub	sp, sp, r3
	mov	r3, sp
	add	r3, r3, #0
	str	r3, [fp, #-28]
	mov	r3, #0
	strb	r3, [fp, #-33]
.L14:
	ldr	r3, [fp, #-28]
	sub	r2, fp, #33
	mov	r1, r3
	ldr	r0, [fp, #-40]
	bl	div2
	mov	r3, r0
	str	r3, [fp, #-32]
	ldr	r3, [fp, #-28]
	mov	r1, r3
	ldr	r0, [fp, #-40]
	bl	strcpy
	ldr	r3, [fp, #-32]
	uxtb	r2, r3
	ldr	r3, [fp, #-16]
	add	r1, r3, #1
	str	r1, [fp, #-16]
	add	r2, r2, #48
	uxtb	r2, r2
	strb	r2, [r3]
	ldrb	r3, [fp, #-33]	@ zero_extendqisi2
	cmp	r3, #0
	bne	.L17
	b	.L14
.L17:
	nop
	ldr	r3, [fp, #-16]
	mov	r2, #0
	strb	r2, [r3]
	ldr	r0, [fp, #-20]
	bl	reverse
	mov	r3, r0
	mov	sp, r4
	mov	r0, r3
	sub	sp, fp, #8
	@ sp needed
	pop	{r4, fp, pc}
	.size	dec2bin, .-dec2bin
	.section	.rodata
	.align	2
.LC0:
	.ascii	"23\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r0, .L20
	bl	dec2bin
	mov	r3, r0
	mov	r0, r3
	bl	puts
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L21:
	.align	2
.L20:
	.word	.LC0
	.size	main, .-main
	.ident	"GCC: (Raspbian 8.3.0-6+rpi1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
