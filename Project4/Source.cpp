#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int q = 0;

char random_permutation_cyclic_type(int* perm, int* cyc, int ncyc) {
    int i, j, k;
    int count = 0;

    if (perm == NULL || cyc == NULL || ncyc <= 0) {
        return 0;
    }

    for (i = 0; i < ncyc; ++i) {
        for (j = 0; j < cyc[i]; ++j) {
            perm[j + count] = j + 1;
        }
        count += cyc[i];
    }

    for (int i = 0; i < count; ++i) {
        for (int j = 1; j < count; ++j) {
            if (perm[i] == perm[i - j]) {
                perm[i] = 0;
            }
        }
    }

    //Fisher-Yatesov algoritmus
    for (i = count - 1; i > 0; --i) {
        j = rand() % (i + 1);
        k = perm[i];
        perm[i] = perm[j];
        perm[j] = k;
    }

    for (int i = 0; i < count; ++i) {
        if (perm[i] != 0) {
            q++;
        }
    }

    int* perm2 = (int*)malloc(q * sizeof(int));

    int index = 0;
    for (int i = 0; i < count; ++i) {
        if (perm[i] != 0) {
            perm2[index++] = perm[i];
        }
    }

    for (int i = 0; i < count; ++i) {
        perm[i] = perm2[i];
    }

    free(perm2);

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
        for (int i = 0; i < q; ++i) {
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