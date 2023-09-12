#ifndef TIMES_H
#define TIMES_H

#include "jogadores.h"

typedef struct tim
{
    int num, index, jogos, pontos, GP, GS, SG, V, E, D;
    char nome[30], cidade[30], estadio[30], treinador[30];
    struct tim *prox;
    struct tim *ant;
    jogadores *LISTA_JOGADORES;
}time; 


void exclui (time *LISTA_TIMES);
void init_team (time *novo);
int vazia (time *LISTA_TIMES);
int menu_principal (void);
void insereFim (time *LISTA_TIMES);
void editaIndex (time *LISTA_TIMES, int id);
void exibe (time *LISTA_TIMES);
void exibeInfo (time *LISTA_TIMES);
void exibe_Jogadores (time* LISTA_TIMES);
void libera (time *LISTA_TIMES);

#endif 