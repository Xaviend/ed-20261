#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t { int valor; struct no_t *proximo; } no_t;
struct pilha_t { no_t *topo; };

Pilha* pilha_criar() {
    Pilha* p = malloc(sizeof(Pilha)); 
    p->topo = NULL; 
    return p;
}

void pilha_empilhar(Pilha* p, int valor) {
    no_t* n = malloc(sizeof(no_t));
    n->valor = valor; 
    n->proximo = p->topo; 
    p->topo = n;
}

int pilha_desempilhar(Pilha* p) {
    if(!p->topo) return -1;
    no_t* n = p->topo; 
    int v = n->valor;
    p->topo = n->proximo; 
    free(n); 
    return v;
}

int pilha_topo(Pilha* p) { return p->topo ? p->topo->valor : -1; }
int pilha_esta_vazia(Pilha* p) { return p->topo == NULL; }

void pilha_exibir(Pilha* p) {
    no_t* a = p->topo;
    while(a) { 
        printf("%d ", a->valor); 
        a = a->proximo; 
    }
    printf("\n");
}

void pilha_destruir(Pilha* p) {
    while(!pilha_esta_vazia(p)) pilha_desempilhar(p);
    free(p);
}