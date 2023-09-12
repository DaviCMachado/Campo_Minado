#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include "partidas.c"
 
typedef struct stat{

    char tipo[20];
    jogadores *autor;
    struct stat *prox;

}stats; 


void exibe_stats (partidas *LISTA_PARTIDAS);
void exibe_tabela (time *LISTA_TIMES);
void ordena_tabela (time *LISTA_TIMES);
time *copiaLista(time *LISTA_TIMES);
time *copiaTime(time *original);



#endif