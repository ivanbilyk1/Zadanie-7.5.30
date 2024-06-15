#include "Permutation.h"

int main() {
    srand((unsigned int)time(NULL));
    int i;
    int n;
    int ncyc = 6;
    int cyc[] = { 1, 1, 1, 1, 1, 1 };

    for (n = 0, i = 0; i < ncyc; n += cyc[i++]);

    print(n, cyc, ncyc);
    return 0;
}