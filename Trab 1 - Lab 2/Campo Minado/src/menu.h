#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "timer.h"
#include "matrix.h"
#include "cursor.h"
#define startX 580
#define startY 450

#define overX 580
#define overY 480
#include "IA.h"


typedef struct{

    int estado = 0, tab = 0, tam = 5, time = 0, venceu = 0, ia = 0, init = 0;
    int alocado = 0, bombas = 10;

}Jogo;

Jogo jogo;


void gameOver()
{


    CV::rect(overX, overY, overX + 150, overY + 60);

    if (jogo.venceu == 0)
        CV::text(overX + 10, overY + 20, "GAME OVER!!!");
    else
        CV::text(overX + 10, overY + 20, "VOCE VENCEU!!!");

}

void init(){


    exibe(jogo.tam);

    CV::text(startX + 130, startY -80, jogo.bombas);  // Mostra o numero de bombas

    CV::text(startX + 125, startY -240, jogo.tam);  // Mostra o numero do tabuleiro
    CV::text(startX + 150, startY -240, "x");
    CV::text(startX + 170, startY -240, jogo.tam);  // Mostra o numero do tabuleiro


    if (jogo.estado == 0){

        CV::rect(startX, startY + 20, startX + 80, startY + 60);  // BOTAO DE INICIAR
        CV::text(startX + 5, startY + 40, "Iniciar");

        CV::rect(startX + 100, startY + 20, startX + 180, startY + 60);  // BOTAO DE INICIAR
        CV::text(startX + 105, startY + 40, "Modo IA");

        if (jogo.alocado == 0){
            aloca(jogo.tam);
            jogo.alocado = 1;
        }
    }

    if (jogo.estado == 1 && jogo.alocado == 1){

        if (jogo.tab == 0){
            cria(jogo.tam, jogo.bombas);    // FUNÇÃO DA MATRIX.H
            jogo.tab = 1;
        }
        if (jogo.tab == 1)
            abre(jogo.tam);

         if (jogo.ia == 1 && jogo.tab == 1)
        {

           // jogo.estado = test(jogo.tam);
             test(jogo.tam);
        }


        int ab = 0;
        for (int i = 0; i < jogo.tam; i++)
            for (int j = 0; j < jogo.tam; j++)
                if(mat[i][j].aberto == 1 && mat[i][j].bomba == 0)
                    ab += 1;

        if (ab + jogo.bombas == (jogo.tam * jogo.tam))
        {
            jogo.venceu = 1;
            jogo.estado = 2;
        }
    }

    if (jogo.estado == 2 && jogo.alocado == 1)
    {
        abre(jogo.tam);
        gameOver();

    }
}

void endgame()
{
    for(int i = 0; i < jogo.tam; i++)
        free(mat[i]);

    free(mat);
    exit(0);
}

void lobby()
{

    for(int i = 0; i < jogo.tam; i++)
        free(mat[i]);

    free(mat);

    jogo.estado = 0;
    jogo.tab = 0;
    jogo.alocado = 0;
    jogo.venceu = 0;
    jogo.ia = 0;
}

#endif
