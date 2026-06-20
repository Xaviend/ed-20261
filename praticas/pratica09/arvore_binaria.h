typedef struct arvore_t Arvore;
Arvore* arvore_criar();
void arvore_inserir(Arvore* a, int valor);
void arvore_exibir_pre_ordem(Arvore* a);
void arvore_exibir_em_ordem(Arvore* a);
void arvore_exibir_pos_ordem(Arvore* a);
int arvore_esta_vazia(Arvore* a);
void arvore_destruir(Arvore* a);