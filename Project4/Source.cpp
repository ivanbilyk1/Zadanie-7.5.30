#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char random_permutation_cyclic_type(int* perm, int* cyc, float ncyc) {
    int i, j, k;
    int count = 0;

    if (perm == NULL || cyc == NULL || ncyc <= 0) {
        return 0;
    }

    srand((unsigned int)time(NULL));

    for (i = 0; i < ncyc; ++i) {
        for (j = 0; j < cyc[i]; ++j) {
            perm[j + count] = j + 1;
        }
        count += cyc[i];
    }

    for (i = count - 1; i > 0; --i) {
        j = rand() % (i + 1);
        k = perm[i];
        perm[i] = perm[j];
        perm[j] = k;
    }

    return 1;
}

int main() {
    int n = 10;
    int ncyc = 3;
    int cyc[] = { 3, 2, 5 };
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