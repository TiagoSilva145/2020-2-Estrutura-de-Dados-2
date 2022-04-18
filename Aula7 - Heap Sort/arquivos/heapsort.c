#include <stdio.h>

int pai (int i)
{
    return (i - 1)/2;
}

int esquerda(int i)
{
    return i*2 + 1;
}

int direita(int i)
{
    return i*2 + 2;
}

void trocar (int V[], int a, int b)
{
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir (int V[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void max_heapify (int V[], int size, int i)
{
    int maior = i;
    int e = esquerda(i);
    int d = direita(i);

    if(e < size && V[maior] < V[e])
        maior = e;
    if(d < size && V[maior] < V[d])
        maior = d;

    if(maior != i)
    {
        trocar(V, maior, i);
        max_heapify(V, size, maior);
    }
}

void build_max_heap (int V[], int size)
{
    for(int i = size/2; i > -1; i--)
        max_heapify(V, size, i);
}

void heap_sort (int V[], int size)
{
    build_max_heap(V,size);

    for(int i = size; i > 0; i--)
    {
        size--;
        trocar(V, 0, size);
        max_heapify(V,size,0);
    }
}

int main ()
{

    int i;

    int size = 10;

    int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    printf("Vetor inicial : ");
    imprimir (V, size);

    heap_sort (V, size);

    printf("Vetor ordenado: ");
    imprimir (V, size);

    return 0;
}
