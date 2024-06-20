#include "Permutation.h"

int main() {
    srand((unsigned int)time(NULL));
    int i;
    int n;
    int cyc[] = { 4, 1, 2, 1, 1, 1 };

    int ncyc = sizeof(cyc) / sizeof(cyc[0]);

    for (n = 0, i = 0; i < ncyc; n += cyc[i++]);

    print(n, cyc, ncyc);
    return 0;
}