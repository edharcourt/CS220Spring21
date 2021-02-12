extern int find_smallest(int i, int vec[], int n);
extern void swap(int vec[], int i, int j);

void sort(int vec[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int j = find_smallest(i, vec, n);
        swap(vec, i, j);
    }    
}
