// HW 5 Due Friday March 19


/*
 * An 8 bit unsigned integer. 
 *
 * C doesn't specify if char is signed or unsigned. 
 * So define a byte to be an unsigned char. 
 */
typedef unsigned char byte;
typedef unsigned char uint8_t;


/*
 * A 16 bit unsigned integer 
 */
typedef unsigned short uint16_t;


/*
 * The BigInt struct. n is the number of digits in the number
 * and ds is an array of digits. One digit per element.
 *
 * ds[0] contains the least significant digit.
 *
 * For example, the number 397 would be stored in the array as
 *
 *         -------------
 *         | 7 | 9 | 3 |
 *         -------------
 *  index =  0   1   2
 *
 *  Or the way we have been drawing it in class with index 0 on the right.
 *
 *         -------------
 *         | 3 | 9 | 7 |
 *         -------------
 *  index =  2   1   0
 *
 *  They are equivalent.
 */
typedef struct {
    byte *ds;
    int n;  // the number of digits
} BigInt;


/*
 * Create a BigInt from a string of decimal digits
 * make_int("1234567890")
 */
extern BigInt *make_int(const char *x);


/* 
 * Print a BigInt without leading zeros. The println version includes
 * a trailing newline character '\n'.
 */
extern void print_int(const BigInt *b);
extern void println_int(const BigInt *b);


/*
 * Free the storage associated with x. This frees *both*
 * the array of digits and the struct. 
 */
extern void free_int(BigInt *);


/*
 * Return a BigInt that is the addition of x and y.
 * Storage is allocated for the result. It is the responsibility
 * of the caller to free the storage. x and y are unmodified. 
 */
extern BigInt *add(const BigInt *x, const BigInt *y);


/*
 * A version of add that does not allocate new storage but adds
 * y into x (thereby modifying x). Notice that x is not const. 
 * x is also returned from the function.
 *
 * No new memory should be allocated. x must be large 
 * enough to include the addition of y
 *
 * No new memory should be allocated. x must be large 
 * enough to include the addition of y.
 */
extern BigInt *acc(BigInt *x, const BigInt *y);


/*
 * Shift x left by n places, effectively multiplying by 
 * a power of 10. x is modified and also returned. 
 *
 * No new memory should be allocated. x must be large 
 * enough to include the shift. 
 */
extern BigInt *shift_left(BigInt *x, int n);


/*
 * Return the result of multiply x and y and allocating new storage for 
 * the result.  It is the responsibility of the caller to free the
 * storage when they are finished with it.
 */
extern BigInt *mult(const BigInt *x, const BigInt *y);


/*
 * Compute x raised to the y power. This allocated a new BigInt.
 * 
 * y is an int (and not a BigInt) for two reasons:
 *
 *     1) y can be as big as 2147483647 and there is no reason
 *        to be able to have an exponent larger than that.
 *
 *     2) If we leave y an int, then we can do some basic math on it
 *        that we have not implemented yet for BigInts, such as dividing
 *        by two or subtracting 1.
 */
extern BigInt *bigpow(const BigInt *x, int y);
