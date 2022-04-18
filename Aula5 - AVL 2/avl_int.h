#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_int
{
    int chave;
    int altura;
    struct arvore_int* esq;
    struct arvore_int* dir;
} Arvore_int;

int maior (int esq, int dir);

int altura (Arvore_int* a);

int atualizar_altura (Arvore_int *a);

int balanceamento (Arvore_int *a);

Arvore_int* rotacao_simples_esq (Arvore_int* a);

Arvore_int* rotacao_simples_dir (Arvore_int* a);

Arvore_int* rotacao_dupla_esq (Arvore_int* a);

Arvore_int* rotacao_dupla_dir (Arvore_int* a);

Arvore_int* atualizar_fb_dir (Arvore_int *a);

Arvore_int* atualizar_fb_esq (Arvore_int *a);

Arvore_int* inserir (Arvore_int *a, int chave);

Arvore_int* remover (Arvore_int *a, int chave);

void imprimir_in_order (Arvore_int* a, int nivel);
