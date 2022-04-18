#include "avl_int.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir)
{
    return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura (Arvore_int* a)
{
    return (!a ? -1 : a->altura);
}

int atualizar_altura (Arvore_int *a)
{
    return(maior(altura(a->esq), altura(a->dir)) + 1);
}

/*----------------------*/
int balanceamento (Arvore_int *a)
{
    return(altura(a->dir) - altura(a->esq));
}

/*----------------------*/
Arvore_int* rotacao_simples_esq (Arvore_int* a)
{
    Arvore_int* aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;

    a->altura = atualizar_altura(a);
    aux->altura = atualizar_altura(aux);

    return aux;
}

/*----------------------*/
Arvore_int* rotacao_simples_dir (Arvore_int* a)
{
    Arvore_int* aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;

    a->altura = atualizar_altura(a);
    aux->altura = atualizar_altura(aux);

    return aux;
}

/*----------------------*/
Arvore_int* rotacao_dupla_esq (Arvore_int* a)
{
    a->dir = rotacao_simples_dir(a->dir);
    return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore_int* rotacao_dupla_dir (Arvore_int* a)
{
    a->esq = rotacao_simples_esq(a->esq);
    return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore_int* atualizar_fb_dir (Arvore_int *a)
{
    a->altura = atualizar_altura(a);

    if(balanceamento(a) == 2)
    {
        if(balanceamento(a->dir) >= 0)
            a = rotacao_simples_esq(a);
        else
            a = rotacao_dupla_esq(a);
    }
    return a;
}

/*----------------------*/
Arvore_int* atualizar_fb_esq (Arvore_int *a)
{
    a->altura = atualizar_altura(a);

    if(balanceamento(a) == -2)
    {
        if(balanceamento(a->esq) <= 0)
            a = rotacao_simples_dir(a);
        else
            a = rotacao_dupla_dir(a);
    }
    return a;
}

/*----------------------*/
Arvore_int* inserir (Arvore_int *a, int chave)
{
    if(!a)
    {
        a = (Arvore_int*) malloc(sizeof (Arvore_int));
        a->esq = a->dir = NULL;
        a->altura = 0;
        a->chave = chave;
    }

    else if(chave < a->chave)
    {
        a->esq = inserir(a->esq, chave);
        a = atualizar_fb_esq(a);
    }

    else
    {
        a->dir = inserir(a->dir, chave);
        a = atualizar_fb_dir(a);
    }
    return a;
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore_int* remover (Arvore_int *a, int chave)
{
    if (a == NULL)
    {
        return NULL;
    }
    else
    {
        if (chave < a->chave)
        {
            a->esq = remover (a->esq, chave);
            a = atualizar_fb_dir (a);
        }
        else if (chave > a->chave)
        {
            a->dir = remover (a->dir, chave);
            a = atualizar_fb_esq (a);
        }
        else
        {
            if ((a->esq == NULL) && (a->dir == NULL))
            {
                free (a);
                a = NULL;
            }
            else if (a->esq == NULL)
            {
                Arvore_int *tmp = a;
                a = a->dir;
                free (tmp);
            }
            else if (a->dir == NULL)
            {
                Arvore_int *tmp = a;
                a = a->esq;
                free (tmp);
            }
            else
            {
                Arvore_int *tmp = a->esq;
                while (tmp->dir != NULL)
                {
                    tmp = tmp->dir;
                }
                a->chave = tmp->chave;
                tmp->chave = chave;
                a->esq = remover (a->esq, chave);
                a = atualizar_fb_dir (a);
            }
        }
        return a;
    }
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order (Arvore_int* a, int nivel)
{
    if (a != NULL)
    {
        int i;
        for (i = 0; i < nivel; i++)
        {
            printf("      ");
        }
        printf("Chave: %d (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);
        imprimir_in_order (a->esq, nivel + 1);
        imprimir_in_order (a->dir, nivel + 1);
    }
}

