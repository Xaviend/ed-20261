#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t { int valor; struct no_t *esquerda, *direita; } no_t;
struct arvore_t { no_t *raiz; };

Arvore* arvore_criar() {
    Arvore* a = malloc(sizeof(Arvore)); 
    a->raiz = NULL; 
    return a;
}

no_t* inserir_no(no_t* n, int valor) {
    if(!n) {
        no_t* novo = malloc(sizeof(no_t)); 
        novo->valor = valor;
        novo->esquerda = NULL; 
        novo->direita = NULL; 
        return novo;
    }
    if(valor < n->valor) n->esquerda = inserir_no(n->esquerda, valor);
    else if(valor > n->valor) n->direita = inserir_no(n->direita, valor);
    return n;
}

void arvore_inserir(Arvore* a, int valor) { a->raiz = inserir_no(a->raiz, valor); }

void pre_ordem(no_t* n) { 
    if(n) { printf("%d ", n->valor); pre_ordem(n->esquerda); pre_ordem(n->direita); } 
}
void arvore_exibir_pre_ordem(Arvore* a) { pre_ordem(a->raiz); printf("\n"); }

void em_ordem(no_t* n) { 
    if(n) { em_ordem(n->esquerda); printf("%d ", n->valor); em_ordem(n->direita); } 
}
void arvore_exibir_em_ordem(Arvore* a) { em_ordem(a->raiz); printf("\n"); }

void pos_ordem(no_t* n) { 
    if(n) { pos_ordem(n->esquerda); pos_ordem(n->direita); printf("%d ", n->valor); } 
}
void arvore_exibir_pos_ordem(Arvore* a) { pos_ordem(a->raiz); printf("\n"); }

int arvore_esta_vazia(Arvore* a) { return a->raiz == NULL; }

void destruir_no(no_t* n) { 
    if(n) { destruir_no(n->esquerda); destruir_no(n->direita); free(n); } 
}
void arvore_destruir(Arvore* a) { destruir_no(a->raiz); free(a); }