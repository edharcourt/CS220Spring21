	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"dec2bin_finished.c"
	.text
	.align	2
	.global	div2
	.arch armv6
	.syntax unified
	.arm
	.fpu vfp
	.type	div2, %function
div2:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r3, r4, r5, r6, r7, r8, r9, r10, fp, lr}
	mov	r3, #1
	strb	r3, [r2]
	mov	r6, r2
	ldrb	r4, [r0]	@ zero_extendqisi2
	mov	r5, r0
	mov	r9, r1
	bl	strlen
	sub	r4, r4, #48
	cmp	r0, #0
	beq	.L6
	mov	r10, #0
	mov	r8, r10
	add	r7, r5, #1
.L5:
	add	r3, r4, r4, lsr #31
	mov	r0, r5
	asrs	fp, r3, #1
	add	r3, fp, #48
	strbne	r8, [r6]
	strb	r3, [r9], #1
	bl	strlen
	and	r3, r4, #1
	sub	r2, r0, #1
	cmp	r2, r10
	bls	.L4
	cmp	r4, #0
	rsblt	r3, r3, #0
	ldrb	r4, [r7, r10]	@ zero_extendqisi2
	add	r3, r3, r3, lsl #2
	sub	r4, r4, #48
	add	r4, r4, r3, lsl #1
.L4:
	add	r10, r10, #1
	cmp	r0, r10
	bhi	.L5
.L2:
	sub	r0, r4, fp, lsl #1
	mov	r3, #0
	uxtb	r0, r0
	strb	r3, [r9]
	pop	{r3, r4, r5, r6, r7, r8, r9, r10, fp, pc}
.L6:
	mov	fp, r0
	b	.L2
	.size	div2, .-div2
	.align	2
	.global	dec2bin
	.syntax unified
	.arm
	.fpu vfp
	.type	dec2bin, %function
dec2bin:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, r8, r9, r10, fp, lr}
	add	fp, sp, #32
	sub	sp, sp, #12
	mov	r6, r0
	bl	strlen
	add	r9, r6, #1
	mov	r4, r0
	lsl	r0, r0, #2
	add	r0, r0, #1
	bl	malloc
	add	r4, r4, #8
	bic	r4, r4, #7
	sub	sp, sp, r4
	mov	r8, sp
	mov	r7, r0
	str	r0, [fp, #-40]
.L18:
	mov	r0, r6
	bl	strlen
	ldrb	r5, [r6]	@ zero_extendqisi2
	sub	r4, r5, #48
	cmp	r0, #0
	beq	.L14
	mov	ip, r8
	mov	r5, #1
	mov	r2, #0
	sub	r1, r0, #1
.L17:
	add	r10, r4, r4, lsr #31
	and	lr, r4, #1
	asrs	r10, r10, #1
	movne	r5, #0
	add	r3, r10, #48
	cmp	r1, r2
	strb	r3, [ip], #1
	bls	.L16
	cmp	r4, #0
	ldrb	r3, [r9, r2]	@ zero_extendqisi2
	rsblt	lr, lr, #0
	add	r4, lr, lr, lsl #2
	sub	r3, r3, #48
	add	r4, r3, r4, lsl #1
.L16:
	add	r2, r2, #1
	cmp	r0, r2
	bhi	.L17
	mov	r3, #0
	mov	r1, r8
	mov	r0, r6
	strb	r3, [ip]
	sub	r4, r4, r10, lsl #1
	bl	strcpy
	add	r4, r4, #48
	cmp	r5, #0
	strb	r4, [r7], #1
	beq	.L18
	b	.L19
.L14:
	mov	lr, r0
	mov	r1, r8
	mov	r0, r6
	strb	lr, [r8]
	bl	strcpy
	strb	r5, [r7], #1
.L19:
	mov	r3, #0
	ldr	r0, [fp, #-40]
	strb	r3, [r7]
	sub	sp, fp, #32
	@ sp needed
	pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
	.size	dec2bin, .-dec2bin
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	ldr	r3, .L29
	str	lr, [sp, #-4]!
	sub	sp, sp, #12
	ldr	r3, [r3]
	add	r0, sp, #4
	strh	r3, [sp, #4]	@ movhi
	lsr	r3, r3, #16
	strb	r3, [sp, #6]
	bl	dec2bin
	bl	puts
	mov	r0, #0
	add	sp, sp, #12
	@ sp needed
	ldr	pc, [sp], #4
.L30:
	.align	2
.L29:
	.word	.LC0
	.size	main, .-main
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"23\000"
	.ident	"GCC: (Raspbian 8.3.0-6+rpi1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
