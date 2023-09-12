#include "campeonato.h"

// Função de comparação para qsort
int compararTimes(const void *a, const void *b) {
    const time *timeA = (const time *)a;
    const time *timeB = (const time *)b;

    // Primeiro, compare os pontos
    if (timeA->pontos != timeB->pontos) {
        return timeB->pontos - timeA->pontos; // Ordena em ordem decrescente de pontos
    }

    // Em caso de empate nos pontos, compare as vitórias
    if (timeA->V != timeB->V) {
        return timeB->V - timeA->V; // Ordena em ordem decrescente de vitórias
    }

    // Em caso de empate nas vitórias, compare o saldo de gols
    if (timeA->SG != timeB->SG) {
        return timeB->SG - timeA->SG; // Ordena em ordem decrescente de saldo de gols
    }

    // Em caso de empate no saldo de gols, compare os gols marcados
    return timeB->GP - timeA->GP; // Ordena em ordem decrescente de gols marcados
}

int contarTimes(time *LISTA_TIMES)
{
    int cont = 0;
    time *atual = LISTA_TIMES;

    while (atual->prox != NULL)
    {
        cont++;
        atual = atual->prox;
    }

    return cont;
}


void ordena_tabela(time *LISTA_TIMES) 
{
    int numTimes = contarTimes(LISTA_TIMES); // Implemente a função contarTimes para contar o número de times na lista.

    if (numTimes > 0) {
        time *arrayTimes = (time *)malloc(numTimes * sizeof(time)); // Crie um array para armazenar os times da lista.
        int i = 0;
        
        // Copie os times da lista para o array.
        time *atual = LISTA_TIMES->prox;
        
        while (atual != NULL) 
        {
            arrayTimes[i] = *atual;
            atual = atual->prox;
            i++;
        }

        // Use qsort para ordenar o array de times.
        qsort(arrayTimes, numTimes, sizeof(time), compararTimes);

        // Agora, copie os times ordenados de volta para a lista.
        atual = LISTA_TIMES->prox;
        i = 0;
        while (atual != NULL) 
        {
            *atual = arrayTimes[i];
            atual = atual->prox;
            i++;
        }

        free(arrayTimes); // Libere a memória alocada para o array.
    }
}

time *copiaTime(time *original) 
{
    time *novoTime = (time *)malloc(sizeof(time));
    if (novoTime == NULL) 
    {
        return NULL;
    }

    *novoTime = *original;
    novoTime->prox = NULL;
    return novoTime;
}

// Função para criar uma cópia da lista original
time *copiaLista(time *LISTA_TIMES) 
{
    time *copiaHead = NULL;
    time *atual = LISTA_TIMES->prox;
    time *copiaAtual = NULL;

    while (atual != NULL) 
    {
        time *novoTime = copiaTime(atual);
        if (novoTime == NULL) 
        {
          
            break;
        }

        if (copiaHead == NULL) 
        {
            copiaHead = novoTime;
            copiaAtual = copiaHead;
        }

        else 
        {
            copiaAtual->prox = novoTime;
            copiaAtual = copiaAtual->prox;
        }

        atual = atual->prox;
    }

    return copiaHead;
}

void exibe_tabela (time *LISTA_TIMES)
{
    time *copia_Lista_Times = copiaLista(LISTA_TIMES);
    ordena_tabela(copia_Lista_Times);

    int cont = 1;
    time *atual = LISTA_TIMES->prox;

    printf("+----------------------+---------+---------+---------+\n");
    printf("|       Time      | P | J | V | E | D | GP | GS | SG |\n");
    printf("+----------------------+---------+---------+---------+\n");

    while (atual != NULL)
    {
        printf("|%d| %s         %d | %d | %d | %d | %d | %d | %d | %d |\n", cont, atual->nome, atual->pontos,   
        atual->jogos, atual->V, atual->E, atual->D, atual->GP, atual->GS, atual->SG);

        atual = atual->prox;
    }

}

