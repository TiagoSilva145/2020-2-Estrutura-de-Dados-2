#include "arvore.h"

Arvore* cria_arv_vazia () {
   return NULL;
}

void destroi_arv (Arvore *arv) {
   if (arv != NULL) {
      destroi_arv (arv->esq);
      destroi_arv (arv->dir);
      free(arv);
   }
}

Arvore* constroi_arv (char elem, Arvore *esq, Arvore *dir) {
   Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
   arv->info = elem;
   arv->esq = esq;
   arv->dir = dir;
   return arv;
}

void preordem (Arvore* arv)
{
    printf("%c ", arv->info);

    if(arv->esq)
        preordem(arv->esq);
    if(arv->dir)
       preordem(arv->dir);

    return;
}

void inordem (Arvore* arv)
{
    if(arv->esq)
        inordem(arv->esq);

    printf("%c ", arv->info);

    if(arv->dir)
       inordem(arv->dir);

    return;
}

void posordem (Arvore* arv)
{
    if(arv->esq)
        posordem(arv->esq);

    if(arv->dir)
       posordem(arv->dir);

    printf("%c ", arv->info);

    return;
}

void imprime_arv_marcadores (Arvore* arv)
{
    printf("<%c", arv->info);

    if(arv->esq)
        imprime_arv_marcadores(arv->esq);
    else
        printf("<>");

    if(arv->dir)
       imprime_arv_marcadores(arv->dir);
    else
        printf("<>");

    printf(">");

    return;
}

int pertence_arv (Arvore *a, char c)
{
    /*int dado = 0;

    if(a->info == c)
        return 1;

    if(a->esq)
        dado = pertence_arv (a->esq,c);

    if(a->dir && dado == 0)
       dado = pertence_arv (a->dir,c);

    return dado;*/

    if(a->info == c)
        return 1;

    if(a->esq)
        if(pertence_arv (a->esq,c))
            return 1;

    if(a->dir)
       if(pertence_arv (a->dir,c))
            return 1;

    return 0;
}

int conta_nos (Arvore *a)
{
    int nos = 1;

    if(a->esq)
        nos += conta_nos(a->esq);

    if(a->dir)
        nos += conta_nos(a->dir);

    return nos;
}

int calcula_altura_arvore (Arvore *a)
{
    int h = -1;
    int aux = 0;

    if(a->esq)
    {
        aux = calcula_altura_arvore(a->esq);
        if(aux > h)
            h = aux;
    }

    if(a->dir)
    {
        aux = calcula_altura_arvore(a->dir);
        if(aux > h)
            h = aux;
    }

    return h+1;
}

int conta_nos_folha (Arvore *a)
{
    int nos = 0;

    if(a->esq)
        nos += conta_nos_folha(a->esq);

    if(a->dir)
        nos += conta_nos_folha(a->dir);

    if(a->esq == NULL && a->dir == NULL)
        nos++;

    return nos;
}
