
/*
 * Return the index of the smallest item in the array
 * vec from index i.
 *
 * precondition: 0 <= i < n
 */
int find_smallest(int i, int vec[], int n) {
    
    int r = i; // assume i is smallest
    
    for (int j = i; j < n; j++)
        if (vec[j] < vec[r])
            r = j;

    return r;
}
