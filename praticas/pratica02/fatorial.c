#include <stdio.h>

// Iterativo: O(n) tempo, O(1) espaço. Mais seguro para números grandes.
long long fat_i(int n) {
    long long res = 1;
    while (n > 1) res *= n--;
    return res;
}

// Recursivo: O(n) tempo, O(n) espaço (stack). Elegante, mas arriscado.
long long fat_r(int n) {
    return (n <= 1) ? 1 : n * fat_r(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("Iterativo: %lld\nRecursivo: %lld\n", fat_i(n), fat_r(n));
    return 0;
}