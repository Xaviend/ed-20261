#include "selecao.h"

// Linear: O(n)
int linear_search(int *v, int n, int x) {
    for (int i = 0; i < n; i++) if (v[i] == x) return i;
    return -1;
}

// QuickSelect: O(n) médio para achar o k-ésimo menor
int quick_select(int *v, int left, int right, int k) {
    if (left == right) return v[left];
    int p = v[right], i = left;
    for (int j = left; j < right; j++)
        if (v[j] <= p) { int t = v[i]; v[i] = v[j]; v[j] = t; i++; }
    int t = v[i]; v[i] = v[right]; v[right] = t;

    if (i == k) return v[i];
    return (k < i) ? quick_select(v, left, i - 1, k) : quick_select(v, i + 1, right, k);
}