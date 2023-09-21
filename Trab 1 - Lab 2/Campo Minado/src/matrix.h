#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#define tabX 80
#define tabY 550

typedef struct{

    int bomba, aberto, vizinhos, bandeira, ultimo, abertas;

}tab;

tab **mat;

void aloca(int n)
{

    int i;

        mat = (tab **) malloc(n * sizeof(tab *));

        for (i = 0; i < n; i++){
            mat[i] = (tab *) malloc(n * sizeof(tab));
        }

}

void cria(int n, int bombs){

    srand(time(NULL));
    int posicionadas = 0, i, j;

    while (posicionadas != bombs)
    {

      for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {


                mat[i][j].aberto = 0;
                mat[i][j].bomba = 0;
                mat[i][j].vizinhos = 0;
                mat[i][j].bandeira = 0;
                mat[i][j].ultimo = 0;
                mat[i][j].abertas = 0;
            }
        }
        while (posicionadas < bombs)
        {
            i = rand() % n;
            j = rand() % n;
            if (mat[i][j].bomba == 0)
            {
                mat[i][j].bomba = rand() % 2;
                posicionadas += mat[i][j].bomba;
            }
        }


        if (posicionadas != bombs)
            posicionadas = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (i > 0)
            {
                if (j > 0)
                    if (mat[i-1][j-1].bomba == 1)
                        mat[i][j].vizinhos += 1;

                if (mat[i-1][j].bomba == 1)
                    mat[i][j].vizinhos += 1;
                if (j < n - 1)
                    if (mat[i-1][j+1].bomba == 1)
                        mat[i][j].vizinhos += 1;
            }

            if (j > 0)
                if (mat[i][j-1].bomba == 1)
                    mat[i][j].vizinhos += 1;
            if (j < n - 1)
                if (mat[i][j+1].bomba == 1)
                    mat[i][j].vizinhos += 1;

            if (i < n - 1)
            {
                if (j > 0)
                    if (mat[i+1][j-1].bomba == 1)
                        mat[i][j].vizinhos += 1;

                if (mat[i+1][j].bomba == 1)
                    mat[i][j].vizinhos += 1;
                if (j < n - 1)
                    if (mat[i+1][j+1].bomba == 1)
                        mat[i][j].vizinhos += 1;
            }
        }
    }
}

void abre(int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j].aberto == 1)
            {
                if (mat[i][j].bomba == 1)
                {
                    CV::text((tabX + 15) + (40 * j), (tabY - 25) - (40 * i), "X");

                }

                else
                {
                    CV::text((tabX + 15) + (40 * j), (tabY - 25) - (40 * i), mat[i][j].vizinhos);

                }

                if (mat[i][j].vizinhos == 0)
                {
                    if (i > 0)
                    {
                        if (j > 0)
                                mat[i-1][j-1].aberto = 1;

                        mat[i-1][j].aberto = 1;

                        if (j < n - 1)
                                mat[i-1][j+1].aberto = 1;
                    }

                    if (j > 0)
                            mat[i][j-1].aberto = 1;

                    if (j < n - 1)
                            mat[i][j+1].aberto = 1;

                    if (i < n - 1)
                    {
                        if (j > 0)
                                mat[i+1][j-1].aberto = 1;

                        mat[i+1][j].aberto = 1;

                        if (j < n - 1)
                                mat[i+1][j+1].aberto = 1;
                    }
                }
            }
            else
            {
                if (mat[i][j].bandeira == 1)
                {
               //     CV::text((tabX + 15) + (40 * j), (tabY - 25) - (40 * i), "!");
                    CV::color(6);
                    CV::line((tabX + 20) + (40 * j), (tabY - 30) - (40 * i),(tabX + 20) + (40 * j), (tabY - 10) - (40 * i));
                    CV::line((tabX + 10) + (40 * j), (tabY - 20) - (40 * i),(tabX + 20) + (40 * j), (tabY - 10) - (40 * i));
                    CV::line((tabX + 10) + (40 * j), (tabY - 20) - (40 * i),(tabX + 20) + (40 * j), (tabY - 20) - (40 * i));
                    CV::color(0);
                }
            }

            if (mat[i][j].aberto == 1)
            {

                if (i > 0)
                {
                    if (j > 0)
                        if (mat[i-1][j-1].aberto == 1)
                            mat[i][j].abertas += 1;

                    if (mat[i-1][j].aberto == 1)
                        mat[i][j].abertas += 1;

                    if (j < n - 1)
                        if (mat[i-1][j+1].aberto == 1)
                            mat[i][j].abertas += 1;
                }

                if (j > 0)
                    if (mat[i][j-1].aberto == 1)
                        mat[i][j].abertas += 1;

                if (j < n - 1)
                    if (mat[i][j+1].aberto == 1)
                        mat[i][j].abertas += 1;

                if (i < n - 1)
                {
                    if (j > 0)
                        if (mat[i+1][j-1].aberto == 1)
                            mat[i][j].abertas += 1;

                    if (mat[i+1][j].aberto == 1)
                        mat[i][j].abertas += 1;

                    if (j < n - 1)
                        if (mat[i+1][j+1].aberto == 1)
                            mat[i][j].abertas += 1;
                }
            }
        }
    }
}

#endif
