
/*
 * An 8 bit unsigned integer. 
 * C doesn't specify if char is signed or unsigned. 
 * So define a byte to be an unsigned char. 
 */
typedef unsigned char byte;
typedef unsigned char uint8_t;

/*
 * A 16 bit unsigned integer 
 */
typedef unsigned short uint16_t;

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
 * Printy a BigInt without leading zeros.
 */
extern void print_int(const BigInt *b);
extern void println_int(const BigInt *b);

/*
 * Free the storage associated with x. 
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
 */
extern BigInt *acc(BigInt *x, const BigInt *y);

/*
 * Shift x left by n places, effectively multiplying by 
 * a power of 10. x is modified and also returned. 
 */
extern BigInt *shift_left(BigInt *x, int n);

/*
 * Return the result of multiply x and y allocating new storage for 
 * the result.  It is the responsibility of the caller to free the
 * storage when they are finished with it.
 */
extern BigInt *mult(const BigInt *x, const BigInt *y);

/*
 * Compute x raised to the y power. 
 */
extern BigInt *bigpow(const BigInt *x, int y);
