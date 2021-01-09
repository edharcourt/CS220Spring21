/*
 * A function that returns the number of times digit in a
 * positive integer n. For example, countd(2737) is 2.
 */
int countd(int n, int digit) {

    int count = 0;

    while (n > 0) {
        if (n % 10 == digit)
            count += 1;

        n = n / 10;
    }

    return count;
}
