.global sort

/*

void sort(int vec[], int n) {
    int i = 0;
    while (i < n) {
        int j = find_smallest(i, vec, n);
        swap(vec, i, j);
        i++;
    }
}
*/

.text 
sort:
    push { r4, r5, r6, r11, lr }    // r11 used by C compiler 
    mov r4, r0    // vec is in r4
    mov r5, r1    // n is in r5
    mov r6, #0    // i is in r6

while:
    cmp r6, r5
    bge endwhile
    mov r0, r6
    mov r1, r4
    mov r2, r5
    bl find_smallest
    mov r2, r0   


endwhile:    

