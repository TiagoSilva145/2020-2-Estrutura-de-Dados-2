#include <stdio.h>
#include <stdlib.h>

int pai (int i)
{
    return (i - 1)/2;
}

int esquerda (int i)
{
    return (i * 2) + 1;
}

int direita (int i)
{
    return (i * 2) + 2;
}

void trocar (int v[], int a, int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void imprimir (int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void min_heapify (int v[], int tam, int i)
{
    int e = esquerda(i);
    int d = direita(i);
    int menor = i;

    if(e < tam && v[e] < v[menor])
        menor = e;
    if(d < tam && v[d] < v[menor])
        menor = d;

    if(menor != i)
    {
        trocar(v, menor, i);
        min_heapify(v,tam,menor);
    }
}

void build_min_heap (int v[], int tam)
{
    for(int i = tam/2; i > -1; i--)
        min_heapify(v, tam, i);
}

int heap_extract_min (int v[], int *tam)
{
    if(*tam < 1)
        printf("Erro, um unico elemento no heap\n");

    int min = v[0];

    v[0] = v[*tam - 1];
    (*tam)--;

    min_heapify(v,*tam,0);

    return min;
}

void heap_decrease_key (int v[], int i, int chave, int tam)
{
    int p = pai(i);

    if(v[i] < chave)
    {
        printf("Impossivel diminuir, a chave eh maior que o v[i]");
        return;
    }

    v[i] = chave;

    while(i > 0 && v[p] > v[i])
    {
        trocar(v,i,p);
        min_heapify(v,tam,i);
        i = p;
        p = pai(i);
    }
}

void min_heap_insert (int v[], int chave, int *tam)
{
    v[*tam] = chave;
    (*tam)++;

    heap_decrease_key(v,(*tam)-1,chave,*tam);
}

int main ()
{

    int tam = 10;

    int v[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    imprimir (v, tam);

    build_min_heap (v, tam);

    imprimir (v, tam);

    heap_extract_min (v, &tam);

    imprimir (v, tam);

    /*Modificando a última chave {16} para o valor {1}!*/
    heap_decrease_key (v, tam-1, 1, tam);

    imprimir (v, tam);

    /*Inserindo uma nova chave com valor {0}!*/
    min_heap_insert (v, 0, &tam);

    imprimir (v, tam);

    return 0;
}


