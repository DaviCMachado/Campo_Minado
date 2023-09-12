#ifndef PARTIDAS_H
#define PARTIDAS_H

#include "times.h"
 
typedef struct part
{
    int id_partida, rodada, gol_casa, gol_fora;
    char relatorio[10000];
    time *casa;
    time *fora;
    struct part *prox;
    struct part *ant;
    
}partidas; 

void opcao_stats (partidas *PARTIDAS, int opt);
void finaliza_partida (partidas *PARTIDA);
void opcao_principal (time *LISTA_TIMES, partidas *LISTA_PARTIDAS, int op);
void stats_partida (partidas *LISTA_PARTIDAS);
void nova_partida (partidas *LISTA_PARTIDAS, int rodada, time *LISTA_TIMES);
void exclui_partida (partidas *LISTA_PARTIDAS, int rodada, int id);
void add_stats(partidas *LISTA_PARTIDAS, int opt);
void edita_partidas(partidas *LISTA_PARTIDAS, int rodada, int id);
void exibe_partidas(partidas *LISTA_PARTIDAS);
int menu_partidas ();
void opcao_partidas(time *LISTA_TIMES, partidas *LISTA_PARTIDAS);
void relatorio_partidas(partidas *LISTA_PARTIDAS);
void libera_partidas(partidas *LISTA_PARTIDAS);

#endif 


