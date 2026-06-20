#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t { int valor; struct no_t *anterior, *proximo; } no_t;
struct lista_t { no_t *primeiro, *ultimo; };

Lista* lista_criar() {
    Lista* l = malloc(sizeof(Lista));
    l->primeiro = NULL; l->ultimo = NULL;
    return l;
}

void lista_inserir(Lista* l, int valor) {
    no_t* n = malloc(sizeof(no_t));
    n->valor = valor; n->proximo = NULL; n->anterior = l->ultimo;
    if(l->ultimo) l->ultimo->proximo = n;
    else l->primeiro = n;
    l->ultimo = n;
}

void lista_remover(Lista* l, int valor) {
    no_t* a = l->primeiro;
    while(a && a->valor != valor) a = a->proximo;
    if(!a) return;
    if(a->anterior) a->anterior->proximo = a->proximo;
    else l->primeiro = a->proximo;
    if(a->proximo) a->proximo->anterior = a->anterior;
    else l->ultimo = a->anterior;
    free(a);
}

int lista_buscar(Lista* l, int valor) {
    no_t* a = l->primeiro;
    while(a) { 
        if(a->valor == valor) return 1; 
        a = a->proximo; 
    }
    return 0;
}

void lista_exibir(Lista* l) {
    no_t* a = l->primeiro;
    while(a) { 
        printf("%d ", a->valor); 
        a = a->proximo; 
    }
    printf("\n");
}

int lista_esta_vazia(Lista* l) { return l->primeiro == NULL; }

void lista_destruir(Lista* l) {
    no_t* a = l->primeiro;
    while(a) { 
        no_t* p = a->proximo; 
        free(a); 
        a = p; 
    }
    free(l);
}