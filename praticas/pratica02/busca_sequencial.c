#include <stdio.h>

int busca(int *v, int n, int x) {
    for (int i = 0; i < n; i++) if (v[i] == x) return i;
    return -1;
}

int main() {
    int v[100], x;
    for (int i = 0; i < 100; i++) v[i] = i * 2; // Exemplo
    scanf("%d", &x);
    printf("Posicao: %d\n", busca(v, 100, x));
    return 0;
}