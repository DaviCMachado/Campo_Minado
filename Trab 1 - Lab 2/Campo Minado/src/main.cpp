/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp

//  Todos os arquivos do projeto devem ser .cpp
//
//  Versao 2.0
//
// *********************************************************************/

#include <limits.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

#include "auxiliar.h"

#define MENU 0
#define JOGANDO 1
#define FIM 2

#include "timer.h"
#include "menu.h"
#include "IA.h"
#include "matrix.h"
#include "cursor.h"

//variaveis globais
int screenWidth = 800, screenHeight = 600; //largura e altura inicial da tela. Alteram com o redimensionamento de tela.
int mx, my; //variaveis globais do mouse para poder exibir dentro da render().
clock_t begin, end;

void jogar(){

    init();

    double time_spent = 0.0;

    end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    if (jogo.estado == 1)
    {
        timer(time_spent);
        jogo.time = time_spent;
    }

    if (jogo.estado == 2)
        timer(jogo.time);
}



void DrawMouseScreenCoords()
{
    char str[100];
    sprintf(str, "Mouse: (%d,%d)", mx, my);
    CV::text(10,300, str);
    sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
    CV::text(10,320, str);
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
    CV::clear(255,255,255);

    CV::color(0);

    jogar();


}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   printf("\nTecla: %d" , key);

   switch(key)
   {
      case 27: //finaliza programa
	     endgame();
        break;

   }
}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{

}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{

    printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

    if(jogo.estado == 0 && state == 0 && mx > startX && mx < (startX + 80) && my > startY + 20 && my < (startY + 60))
    {
        jogo.estado = 1;
        begin = clock();
    }

    if(jogo.estado == 0 && state == 0 && mx > (startX + 150) && mx < (startX + 190) && (my > startY - 300 )&& my < (startY - 260) && jogo.tam < 12)
    {
        lobby();
        jogo.tam += 1;
    }

    if(jogo.tam > 2 && (((jogo.tam -1)*(jogo.tam-1)) > jogo.bombas) && jogo.estado == 0 && state == 0 && mx > (startX + 150) && mx < (startX + 190) && (my > startY - 340 )&& my < startY - 300)
    {
        lobby();
        jogo.tam -= 1;
    }

    if(jogo.estado == 1 && state == 0 && mx > tabX && mx < (tabX + (40 * jogo.tam)) && my > (tabY - (40 * jogo.tam)) && my < tabY)
    {
        int a, b;

        a = (int)(mx - tabX) /40;
        b = (int)( - my + tabY) /40;

        if (button == 2)
        {
            if (mat[b][a].bandeira == 0)
            {
                mat[b][a].bandeira = 1;
            }
            else
            {
                mat[b][a].bandeira = 0;
            }
        }

        else
        {
            if (mat[b][a].aberto == 0)
            {
                mat[b][a].aberto = 1;
                    if (mat[b][a].bomba == 1)
                        jogo.estado = 2;
            }
        }

    }

    if((jogo.estado == 1 || jogo.estado == 2) && state == 0 && mx > startX && mx < (startX + 150) && (my > startY - 40 )&& my < (startY))
        lobby();

    if(jogo.estado == 0 && jogo.bombas < ((jogo.tam * jogo.tam) - 1) && state == 0 && mx > (startX + 150) && mx < (startX + 190) && (my > startY - 140 )&& my < (startY - 100))
    {
        lobby();
        jogo.bombas += 1;
    }

    if(jogo.bombas > 1 && jogo.estado == 0 && state == 0 && mx > (startX + 150) && mx < (startX + 190) && (my > startY - 180 )&& my < startY - 140)
    {
        lobby();
        jogo.bombas -= 1;
    }

    if(jogo.estado == 0 && state == 0 && mx > startX + 100 && mx < (startX + 180) && my > startY + 20 && my < (startY + 60))
    {
        jogo.estado = 1;
        begin = clock();
        jogo.ia = 1;
    }

   mx = x; //guarda as coordenadas do mouse para exibir dentro da render()
   my = y;
}

int main(void)
{
    CV::init(&screenWidth, &screenHeight, "Campo Minado");

    CV::run();
}
