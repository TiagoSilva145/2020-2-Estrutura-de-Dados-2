#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

Arvore* cria_arvore_vazia (void)
{
    return NULL;
}

void arvore_libera (Arvore* a)
{
    if (a != NULL)
    {
        arvore_libera (a->esq);
        arvore_libera (a->dir);
        free(a);
    }
}

Arvore* inserir (Arvore *a, int v)
{
    if(a == NULL)
    {
        a = (Arvore*)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;

    }

    else if(v < a->info)
        a->esq = inserir(a->esq, v);

    else if (v > a->info)
        a->dir = inserir(a->dir, v);

    return a;
}

Arvore* remover (Arvore *a, int v)
{
    Arvore* aux = NULL;

    if(a == NULL)
        return NULL;

    else if(v < a->info)
        a->esq = remover(a->esq, v);

    else if(v > a->info)
        a->dir = remover(a->dir, v);

    else
    {
        if(a->esq == NULL && a->dir == NULL)
        {
            free(a);
            return NULL;
        }

        if(a->esq == NULL)
        {
            aux = a->dir;
            free(a);
            return aux;
        }

        if(a->dir == NULL)
        {
            aux = a->esq;
            free(a);
            return aux;
        }

        aux = a->esq;
        while(aux->dir != NULL)
            aux = aux->dir;

        a->info = aux->info;
        aux->info = v;
        a->esq = remover(a->esq, v);
    }

    return a;
}

int buscar (Arvore *a, int v)
{
    if(a != NULL)
    {
        if (a->info == v)
            return 1;

        if(v < a->info)
            return buscar(a->esq, v);

        else
            return buscar(a->dir, v);
    }

    return 0;

}

void pre_order (Arvore* a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        pre_order (a->esq);
        pre_order (a->dir);
    }
}

void in_order (Arvore* a)
{
    if (a != NULL)
    {
        in_order (a->esq);
        printf("%d ", a->info);
        in_order (a->dir);
    }
}

int min (Arvore *a)
{
    if(a->esq != NULL)
        return min(a->esq);

    return a->info;
}

int max (Arvore *a)
{
    if(a->dir != NULL)
        return max(a->dir);

    return a->info;
}

Arvore* produz_ordem(int v)
{
    Arvore* a = NULL;

    for(int i = 0; i < v; i++)
    {
        a = inserir(a,i);
    }

    return a;
}

Arvore* produz_aleatorio(int v)
{
    Arvore* a = NULL;

    for(int i = 0; i < v; i++)
    {
        a = inserir(a,rand()%v);
    }

    return a;
}

void imprime_decrescente (Arvore *a)
{
    if(a != NULL)
    {
        imprime_decrescente(a->dir);
        printf("%d ", a->info);
        imprime_decrescente(a->esq);
    }
}

int maior_ramo (Arvore *a)
{
    int soma1, soma2;

    if(a == NULL)
        return 0;

    soma1 = soma2 = a->info;

    soma1 += maior_ramo(a->esq);
    soma2 += maior_ramo(a->dir);

    if(soma1 > soma2)
        return soma1;

    return soma2;
}

int ancestral (Arvore *a, int e1, int e2)
{
    int esq, dir;

    if(a == NULL)
        return 0;

    if(a->info == e1 || a->info == e2)
        return 1;

    esq = ancestral(a->esq, e1, e2);
    dir = ancestral(a->dir, e1, e2);

    if(esq != 0 && dir != 0)
        return a->info;

    if(esq != 0)
        return esq;

    if(dir != 0)
        return dir;

    return 0;

}

int main ()
{
    clock_t ini, fim;
    double tempo;
    srand(time(NULL));

    Arvore *a = cria_arvore_vazia ();
    int e = 1;

    //Exercicio 1

    printf("---Exercicio: %d---\n\n", e++);

    a = inserir (a, 50);
    a = inserir (a, 30);
    a = inserir (a, 90);
    a = inserir (a, 20);
    a = inserir (a, 40);
    a = inserir (a, 95);
    a = inserir (a, 10);
    a = inserir (a, 35);
    a = inserir (a, 45);

    pre_order (a);
    printf("\n");

    //Exercicio 2

    printf("\n---Exercicio: %d---\n\n", e++);

    printf("Valor minimo da arvore: %d\n", min(a));
    printf("Valor maximo da arvore: %d\n", max(a));

    arvore_libera(a);
    a = NULL;

    //Exercicio 3

    printf("\n---Exercicio: %d---\n\n", e++);

    //a = produz_ordem(60000);
    a = produz_ordem(500);

    ini = clock();

    buscar(a, 500001);

    fim = clock();

    tempo = ((double) (fim - ini)) / CLOCKS_PER_SEC;

    printf("Duracao da busca arvore ordenada: %f segundos\n", tempo);

    arvore_libera(a);
    a = NULL;

    //Exercicio 4

    printf("\n---Exercicio: %d---\n\n", e++);

    a = produz_aleatorio(1000000);

    ini = clock();

    buscar(a, 10000001);

    fim = clock();

    tempo = ((double) (fim - ini)) / CLOCKS_PER_SEC;

    printf("Duracao da busca arvore aleatoria: %f segundos\n", tempo);

    arvore_libera(a);
    a = NULL;

    //Exercicio 5

    printf("\n---Exercicio: %d---\n\n", e++);

    a = inserir (a, 50);
    a = inserir (a, 30);
    a = inserir (a, 90);
    a = inserir (a, 20);
    a = inserir (a, 40);
    a = inserir (a, 95);
    a = inserir (a, 10);
    a = inserir (a, 35);
    a = inserir (a, 45);

    imprime_decrescente(a);

    //Exercicio 6

    printf("\n\n---Exercicio: %d---\n\n", e++);

    printf("Valor do maior caminho: %d\n", maior_ramo(a));

    arvore_libera(a);
    a = NULL;

    //Exercicio 7

    printf("\n---Exercicio: %d---\n\n", e++);

    int b, c;

    a = inserir (a, 20);
    a = inserir (a, 8);
    a = inserir (a, 22);
    a = inserir (a, 4);
    a = inserir (a, 12);
    a = inserir (a, 10);
    a = inserir (a, 14);

    b = 4;
    c = 14;
    printf("O ancestral em comum de maior nivel entre %d e %d eh: %d\n", b, c, ancestral(a, b, c));

    b = 4;
    c = 22;
    printf("O ancestral em comum de maior nivel entre %d e %d eh: %d\n", b, c, ancestral(a, b, c));

    b = 10;
    c = 14;
    printf("O ancestral em comum de maior nivel entre %d e %d eh: %d\n", b, c, ancestral(a, b, c));

    arvore_libera(a);
    a = NULL;

    return 0;
}


