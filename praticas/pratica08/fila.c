#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t { int valor; struct no_t *proximo; } no_t;
struct fila_t { no_t *inicio, *fim; };

Fila* fila_criar() {
    Fila* f = malloc(sizeof(Fila)); 
    f->inicio = NULL; 
    f->fim = NULL; 
    return f;
}

void fila_enfileirar(Fila* f, int valor) {
    no_t* n = malloc(sizeof(no_t)); 
    n->valor = valor; 
    n->proximo = NULL;
    if(f->fim) f->fim->proximo = n;
    else f->inicio = n;
    f->fim = n;
}

int fila_desenfileirar(Fila* f) {
    if(!f->inicio) return -1;
    no_t* n = f->inicio; 
    int v = n->valor;
    f->inicio = n->proximo;
    if(!f->inicio) f->fim = NULL;
    free(n); 
    return v;
}

int fila_inicio(Fila* f) { return f->inicio ? f->inicio->valor : -1; }
int fila_esta_vazia(Fila* f) { return f->inicio == NULL; }

void fila_exibir(Fila* f) {
    no_t* a = f->inicio;
    while(a) { 
        printf("%d ", a->valor); 
        a = a->proximo; 
    }
    printf("\n");
}

void fila_destruir(Fila* f) {
    while(!fila_esta_vazia(f)) fila_desenfileirar(f);
    free(f);
}