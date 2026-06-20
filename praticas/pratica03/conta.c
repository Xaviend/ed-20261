#include <stdlib.h>
#include "conta.h"

struct conta_t { int numero; float saldo; };

Conta* conta_criar(int num) {
    Conta *c = malloc(sizeof(Conta));
    if (c) { c->numero = num; c->saldo = 0; }
    return c;
}

void conta_depositar(Conta *c, float v) { if (v > 0) c->saldo += v; }
int conta_sacar(Conta *c, float v) { 
    if (v > 0 && c->saldo >= v) { c->saldo -= v; return 1; }
    return 0;
}
float conta_ver_saldo(Conta *c) { return c ? c->saldo : 0; }
void conta_destruir(Conta *c) { free(c); }