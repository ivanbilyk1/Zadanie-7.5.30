#include "Permutation.h"

char random_permutation_cyclic_type(int* perm, int* cyc, int ncyc) {
    int i, j;
    int count = 0;

    if (perm == NULL || cyc == NULL || ncyc <= 0) {
        return 0;
    }
    
    for (i = 0; i < ncyc; ++i) {
        for (j = 0; j < cyc[i]; ++j) {
            perm[count + j] = count + cyc[i] - j;
        }
        count += cyc[i];
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

    return 1;
}