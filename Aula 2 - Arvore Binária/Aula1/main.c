#include "arvore.h"

int main()
{
    Arvore *a = constroi_arv ('a',
        constroi_arv('b',
            cria_arv_vazia(),
            constroi_arv('d',cria_arv_vazia(),cria_arv_vazia())
        ),
        constroi_arv('c',
            constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
            constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
        )
    );

    //Exercicio 1

    printf("Pre-order: ");
    preordem(a);
    printf("\n");

    printf("In-order: ");
    inordem(a);
    printf("\n");

    printf("Pos-order: ");
    posordem(a);
    printf("\n");

    //Exercicio 2

    printf("Imprime arvore marcadores: ");
    imprime_arv_marcadores(a);
    printf("\n");

    //Exercicio 3

    char c = 'b';

    printf("O caractere %c esta na arvore? ", c);

    if(pertence_arv (a,c))
        printf("Sim");
    else
        printf("Nao");

    printf("\n");

    //Exercicio 4

    printf("Numero de nos na arvore: ");
    printf("%d", conta_nos(a));
    printf("\n");

    //Exercicio 5

    printf("Altura da arvore: ");
    printf("%d", calcula_altura_arvore(a));
    printf("\n");

    //Exercicio 6

    printf("\n------Exercicio proposto: criar uma funcao para contar a quantidade de nos folha na arvore------\n");
    printf("Numero de nos folha na arvore: ");
    printf("%d", conta_nos_folha(a));
    printf("\n");

    return 0;
}
