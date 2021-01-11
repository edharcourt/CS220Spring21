
int checksum(int n) {
    int sum = 0;
    int tmp = n;

    while (n > 0) {
        sum = sum + (n % 10);
	n = n / 10;
    }

    return (tmp * 10) + (sum % 10);
}
