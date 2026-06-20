#include <stdio.h>
#include <time.h>

#define N 10

int main() {
    int m[N][N] = {0};
    clock_t start;

    start = clock();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) printf("%d ", m[i][j]);
    printf("\nTempo 2 laços: %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    start = clock();
    int *ptr = &m[0][0];
    for (int i = 0; i < N * N; i++) printf("%d ", ptr[i]);
    printf("\nTempo 1 laço: %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}