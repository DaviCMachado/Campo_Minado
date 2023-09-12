#ifndef JOGADORES_H
#define JOGADORES_H
 

typedef struct jog
{
    int num, idade, gols, assists, yellow, red, faltas, index, titular;
    char nome[30], posicao[30];
    struct jog *prox;
    struct jog *ant;

}jogadores; 

int vazia_JOGADORES (jogadores* LISTA_JOGADORES );
void insere_Jogador (jogadores* LISTA_JOGADORES );

#endif 