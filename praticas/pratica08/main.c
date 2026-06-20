#include <stdio.h>
#include "fila.h"

int main() {
    Fila* f = fila_criar();
    fila_enfileirar(f, 1);
    fila_enfileirar(f, 2);
    fila_enfileirar(f, 3);
    fila_exibir(f);
    printf("Saiu da fila: %d\n", fila_desenfileirar(f));
    printf("Proximo inicio: %d\n", fila_inicio(f));
    fila_destruir(f);
    return 0;
}