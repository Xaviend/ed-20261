#include "ordenacao.h"

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void bubble_sort(int *v, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (v[j] > v[j+1]) swap(&v[j], &v[j+1]);
}

void selection_sort(int *v, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) if (v[j] < v[min]) min = j;
        swap(&v[i], &v[min]);
    }
}

void quick_sort(int *v, int low, int high) {
    if (low < high) {
        int p = v[high], i = low;
        for (int j = low; j < high; j++)
            if (v[j] < p) swap(&v[i++], &v[j]);
        swap(&v[i], &v[high]);
        quick_sort(v, low, i - 1);
        quick_sort(v, i + 1, high);
    }
}