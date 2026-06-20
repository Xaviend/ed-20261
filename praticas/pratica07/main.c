#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p = pilha_criar();
    pilha_empilhar(p, 5);
    pilha_empilhar(p, 10);
    pilha_empilhar(p, 15);
    pilha_exibir(p);
    printf("Topo removido: %d\n", pilha_desempilhar(p));
    printf("Novo Topo: %d\n", pilha_topo(p));
    pilha_destruir(p);
    return 0;
}