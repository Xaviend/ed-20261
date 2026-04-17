#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main () {
    Agenda *agenda_t = criar_agenda (10);

    Contato contato;
    strcpy(contato.nome, "Jose");
    strcpy(contato.telefone, "1111-1111");

    adicionar_contato(&agenda_t , contato_t)


    listar_contato(&agenda_t);

    return 0;
}