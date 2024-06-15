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
    count = 0;
    for (i = 0; i < ncyc; ++i) {
        int start = count;
        int end = count + cyc[i];
        count = end;
        for (j = end - 1; j > start; --j) {
            k = rand() % (j - start + 1) + start;
            int temp = perm[j];
            perm[j] = perm[k];
            perm[k] = temp;
        }
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