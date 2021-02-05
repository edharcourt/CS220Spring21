.global between

/*
int between(int x, int y, int z) {
   if (x < y && y < z)
        return 1;
   else
        return 0;
}
*/
.text
between:
    cmp r0, r1
    bge else
    cmp r1, r2
    bge else
    mov r0, #1
    b end_between
else:
    mov r0, #0
end_between:
    bx lr
