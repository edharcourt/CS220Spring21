
typedef unsigned char byte;
typedef unsigned short uint16_t;

typedef struct {
    byte *ds;
    int n;  // the number of digits
} BigInt;

extern BigInt *make_int(const char *x);

extern void print_int(const BigInt *b);
extern void println_int(const BigInt *b);

extern BigInt *add(const BigInt *x, const BigInt *y);
