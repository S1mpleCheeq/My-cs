#include <stdio.h>
#include <random>

#define SEED 0

int main() {
    srand(SEED);
    printf("%d",rand());
    int SEED=0;
    srand(SEED);
    return 0;
}
