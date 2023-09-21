#ifndef CURSOR_H_INCLUDED
#define CURSOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define tabX 80
#define tabY 550
#define startX 580
#define startY 450

void exibe(int n){

    CV::rect(tabX, tabY, tabX + (40 * n), tabY - (40 * n)); // TABULEIRO

    for (int i = 0; i < n; i++){
        CV::line(tabX, tabY - (40 * i) , tabX + 40 * n, tabY - (40 * i)); // LINHAS DO TABULEIRO
        CV::line(tabX + (40 * i), tabY, tabX + (40 * i), tabY - (40 * n));

    }

    CV::text(startX + 20, startY -240, "Tabuleiro:");
    CV::rect(startX, startY - 360, startX + 200, startY - 220);

    CV::rect(startX + 150, startY - 300, startX + 190, startY - 260);    // BOTAO DE AUMENTAR O TABULEIRO
    CV::rect(startX + 150, startY - 340, startX + 190, startY - 300);    // BOTAO DE DIMINUIR O TABULEIRO

    CV::text(startX + 20, startY -280, "Aumentar -->" );
    CV::text(startX + 20, startY -320, "Diminuir -->" );

    CV::text(startX + 40, startY -80, "Bombas:");
    CV::rect(startX, startY - 200, startX + 200, startY - 60);

    CV::rect(startX + 150, startY - 140, startX + 190, startY - 100);    // BOTAO DE AUMENTAR BOMBAS
    CV::rect(startX + 150, startY - 180, startX + 190, startY - 140);    // BOTAO DE DIMINUIR BOMBAS

    CV::text(startX + 20, startY -120, "Aumentar -->" );
    CV::text(startX + 20, startY -160, "Diminuir -->" );

    CV::rect(startX, startY - 40, startX + 150, startY);   // BOTAO DE VOLTAR AO MENU
    CV::text(startX + 5, startY - 30, "Voltar ao menu");

}

#endif
