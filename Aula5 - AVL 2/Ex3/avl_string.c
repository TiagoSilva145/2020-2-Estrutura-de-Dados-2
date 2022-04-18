#include "avl_string.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir)
{
    return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura (Arvore_string* a)
{
    return (!a ? -1 : a->altura);
}

int atualizar_altura (Arvore_string *a)
{
    return(maior(altura(a->esq), altura(a->dir)) + 1);
}

/*----------------------*/
int balanceamento (Arvore_string *a)
{
    return(altura(a->dir) - altura(a->esq));
}

/*----------------------*/
Arvore_string* rotacao_simples_esq (Arvore_string* a)
{
    Arvore_string* aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;

    a->altura = atualizar_altura(a);
    aux->altura = atualizar_altura(aux);

    return aux;
}

/*----------------------*/
Arvore_string* rotacao_simples_dir (Arvore_string* a)
{
    Arvore_string* aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;

    a->altura = atualizar_altura(a);
    aux->altura = atualizar_altura(aux);

    return aux;
}

/*----------------------*/
Arvore_string* rotacao_dupla_esq (Arvore_string* a)
{
    a->dir = rotacao_simples_dir(a->dir);
    return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore_string* rotacao_dupla_dir (Arvore_string* a)
{
    a->esq = rotacao_simples_esq(a->esq);
    return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore_string* atualizar_fb_dir (Arvore_string *a)
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
Arvore_string* atualizar_fb_esq (Arvore_string *a)
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
Arvore_string* inserir (Arvore_string *a, char* chave)
{
    if(!a)
    {
        a = (Arvore_string*) malloc(sizeof (Arvore_string));
        a->esq = a->dir = NULL;
        a->altura = 0;
        strcpy(a->chave,chave);
    }

    else if(strcmp(chave,a->chave) < 0)
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
Arvore_string* remover (Arvore_string *a, char* chave)
{
    if (a == NULL)
    {
        return NULL;
    }
    else
    {
        if (strcmp(chave,a->chave) < 0)
        {
            a->esq = remover (a->esq, chave);
            a = atualizar_fb_dir (a);
        }
        else if (strcmp(chave,a->chave) > 0)
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
                Arvore_string *tmp = a;
                a = a->dir;
                free (tmp);
            }
            else if (a->dir == NULL)
            {
                Arvore_string *tmp = a;
                a = a->esq;
                free (tmp);
            }
            else
            {
                Arvore_string *tmp = a->esq;
                while (tmp->dir != NULL)
                {
                    tmp = tmp->dir;
                }
                strcpy(a->chave,chave);
                strcpy(a->chave,chave);
                a->esq = remover (a->esq, chave);
                a = atualizar_fb_dir (a);
            }
        }
        return a;
    }
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order (Arvore_string* a, int nivel)
{
    if (a != NULL)
    {
        int i;
        for (i = 0; i < nivel; i++)
        {
            printf("      ");
        }
        printf("Chave: %s (altura: %d, fb: %+d) Arvore_string nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);
        imprimir_in_order (a->esq, nivel + 1);
        imprimir_in_order (a->dir, nivel + 1);
    }
}

