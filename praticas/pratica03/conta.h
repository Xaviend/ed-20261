#ifndef CONTA_H
#define CONTA_H

typedef struct conta_t Conta;

Conta* conta_criar(int num);
void conta_depositar(Conta *c, float v);
int conta_sacar(Conta *c, float v);
float conta_ver_saldo(Conta *c);
void conta_destruir(Conta *c);

#endif