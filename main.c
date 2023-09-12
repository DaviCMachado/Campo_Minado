#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "campeonato.c"


int main(void)
{
    time *LISTA_TIMES = (time *) malloc(sizeof(time)); 
    partidas *LISTA_PARTIDAS = (partidas *) malloc(sizeof(partidas)); 

    LISTA_PARTIDAS->prox = NULL;
    LISTA_PARTIDAS->rodada = 0;

    LISTA_TIMES->prox = NULL;
    LISTA_TIMES->ant = NULL;
    
    int opt;
 
    do{
        opt = menu_principal ();
        opcao_principal (LISTA_TIMES, LISTA_PARTIDAS, opt);
    }while(opt);

    free(LISTA_TIMES);
    return 0;
}


