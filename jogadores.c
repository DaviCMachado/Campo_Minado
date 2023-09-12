#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "jogadores.h"


int vazia_JOGADORES (jogadores *LISTA_JOGADORES )
{
    if(LISTA_JOGADORES->prox == NULL)
        return 1;
    else
        return 0;
}

void insere_Jogador (jogadores *LISTA_JOGADORES)
{
    jogadores *novo = (jogadores *) malloc(sizeof(jogadores));
    

    printf("Nome do Jogador: ");
    scanf (" %s", &novo->nome);

    printf("Numero da camisa: ");
    scanf (" %d", &novo->num);
 
    printf("Idade: ");
    scanf (" %d", &novo->idade);

    printf("Posicao: ");
    scanf (" %s", &novo->posicao);

    novo->prox = NULL;
  
    if(vazia_JOGADORES(LISTA_JOGADORES))
    {
        LISTA_JOGADORES->prox = novo;
        novo->ant = LISTA_JOGADORES;
        novo->index = 1;
        novo->titular = 1;
    }

    else
    {
        jogadores *atual = LISTA_JOGADORES->prox;
        
        while(atual->prox != NULL)
            atual = atual->prox;

        atual->prox = novo;
        novo->ant = atual;
        novo->index = novo->ant->index + 1;
        novo->titular = novo->ant->titular + 1;
    }
}



void exibe_Jogadores (time *LISTA_TIMES)
{
    jogadores *atual;
    atual = LISTA_TIMES->LISTA_JOGADORES->prox;

    while(atual != NULL){
        printf("%d:", atual->index);
        printf("%s\n", atual->nome);
        atual = atual->prox;
    }
    printf("\n");

}

