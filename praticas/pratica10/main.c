#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash* h = hash_criar(10);
    hash_inserir(h, 15);
    hash_inserir(h, 25);
    hash_inserir(h, 5);
    hash_exibir(h);
    hash_remover(h, 25);
    printf("Busca 15: %d\n", hash_buscar(h, 15));
    hash_destruir(h);
    return 0;
}