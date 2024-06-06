#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char random_permutation_cyclic_type(int* perm, int* cyc, int ncyc) {
    int i, j, k;
    int count = 0;

    if (perm == NULL || cyc == NULL || ncyc <= 0) {
        return 0;
    }

    for (j = 0; j < cyc[0]; ++j) {
        perm[j] = j + 1;
    }
    count += cyc[0];

    for (i = 1; i < ncyc; ++i) {
        for (j = count; j < cyc[i] + count; ++j) {
            perm[j] = j + 1;
        }
        count += cyc[i];
    }

    //Fisher-Yatesov algoritmus
    for (i = count - 1; i > 0; --i) {
        j = rand() % (i + 1);
        k = perm[i];
        perm[i] = perm[j];
        perm[j] = k;
    }

    return 1;
}

int main() {
    srand((unsigned int)time(NULL));
    int n = 32;
    int ncyc = 6;
    int cyc[] = {3, 2, 5, 6, 9, 7};
    int* perm = (int*)malloc(n * sizeof(int));

    if (random_permutation_cyclic_type(perm, cyc, ncyc)) {
        printf("Random Permutation: ");
        for (int i = 0; i < n; ++i) {
            printf("%d ", perm[i]);
        }
        printf("\n");
    }
    else {
        printf("Error.\n");
    }

    free(perm);
    return 0;
}