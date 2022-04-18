#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct _no {
   int id;           /*Identificador armazenado no nó. */
   struct _no *next; /*Próximo nó na lista encadeada. */
   int w;            /*Peso da aresta. */
} nodo;

/*Estrutura de Grafo representado por uma lista de adjacências: */
typedef struct {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   nodo **Adj; /* Lista de adjacências. */
} grafo_lista;

/*Função para criar um grafo representado como uma lista de adjacências.*/
grafo_lista* create_graph (int tamanho) {
   int v;
   grafo_lista *G = (grafo_lista *)malloc(sizeof(grafo_lista));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (nodo **)malloc(tamanho * sizeof(nodo *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL; /*Inicializando cada uma das listas encadeadas de adjacência!*/
   }
   return G;
}

/*Função para destruir um grafo construído como uma lista de adjacências.*/
void destroy_graph (grafo_lista *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para mostrar um grafo construído como uma matriz de adjacências.*/
void show_graph (grafo_lista *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      nodo *u;
      printf ("%d -> ", v);
      for (u = G->Adj[v]; u != NULL; u = u->next) {
         printf ("%d ", u->id);
      }
      printf("\n");
   }
}

/*Função auxiliar para adicionar uma aresta em um grafo representado por uma lista de adjacências.*/
void _add_edge (int i, int j, grafo_lista *G) {
   nodo *aux, *ultimo = NULL;
   for (aux = G->Adj[i]; aux != NULL; aux = aux->next) {
      if (aux->id == j) {
         printf("A aresta já existe!\n");
         return;
      }
      ultimo = aux;
   }
   nodo *novo = (nodo *)malloc(sizeof(nodo));
   novo->id = j;
   novo->next = NULL;
   if (ultimo != NULL)
      ultimo->next = novo;
   else {
      G->Adj[i] = novo;
   }
}

/*Função para adicionar uma aresta em um grafo (direcionado ou não direcionado) representado por uma lista de adjacências.*/
void add_edge (int i, int j, grafo_lista *G) {
   _add_edge (i, j, G);
   _add_edge (j, i, G); /*Direcionado ou não?*/
   G->E++; /*Mais uma aresta no grafo!*/
}

void _add_edge_weight (int i, int j, int w, grafo_lista *G) {
   nodo *aux, *ultimo = NULL;
   for (aux = G->Adj[i]; aux != NULL; aux = aux->next) {
      if (aux->id == j) {
         printf("A aresta já existe!\n");
         return;
      }
      ultimo = aux;
   }
   nodo *novo = (nodo *)malloc(sizeof(nodo));
   novo->id = j;
   novo->next = NULL;
   novo->w = w;
   if (ultimo != NULL)
      ultimo->next = novo;
   else {
      G->Adj[i] = novo;
   }
}

void show_graph_weight (grafo_lista *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      nodo *u;
      printf ("%d -> ", v);
      for (u = G->Adj[v]; u != NULL; u = u->next) {
         printf ("%d (w: %d) ", u->id, u->w);
      }
      printf("\n");
   }
}

int lista_incidentes(int j, int tam, grafo_lista *G)
{
    int cont = 0;
    for(int i = 0; i < tam; i++)
    {
        for(nodo* aux = G->Adj[i]; aux; aux = aux->next)
            if(aux->id == j)
            {
                cont++;
                break;
            }
    }

    return cont;
}

int lista_saem(int i, grafo_lista *G)
{
    int cont = 0;
    for(nodo* aux = G->Adj[i]; aux; aux = aux->next)
        cont++;

    return cont;
}

void vertices_adj(int i, grafo_lista *G)
{
    for(nodo* aux = G->Adj[i]; aux; aux = aux->next)
        printf("%d ", aux->id);
    printf("\n");
}

void inverte_graph(int tam, grafo_lista *G1, grafo_lista *G2)
{
    for(int i = 0; i < tam; i++)
    {
        for(nodo* aux = G2->Adj[i]; aux; aux = aux->next)
            _add_edge(aux->id,i,G1);
    }
}

/*Função principal.*/
int main () {

   int V = 6; /*Número de vértices*/

   printf("-----------Exercicio 1:\n");
    grafo_lista *G1 = create_graph (V);
    add_edge(0,1,G1);
    add_edge(0,2,G1);
    add_edge(0,5,G1);
    add_edge(1,2,G1);
    add_edge(1,3,G1);
    add_edge(2,3,G1);
    add_edge(2,4,G1);
    add_edge(3,4,G1);
    add_edge(4,5,G1);
    show_graph (G1);
    printf("\n");

    printf("-----------Exercicio 2:\n");
    grafo_lista *G2 = create_graph (V);
    _add_edge(0,1,G2);
    _add_edge(0,5,G2);
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
    grafo_lista *G3 = create_graph (V);
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
    show_graph_weight(G3);
    printf("\n");
    printf("Numero de arestas incidentes ao vertice 3: %d.\n", lista_incidentes(3,V,G3));
    printf("Numero de arestas que saem do vertice 4: %d.\n", lista_saem(4,G3));
    printf("Vertices adjacentes ao vertice 2: ");
    vertices_adj(2,G3);

    printf("-----------Exercicio 4:\n");
    grafo_lista *G4 = create_graph (V);
    inverte_graph(V,G4,G2);
    show_graph (G4);
    printf("\n");

    destroy_graph (G1);
    destroy_graph (G2);
    destroy_graph (G3);
    destroy_graph (G4);

   return 0;
}

