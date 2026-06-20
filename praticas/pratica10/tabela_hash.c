#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t { int valor; struct no_t* proximo; } no_t;
struct hash_t { no_t** tabela; int tamanho; };

TabelaHash* hash_criar(int tamanho) {
    TabelaHash* h = malloc(sizeof(TabelaHash));
    h->tamanho = tamanho; 
    h->tabela = calloc(tamanho, sizeof(no_t*));
    return h;
}

int func_hash(int valor, int tamanho) { return abs(valor) % tamanho; }

void hash_inserir(TabelaHash* h, int valor) {
    int idx = func_hash(valor, h->tamanho);
    no_t* n = malloc(sizeof(no_t)); 
    n->valor = valor;
    n->proximo = h->tabela[idx]; 
    h->tabela[idx] = n;
}

int hash_buscar(TabelaHash* h, int valor) {
    int idx = func_hash(valor, h->tamanho);
    no_t* a = h->tabela[idx];
    while(a) { 
        if(a->valor == valor) return 1; 
        a = a->proximo; 
    }
    return 0;
}

void hash_remover(TabelaHash* h, int valor) {
    int idx = func_hash(valor, h->tamanho);
    no_t *a = h->tabela[idx], *ant = NULL;
    while(a && a->valor != valor) { 
        ant = a; 
        a = a->proximo; 
    }
    if(!a) return;
    if(ant) ant->proximo = a->proximo; 
    else h->tabela[idx] = a->proximo;
    free(a);
}

void hash_exibir(TabelaHash* h) {
    for(int i = 0; i < h->tamanho; i++) {
        printf("[%d]: ", i); 
        no_t* a = h->tabela[i];
        while(a) { 
            printf("%d -> ", a->valor); 
            a = a->proximo; 
        }
        printf("NULL\n");
    }
}

int hash_esta_vazia(TabelaHash* h) {
    for(int i = 0; i < h->tamanho; i++) {
        if(h->tabela[i]) return 0;
    }
    return 1;
}

void hash_destruir(TabelaHash* h) {
    for(int i = 0; i < h->tamanho; i++) {
        no_t* a = h->tabela[i];
        while(a) { 
            no_t* p = a->proximo; 
            free(a); 
            a = p; 
        }
    }
    free(h->tabela); 
    free(h);
}