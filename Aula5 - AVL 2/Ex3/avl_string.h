#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore_string
{
    char chave[50];
    int altura;
    struct arvore_string* esq;
    struct arvore_string* dir;
} Arvore_string;

int maior (int esq, int dir);

int altura (Arvore_string* a);

int atualizar_altura (Arvore_string *a);

int balanceamento (Arvore_string *a);

Arvore_string* rotacao_simples_esq (Arvore_string* a);

Arvore_string* rotacao_simples_dir (Arvore_string* a);

Arvore_string* rotacao_dupla_esq (Arvore_string* a);

Arvore_string* rotacao_dupla_dir (Arvore_string* a);

Arvore_string* atualizar_fb_dir (Arvore_string *a);

Arvore_string* atualizar_fb_esq (Arvore_string *a);

Arvore_string* inserir (Arvore_string *a, char* chave);

Arvore_string* remover (Arvore_string *a, char* chave);

void imprimir_in_order (Arvore_string* a, int nivel);
