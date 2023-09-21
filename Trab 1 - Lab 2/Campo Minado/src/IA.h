#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED
#include "menu.h"
#include "matrix.h"
#include <time.h>

typedef struct {
    int newI, newJ, oldI, oldJ;
    int first;
    char dir, oldDir;
} Cord;

Cord cord = {0, 0, 0, 0, 0, 'b'};

int test(int n) {
    int i;
    int j;
    int a, b;

    i = cord.newI;
    j = cord.newJ;

    if (!cord.first) {
        // Encontra a primeira célula não revelada que não seja uma bomba
        a = rand() % n;
        b = rand() % n;
        while (mat[a][b].bomba)
        {
            a = rand() % n;
            b = rand() % n;
        }
        i = a;
        j = b;
        cord.first = 1;
    }

     for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j].ultimo = 0;

    mat[cord.oldI][cord.oldJ].ultimo = 1;

    mat[i][j].aberto = 1;
    mat[i][j].ultimo = 1;

    if (mat[i][j].bomba)
    {
        Sleep(500);
        return 2; // Perdeu
    }

    Sleep(700);

    cord.newI = i;
    cord.newJ = j;

    char dir = 'x';

    int menor, C, E, D, B;

    menor = 10;
    D = 0;
    E = 0;
    C = 0;
    B = 0;


    if (i > 0)
    {
        if (j > 0)
            if (mat[i-1][j-1].aberto)
            {
                C += mat[i-1][j-1].vizinhos;
                E += mat[i-1][j-1].vizinhos;
            }

            if (j < n - 1)
                if (mat[i-1][j+1].aberto)
                {
                    C += mat[i-1][j+1].vizinhos;
                    D += mat[i-1][j+1].vizinhos;
                }
    }

    if (i < n - 1)
    {
        if (j > 0)
            if (mat[i+1][j-1].aberto)
            {
                B += mat[i+1][j-1].vizinhos;
                E += mat[i+1][j-1].vizinhos;
            }
        if (j < n - 1)
            if (mat[i+1][j+1].aberto)
            {
                B += mat[i+1][j+1].vizinhos;
                D += mat[i+1][j+1].vizinhos;
            }
    }

    if ((mat[i][j].abertas <= mat[i][j].vizinhos) || mat[i][j].vizinhos < 2)
    {
        if(C < menor && i > 0)
            if (!mat[i-1][j].aberto)
                dir = 'c';

        if(B < menor && i < n-1)
            if (!mat[i+1][j].aberto)
                dir = 'b';

        if(E < menor && j > 0)
            if (!mat[i][j-1].aberto)
                dir = 'e';

        if(D < menor && j < n-1)
            if (!mat[i][j+1].aberto)
                dir = 'd';
    }

    if (dir == 'c')
        if (i > 0)
            cord.newI -= 1;

    if (dir == 'b')
        if (i < n-1)
            cord.newI += 1;

    if (dir == 'e')
        if (j > 0)
            cord.newJ -= 1;

    if (dir == 'd')
        if (j < n-1)
            cord.newJ += 1;

    if (mat[i][j].vizinhos < 3 && dir == 'x')
    {
        if (i > 0)
        {
            if (!mat[i-1][j].aberto)
                cord.newI -= 1;
        }
        else if (i < n-1)
        {
            if (!mat[i+1][j].aberto)
                cord.newI += 1;
        }
        else if (j > 0)
        {
            if (!mat[i][j-1].aberto)
                cord.newJ -= 1;
        }
        else if (j < n-1)
        {
            if (!mat[i][j+1].aberto)
                cord.newJ += 1;
        }
    }

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1; j++)
            if (mat[i][j].aberto && !mat[i][j].vizinhos)
            {
                if (i > 0)
                {
                    if (j > 0)
                        if (!mat[i-1][j-1].aberto)
                            mat[i-1][j-1].aberto = 1;

                        if (j < n - 1)
                            if (!mat[i-1][j+1].aberto)
                                mat[i-1][j+1].aberto = 1;
                }

                if (i < n - 1)
                {
                    if (j > 0)
                        if (!mat[i+1][j-1].aberto)
                            mat[i+1][j-1].aberto = 1;

                    if (j < n - 1)
                        if (!mat[i+1][j+1].aberto)
                            mat[i+1][j+1].aberto = 1;
                }
            }


    if (mat[cord.newI][cord.newJ].aberto == 1 || mat[i][j].vizinhos > 2)
        while (mat[cord.newI][cord.newJ].aberto)
        {
            cord.newI = rand() % n;
            cord.newJ = rand() % n;
        }



    return 1; // Continua jogando
}




#endif // IA_H_INCLUDED
