/*
 *  Creates a copy of src and allocating memory for the copy
 *  and returning a pointer to the newly allocated memory. 
 *  The caller must free the memory allocated.
 *
 *  n - the size of src (src is not necessarily a null terminated string)
 *      Think of it more appropriately as an array of bytes.
 *
 *  src - the bytes to be copied
 * 
 *  returns a pointer the copied object 
 *
 *  This function contains a sneaky buffer overflow. n is of type 
 *  size_t (an unsigned int) but i is an int (a signed int) hence
 *  n can be gretaer then i causing i to wrap around to negative
 *  values.
 *
 *  Modified from a Robert Seacord video at  
 *
 *      https://www.youtube.com/watch?v=1ew0GvB3NpE  
 *
 */


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *copy(u_char n, const char *src) {

    if (n == 0)
        return NULL;

    char *dest = malloc(n);

    if (dest == NULL)
        return NULL;

    for (int8_t i = 0; i < n; ++i)
        dest[i] = *src++;

    return dest;
}

int main(int argc, char *argv[]) {

    char *buff = copy(strlen(argv[1]), argv[1]);  

    // do some stuff with buff

    printf("%s\n", buff);
    

}
