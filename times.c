#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "times.h"


void exclui (time *LISTA_TIMES)
{

    jogadores *proxjog, *atualjog;
    atualjog = LISTA_TIMES->LISTA_JOGADORES->prox;

    while(atualjog != NULL)
    {            
        proxjog = atualjog->prox;
        free(atualjog);
        atualjog = proxjog;
    }

    time *atual = LISTA_TIMES->prox;
        
    while(atual != NULL)
    {
        atual->index -= 1;
        atual = atual->prox;
    }

    LISTA_TIMES->prox->ant = LISTA_TIMES->ant;
    LISTA_TIMES->ant->prox = LISTA_TIMES->prox;
    free(LISTA_TIMES);
}

void init_team (time *novo)
{
    jogadores *JOGS = (jogadores *) malloc(sizeof(jogadores));
    novo->prox = NULL;
    novo->LISTA_JOGADORES = JOGS;
    novo->LISTA_JOGADORES->prox = NULL;
    novo->GP = 0;
    novo->GS = 0;
    novo->SG = 0;
    novo->V = 0;
    novo->E = 0;
    novo->D = 0;
    novo->pontos = 0;
    novo->jogos = 0;
    novo->estadio[0] = '*';
    novo->cidade[0] = '*';
    novo->treinador[0] = '*';
}

int menu_principal ()
{
    int opt;
 
    printf("\n<-----Menu Inicial----->\n");
    printf("\nEscolha a Opcao\n");
    printf("1. Exibir Lista de Times\n");
    printf("2. Editar Time\n");
    printf("3. Adicionar Time\n");
    printf("4. Excluir Time\n");
    printf("5. Visualizar Infos de um Time\n");
    printf("6. Começar/Continuar Campeonato\n");
    printf("7. Sair\n");
    printf("\nOpcao: "); 
    scanf("%d", &opt);
    printf("\n"); 
    
    return opt;
}

void opcao_principal (time *LISTA_TIMES, partidas *LISTA_PARTIDAS, int op)
{

    exibe(LISTA_TIMES);
    time *atual = LISTA_TIMES->prox;

    int id;

    switch(op)
    {    
        case 1:
        
        break;
        
        case 2:
            if(vazia(LISTA_TIMES))
            {
                printf("\nLista de Times Vazia!\n");
                break;
            }
            printf("\nQual indice? ");
            scanf("%d", &id);
            editaIndex(LISTA_TIMES, id);
        break;
        
        case 3:
            insereFim(LISTA_TIMES);
        break;  
        
        case 4:
            printf("Indice do Time que Deseja Excluir: ");
            scanf(" %d", &id);
            while (atual->index != id)
            {
                atual = atual->prox;
                if (!atual)
                {
                    printf("Indice Invalido!\n");
                    break;
                }
            }
            exclui(atual);
        break;

        case 5:
            exibeInfo(LISTA_TIMES);
        break;
   
        case 6:
            
            opcao_partidas(LISTA_TIMES, LISTA_PARTIDAS);
        break;

        case 7:
            libera(LISTA_TIMES);
            libera_partidas(LISTA_PARTIDAS);
            exit(0);
        break;

        default:
            printf("Comando invalido\n\n");
        break;
    }
}

int vazia(time *LISTA_TIMES)
{
    if(LISTA_TIMES->prox == NULL)
        return 1;
    else
        return 0;
}

void insereFim(time *LISTA_TIMES)
{
    time *novo = (time *) malloc(sizeof(time));

    init_team(novo);

    printf("Novo elemento: "); 
    scanf(" %[^\n]", novo->nome);
    novo->prox = NULL;
    novo->ant = NULL;

    if(vazia(LISTA_TIMES))
    {
        LISTA_TIMES->prox = novo;
        novo->ant = LISTA_TIMES;
        novo->index = 1;
    }

    else
    {
        time *atual = LISTA_TIMES->prox;
        
        while(atual->prox != NULL)
            atual = atual->prox;

        atual->prox = novo;
        novo->ant = atual;
        novo->index = novo->ant->index + 1;
    }
}

void editaIndex(time *LISTA_TIMES, int id)
{
    int i;

    time *novo = (time *) malloc(sizeof(time));
    
    time *atual;
    atual = LISTA_TIMES->prox;


    while (atual->index != id)
    {
        atual = atual->prox;
        if (!atual)
        {
            printf("Indice Invalido!\n");
            break;
        }
    }

    if (atual)
    {
        int opt = 0;
        jogadores *ptr = atual->LISTA_JOGADORES;
        
        while (opt > 5 || opt < 1)
        {
            printf("\nEscolha o que editar\n");
            printf("1.Nome\n");
            printf("2.Estadio\n");
            printf("3.Cidade\n");
            printf("4.Adicionar Treinador\n");
            printf("5.Adicionar Jogador\n");
            scanf("%d", &opt);
        }

        switch (opt)        
        {
            case 1:
                printf("Novo nome: ");
                scanf(" %[^\n]", atual->nome);
            break;
            
            case 2:
                printf("Novo estadio: ");
                scanf(" %[^\n]", atual->estadio);
            break;
            
            case 3:
                printf("Nova cidade: ");
                scanf(" %[^\n]", atual->cidade);
            break;

            case 4:
                printf("Novo treinador: ");
                scanf(" %[^\n]", atual->treinador);
            break;
            
            case 5:
            insere_Jogador(atual->LISTA_JOGADORES);
            break;

            default:
            break;
        }

    }

    else
    {
        printf("Nao ha nenhum clube cadastrado!\n");

    }

}

void exibe(time *LISTA_TIMES)
{
    if(vazia(LISTA_TIMES)){
        printf("Lista vazia!\n\n");
        return ;
    }
    
    time *atual;
    atual = LISTA_TIMES->prox;
    
    while(atual != NULL){
        printf("%d:", atual->index);
        printf(" %s\n", atual->nome);
        atual = atual->prox;
    }
  //  printf("\n");

}

void exibeInfo(time *LISTA_TIMES)
{
    if(vazia(LISTA_TIMES)){
        printf("\nLISTA DE TIMES vazia!\n");
        return;
    }
    
    time *atual;
    atual = LISTA_TIMES->prox;
    
    printf("\n");
  
    int opt;

    printf("Indice para visualizar: ");
    scanf("%d", &opt);

    atual = LISTA_TIMES;

    while(atual->index != opt){
        if (atual->prox)
        {
            atual = atual->prox;
        }
        else
        {
            printf("\nIndice invalido!\n");
            return;
        }
    }
    
    printf("\n1.Nome:");
    if (atual->nome[0] != '*')
        printf(" %s\n", atual->nome);
    else
        printf(" Campo Vazio!\n");
    
    printf("\n2.Estadio:");
    if (atual->estadio[0] != '*')
        printf(" %s\n", atual->estadio);
    else
        printf(" Campo Vazio!\n");
    
    printf("\n3.Cidade:");
    if (atual->cidade[0] != '*')
        printf(" %s\n", atual->cidade);
    else
        printf(" Campo Vazio!\n");
    
    printf("\n4.Treinador:");
    if (atual->treinador[0] != '*')
        printf(" %s\n", atual->treinador);
    else
        printf(" Campo Vazio!\n");
    
    printf("\nLista de jogadores:"); 
    if (atual->LISTA_JOGADORES->prox != NULL)
        exibe_Jogadores(atual);
    else
        printf(" Vazia!\n");
    

    

}

void libera (time *LISTA_TIMES)
{
    if(!vazia(LISTA_TIMES))
    {
        time *proxtime, *atual;
        
        atual = LISTA_TIMES->prox;
        while(atual != NULL)
        {
            jogadores *proxjog, *atualjog;
            atualjog = atual->LISTA_JOGADORES->prox;

            while(atualjog != NULL)
            {
                proxjog = atualjog->prox;
                free(atualjog);
                atualjog = proxjog;
            }

            proxtime = atual->prox;
            free(atual);
            atual = proxtime;
        }
    }
    free(LISTA_TIMES);
}




