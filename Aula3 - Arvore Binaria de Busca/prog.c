#include "arvore.h"

void arvore_libera (Arvore* a)
{
    if (a != NULL)
    {
        arvore_libera (a->esq);
        arvore_libera (a->dir);
        free(a);
    }
}

void imprimir_in_ordem (Arvore *a)
{
    if (a != NULL)
    {
        imprimir_in_ordem (a->esq);
        printf ("%d ", a->info);
        imprimir_in_ordem (a->dir);
    }
}

void imprime_decrescente (Arvore* a)
{
    if(!a)
        return;

    imprime_decrescente(a->dir);
    printf("%d ", a->info);
    imprime_decrescente(a->esq);

    return;
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

int min(Arvore* a)
{
    if(!a)
    {
        printf("Arvore vazia\n");
        return 0;
    }
    while(a->esq)
        a = a->esq;

    printf("Valor minimo da arvore: %d\n", a->info);

    return a->info;
}

int max(Arvore* a)
{
    if(!a)
    {
        printf("Arvore vazia\n");
        return 0;
    }
    while(a->dir)
        a = a->dir;

    printf("Valor maximo da arvore: %d\n", a->info);

    return a->info;
}

int q_maiores(Arvore* a, int v)
{
    int i = 1;

    if(!a)
        return 0;

    if(a->info <= v)
    {
        i = 0;
        return i + q_maiores(a->dir, v);
    }

    return i + q_maiores(a->dir, v) + q_maiores(a->esq, v);


}

int main ()
{
    int e = 1, tam = 0;
    double ini = 0, fim = 0, tempo = 0;
    Arvore *a = NULL;
    a = inserir (a, 50);
    a = inserir (a, 30);
    a = inserir (a, 90);
    a = inserir (a, 20);
    a = inserir (a, 40);
    a = inserir (a, 95);
    a = inserir (a, 10);
    a = inserir (a, 35);
    a = inserir (a, 45);
    imprimir_in_ordem (a);

    arvore_libera(a);
    a = NULL;

//----------------------  Ex1 ----------------------//

    printf("\n---Exercicio: %d---\n\n", e++);

    ini = clock();

    tam = 60000;
    a = produz_ordem(tam); // Com 100000 excede a memoria
    // a = produz_ordem(60000);

    buscar(a, 500001);

    fim = clock();

    tempo = ((double) (fim - ini)) / CLOCKS_PER_SEC;

    printf("Duracao da insercao e busca na arvore ordenada com %d elementos: %f segundos\n", tam, tempo);

    arvore_libera(a);
    a = NULL;

//----------------------  Ex2 ----------------------//

    printf("\n---Exercicio: %d---\n\n", e++);

    ini = clock();

    tam = 100000;
    a = produz_aleatorio(tam); // Com 100000 excede a memoria

    buscar(a, 500001);

    fim = clock();

    tempo = ((double) (fim - ini)) / CLOCKS_PER_SEC;

    printf("Duracao da insercao e busca na arvore aleatoria com %d elementos: %f segundos\n", tam, tempo);

    printf("A discrepancia de tempo eh tamanha pois inserindo em ordem a arvore vira degenerada, aumentando muito a complexidade das insercoes e busca\n");
    arvore_libera(a);
    a = NULL;

//----------------------  Ex3 ----------------------//

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

    min(a);
    max(a);

//----------------------  Ex4 ----------------------//

    printf("\n---Exercicio: %d---\n\n", e++);

    printf("Arvore em ordem decrescente: ");
    imprime_decrescente(a);
    printf("\n");

//----------------------  Ex5 ----------------------//

    printf("\n---Exercicio: %d---\n\n", e++);

    printf("Calcular quantos valores maiores que n tem na arvore: \n");

    printf("N = 15: %d valores maiores\n", q_maiores(a,15));
    printf("N = 40: %d valores maiores\n", q_maiores(a,40));
    printf("N = 0: %d valores maiores\n", q_maiores(a,0));
    printf("N = 90: %d valores maiores\n", q_maiores(a,90));

    return 0;
}

