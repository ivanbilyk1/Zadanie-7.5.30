#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char random_permutation_cyclic_type(int* perm, int* cyc, float ncyc) {
    int i, j, k;
    int count = 0;

    if (perm == NULL || cyc == NULL || ncyc <= 0) {
        return 0;
    }
}