void scale(int *vec, int s, int n) {
    int i = 0;
    while (i < n) {
        vec[i] = vec[i] * s;
        i++;
    }
}
