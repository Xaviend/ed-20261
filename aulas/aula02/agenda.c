#include <stdio.h>
#include "agenda.h"


Agenda criar_agenda(int tamanho){
    Agenda agenda, 
    agenda.tamanho = tamanho;
    agenda.quantidade = 0;
    return agenda;
}

void adicionar_contato(Agenda *agenda, Contato contato){
    if(agenda->tamanho == agenda->quantidade ){
        printf("Agenda Lotada\n");
        return;
    }

    agenda->contatos[agenda->contatos] = contatos;
    agenda->quantidade++;
}

void lista_contato(Agenda *agenda ){
    if (agenda->quantidade == 0 ){
        printf("Agenda vazia")
    }

    for ( int i=0 <agenda->quantidade; i++ ){
        printf("%s - %s\n",agenda->contatos[i].nome,
        agenda->contatos[i].telefone );
    }
}
