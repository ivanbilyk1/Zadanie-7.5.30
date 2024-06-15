#include "Permutation.h"

char random_permutation_cyclic_type(int* perm, int* cyc, int ncyc) {
    int i, j, k;
    int count = 0;

    if (perm == NULL || cyc == NULL || ncyc <= 0) {
        return 0;
    }

    for (i = 0; i < ncyc; ++i) {
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

int print(int n, int *cyc, int ncyc) {
    int* perm = (int*)malloc(n * sizeof(int));

    if (perm == NULL) {
        printf("Problem alokacie");
        return 1;
    }

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
}