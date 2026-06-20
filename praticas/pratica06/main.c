#include <stdio.h>
#include "lista_linear.h"

int main() {
    Lista* l = lista_criar();
    lista_inserir(l, 10);
    lista_inserir(l, 20);
    lista_inserir(l, 30);
    lista_exibir(l);
    lista_remover(l, 20);
    lista_exibir(l);
    printf("Busca 30: %d\n", lista_buscar(l, 30));
    lista_destruir(l);
    return 0;
}