#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED
#include "menu.h"
#include "matrix.h"
#include <time.h>

typedef struct {
    int newI, newJ, oldI, oldJ;
    int first;
    char dir;
} Cord;

Cord cord = {0, 0, 0, 0, 0, 'b'};




int test(int n) {
    int i = cord.newI;
    int j = cord.newJ;
    int a, b;

    if (cord.first == 0) {
        // Encontra a primeira célula não revelada que não seja uma bomba
        a = rand() % n;
        b = rand() % n;
        while (mat[a][b].bomba == 1)
        {
            a = rand() % n;
            b = rand() % n;
        }
        i = a;
        j = b;
        cord.first = 1;
    }


    mat[i][j].aberto = 1;

    if (mat[i][j].bomba == 1) {
        return 2; // Perdeu
    }

    Sleep(500); // Adicione atraso (se necessário)





    char directions[] = {'b', 'c', 'd', 'e'};
    int moveIndex = 0;

    while (moveIndex < 4) {
        char currentDir = directions[moveIndex];
        int newI = i, newJ = j;

        switch (currentDir) {
            case 'b':
                newI = i + 1;
                break;
            case 'd':
                newJ = j + 1;
                break;
            case 'c':
                newI = i - 1;
                break;
            case 'e':
                newJ = j - 1;
                break;
        }

        if (newI >= 0 && newI < n && newJ >= 0 && newJ < n && mat[newI][newJ].aberto == 0 && mat[i][j].vizinhos < 3) {
            cord.dir = currentDir;
            cord.oldI = cord.newI;
            cord.oldJ = cord.newJ;
            cord.newI = newI;
            cord.newJ = newJ;
            break;
        }

        else
        {
            cord.newI = cord.oldI;
            cord.newJ = cord.oldJ;


        }

        moveIndex++;
    }

    return 1; // Continua jogando
}




#endif // IA_H_INCLUDED
