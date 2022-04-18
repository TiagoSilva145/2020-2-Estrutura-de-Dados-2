#include <stdio.h>
#include <stdlib.h>

typedef struct _arvore {
   char info;
   struct _arvore *esq;
   struct _arvore *dir;
} Arvore;

Arvore* cria_arv_vazia ();

void destroi_arv (Arvore *arv);

Arvore* constroi_arv (char elem, Arvore *esq, Arvore *dir);

void preordem (Arvore* arv);

void inordem (Arvore* arv);

void posordem (Arvore* arv);

void imprime_arv_marcadores (Arvore* arv);

int pertence_arv (Arvore *a, char c);

int conta_nos (Arvore *a);

int calcula_altura_arvore (Arvore *a);

int conta_nos_folha (Arvore *a);

