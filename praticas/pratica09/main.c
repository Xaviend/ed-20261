// praticas/pratica09/main.c
#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Arvore* a = arvore_criar();
    arvore_inserir(a, 10);
    arvore_inserir(a, 5);
    arvore_inserir(a, 15);
    arvore_exibir_em_ordem(a);
    arvore_destruir(a);
    return 0;
}