#include <stdio.h>
#include <stdlib.h>

/*Estrutura de Grafo representado por uma matriz de adjacências: */
typedef struct grafo
{
    int E; /* Quantidade de arestas. */
    int V; /* Quantidade de vértices. */
    int **Mat; /* Matrix de adjacências. */
} grafo_matrix;

/*Função para criar um grafo representado como uma matriz de adjacências.*/
grafo_matrix* create_graph (int tamanho)
{
    int v;
    grafo_matrix *G = (grafo_matrix *)malloc(sizeof(grafo_matrix));
    G->E = 0;
    G->V = tamanho;
    G->Mat = (int **)malloc(tamanho * sizeof(int *));
    for (v = 0; v < G->V; v++)
    {
        G->Mat[v] = (int *)calloc(tamanho, sizeof(int));
    }
    return G;
}

/*Função para destruir um grafo construído como uma matriz de adjacências.*/
void destroy_graph (grafo_matrix *G)
{
    int v;
    for (v = 0; v < G->V; v++)
    {
        free(G->Mat[v]);
    }
    free(G->Mat);
    free(G);
}

/*Função para mostrar um grafo construído como uma matriz de adjacências.*/
void show_graph (grafo_matrix *G)
{
    int u, v;
    for (u = 0; u < G->V; u++)
    {
        for (v = 0; v < G->V; v++)
        {
            printf("%d ", G->Mat[u][v]);
        }
        printf("\n");
    }
}

/*Função auxiliar para adicionar uma aresta em um grafo representado por uma matriz de adjacências.*/
void _add_edge (int i, int j, grafo_matrix *G)
{
    if (G->Mat[i][j])
    {
        printf("A aresta já existe!\n");
    }
    else
    {
        G->Mat[i][j] = 1;
    }
}

/*Função para adicionar uma aresta em um grafo (direcionado ou não direcionado) representado por uma matriz de adjacências.*/
void add_edge (int i, int j, grafo_matrix *G)
{
    _add_edge (i, j, G);
    _add_edge (j, i, G); /*Direcionado ou não?*/
    G->E++; /*Mais uma aresta no grafo!*/
}

void _add_edge_weight (int i, int j, int w, grafo_matrix *G)
{
    if (G->Mat[i][j])
    {
        printf("A aresta já existe!\n");
    }
    else
    {
        G->Mat[i][j] = w;
    }
}

int lista_incidentes(int j, int tam, grafo_matrix *G)
{
    int n = 0;

    for(int i = 0; i < tam; i++)
        if(G->Mat[i][j] != 0)
            n++;

    return n;
}

int lista_saem(int i, int tam, grafo_matrix *G)
{
    int n = 0;

    for(int j = 0; j < tam; j++)
        if(G->Mat[i][j] != 0)
            n++;

    return n;
}

void vertices_adj(int i, int tam, grafo_matrix *G)
{
    int n = 0;

    for(int j = 0; j < tam; j++)
        if(G->Mat[i][j] != 0)
            printf("%d ", j);

    printf("\n");
}

void inverte_graph(int tam, grafo_matrix *G1, grafo_matrix *G2)
{
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            if(G2->Mat[i][j] != 0)
                G1->Mat[j][i] = 1;
}


/*Função principal.*/
int main ()
{

    int V = 6; /*Número de vértices*/

    printf("-----------Exercicio 1:\n");
    grafo_matrix *G1 = create_graph (V);
    add_edge(0,5,G1);
    add_edge(0,1,G1);
    add_edge(0,2,G1);
    add_edge(1,2,G1);
    add_edge(1,3,G1);
    add_edge(2,3,G1);
    add_edge(2,4,G1);
    add_edge(3,4,G1);
    add_edge(4,5,G1);
    show_graph (G1);
    printf("\n");

    printf("-----------Exercicio 2:\n");
    grafo_matrix *G2 = create_graph (V);
    _add_edge(0,5,G2);
    _add_edge(0,1,G2);
    _add_edge(1,2,G2);
    _add_edge(1,3,G2);
    _add_edge(2,0,G2);
    _add_edge(2,4,G2);
    _add_edge(3,2,G2);
    _add_edge(4,3,G2);
    _add_edge(5,4,G2);
    show_graph (G2);
    printf("\n");

    printf("-----------Exercicio 3:\n");
    grafo_matrix *G3 = create_graph (V);
    _add_edge_weight(0,1,1,G3);
    _add_edge_weight(0,3,5,G3);
    _add_edge_weight(1,3,8,G3);
    _add_edge_weight(2,0,5,G3);
    _add_edge_weight(2,3,4,G3);
    _add_edge_weight(3,3,6,G3);
    _add_edge_weight(3,4,3,G3);
    _add_edge_weight(4,2,7,G3);
    _add_edge_weight(4,5,9,G3);
    _add_edge_weight(5,0,2,G3);
    show_graph (G3);
    printf("\n");
    printf("Numero de arestas incidentes ao vertice 3: %d.\n", lista_incidentes(3,V,G3));
    printf("Numero de arestas que saem do vertice 4: %d.\n", lista_saem(4,V,G3));
    printf("Vertices adjacentes ao vertice 2: ");
    vertices_adj(2,V,G3);

    printf("-----------Exercicio 4:\n");
    grafo_matrix *G4 = create_graph (V);
    inverte_graph(V,G4,G2);
    show_graph (G4);
    printf("\n");

    destroy_graph (G1);
    destroy_graph (G2);
    destroy_graph (G3);
    destroy_graph (G4);

    return 0;
}

