#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "partidas.h"

#include "times.c"
#include "jogadores.c"

#define GOL 3
#define FALTA 6
#define YELLOW 7
#define RED 8
#define CASA 1
#define FORA 2
#define SIM 1
#define NAO 2

void finaliza_partida (partidas *PARTIDA)
{
    PARTIDA->casa->GP += PARTIDA->gol_casa;
    PARTIDA->casa->GS += PARTIDA->gol_fora;

    PARTIDA->fora->GP += PARTIDA->gol_fora;
    PARTIDA->fora->GS += PARTIDA->gol_casa;

    PARTIDA->casa->SG += PARTIDA->gol_casa - PARTIDA->gol_fora;
    PARTIDA->fora->SG += PARTIDA->gol_fora - PARTIDA->gol_casa;


    if (PARTIDA->gol_casa > PARTIDA->gol_fora)
    {
        PARTIDA->casa->V++;
        PARTIDA->fora->D++;
    } 
    else if (PARTIDA->gol_casa < PARTIDA->gol_fora)
    {
        PARTIDA->casa->D++;
        PARTIDA->fora->V++;
    } 
    else
    {
        PARTIDA->casa->E++;
        PARTIDA->fora->E++;
    } 


}

void add_stats (partidas *PARTIDA, int opt)
{
    int who;

    printf ("\n(1)Para o time da casa\n");
    printf ("(2)Para o time de fora\n");
    scanf (" %d", &who);



}



void exibe_relatorio (partidas *atual, int rodada, int id)
{
    while (atual != NULL && atual->rodada != rodada && atual->id_partida != id)
    {
        atual = atual->prox;
    }

    if (!atual)
        printf("\nIndice ou rodada invalido!\n");
    else    
        printf ("%s\n", atual->relatorio);
}

void altera_escalacao (partidas *PARTIDA, int opt, int subs)
{
    jogadores *jog_atual;
    jogadores *segundo_jogador;
    int ctrl = 0, id_max;   // variavel de controle para exibir mensagens apenas uma vez e outras coisas

    if (opt == CASA)
    {   
        printf("\nEscalacao do time da casa\n\n");
        printf("\n<-----Titulares----->\n\n");
        
        jog_atual = PARTIDA->casa->LISTA_JOGADORES;

        while (jog_atual != NULL)
        {
            if (jog_atual->index > 11 && !ctrl)
            {
                printf("\n<-----Reservas----->\n");
                ctrl = 1;
            }

            printf("%d.%s\n", jog_atual->nome, jog_atual->nome);
            id_max = jog_atual->index;
            jog_atual->prox;
        }

        int troca1, troca2;

        printf("\nIndice do jogador que voce deseja trocar:\n");
        scanf(" %d", troca1);
        printf("\nIndice do jogador que voce deseja colocar no lugar:\n");
        scanf(" %d", troca2);

        if (troca1 > id_max || troca1 < 1 || troca2 > id_max || troca2 < 1)
        {
            printf("\nIndice de troca invalido!\n");
            return;
        }

        jog_atual = PARTIDA->casa->LISTA_JOGADORES->prox;

        segundo_jogador = PARTIDA->casa->LISTA_JOGADORES->prox;
        jogadores *proximo;

        while (jog_atual->index != troca1)   
            jog_atual = jog_atual->prox;
        

        while (segundo_jogador->index != troca2)
            segundo_jogador = segundo_jogador->prox;
        
        jog_atual->ant->prox = segundo_jogador;
        segundo_jogador->ant->prox = jog_atual;
        
        ctrl = jog_atual->index;
        proximo = segundo_jogador->prox;
        
        segundo_jogador->prox = jog_atual->prox;
        jog_atual->prox = proximo;
        jog_atual->index = segundo_jogador->index;
        segundo_jogador->index = ctrl;

    }

    else
    {
        printf("\nEscalacao do time de fora\n\n");
        printf("\n<-----Titulares----->\n\n");
        
        jog_atual = PARTIDA->fora->LISTA_JOGADORES;

        while (jog_atual != NULL)
        {
            if (jog_atual->index > 11 && !ctrl)
            {
                printf("\n<-----Reservas----->\n");
                ctrl = 1;
            }

            printf("%d.%s\n", jog_atual->nome, jog_atual->nome);
            id_max = jog_atual->index;
            jog_atual->prox;
        }

        int troca1, troca2;

        printf("\nIndice do jogador que voce deseja trocar:\n");
        scanf(" %d", troca1);
        printf("\nIndice do jogador que voce deseja colocar no lugar:\n");
        scanf(" %d", troca2);

        if (troca1 > id_max || troca1 < 1 || troca2 > id_max || troca2 < 1)
        {
            printf("\nIndice de troca invalido!\n");
            return;
        }

        jog_atual = PARTIDA->fora->LISTA_JOGADORES->prox;

        segundo_jogador = PARTIDA->fora->LISTA_JOGADORES->prox;
        jogadores *proximo;

        while (jog_atual->index != troca1)   
            jog_atual = jog_atual->prox;
        

        while (segundo_jogador->index != troca2)
            segundo_jogador = segundo_jogador->prox;
        
        jog_atual->ant->prox = segundo_jogador;
        segundo_jogador->ant->prox = jog_atual;
        
        ctrl = jog_atual->index;
        proximo = segundo_jogador->prox;
        
        segundo_jogador->prox = jog_atual->prox;
        jog_atual->prox = proximo;
        jog_atual->index = segundo_jogador->index;
        segundo_jogador->index = ctrl;

    }

    if (subs == SIM)
    {
        int min;
        printf ("\nEm que minuto ocorreu a troca?\n");
        scanf (" %d", &min);

        char textoAdicional[100];
        sprintf(textoAdicional, "%d. - Substituicao: sai %s e entra %s .\n", min, jog_atual->nome, segundo_jogador->nome);

        strcat(PARTIDA->relatorio, textoAdicional);
    }

}








void edita_partidas(partidas *LISTA_PARTIDAS, int rodada, int id)
{
    exibe_partidas(LISTA_PARTIDAS);
    partidas *atual = LISTA_PARTIDAS;

    while (atual != NULL && atual->rodada != rodada && atual->id_partida != id)
    {
        atual = atual->prox;
    }

    if (!atual)
        printf("\nIndice ou rodada invalido!\n");
    else    
        stats_partida(atual);

}

void stats_partida (partidas *PARTIDA)
{
    int opt = 0;

    while (opt != 9)
    {
        printf("\n<-----Edicao de Partidas----->\n");
        printf("Escolha a Opcao\n");
        printf("1. Alterar Escalação Time da Casa\n");
        printf("2. Alterar Escalação Time de Fora\n");
        printf("3. Adicionar Gol\n");
        printf("4. Adicionar Substituicao Time da Casa\n");
        printf("5. Adicionar Substituicao Time de Fora\n");
        printf("6. Adicionar Falta\n");
        printf("7. Adicionar Cartão Amarelo\n");
        printf("8. Adicionar Cartão Vermelho\n");
        printf("9. Finalizar edicao\n");
        printf("\nOpcao: "); 
        scanf("%d", &opt);
        printf("\n"); 
        opcao_stats(PARTIDA, opt);
    }
}

void exibe_partidas (partidas *LISTA_PARTIDAS)
{
    partidas *atual;

    atual = LISTA_PARTIDAS->prox;

    while (atual != NULL)
    {
        
        printf("\nRodada %d\n", atual->rodada);       
        printf("Partida %d:", atual->id_partida);
        printf(" %s %d x %d %s\n", atual->casa->nome, atual->gol_casa, atual->gol_fora, atual->fora->nome);

        atual = atual->prox;
    }
    printf("\n");
}

     
void nova_partida(partidas *LISTA_PARTIDAS, int rodada, time *LISTA_TIMES) {
 
    partidas *novo = (partidas *)malloc(sizeof(partidas));

    sprintf(novo->relatorio, "\n<-----Relatorio da Partida----->\n");
 
    novo->prox = NULL;
    novo->rodada = rodada;
    novo->gol_casa = 0;
    novo->casa = NULL;
    novo->gol_fora = 0;
    novo->fora = NULL;

    // Encontrar o local correto para inserir a nova partida com base na rodada
    partidas *atual = LISTA_PARTIDAS->prox;
    partidas *anterior = NULL;

    while (atual != NULL && atual->rodada <= rodada) 
    {
        anterior = atual;
        atual = atual->prox;
    }

    // Insirer a nova partida na posição correta
    if (anterior == NULL) 
    {
        novo->prox = LISTA_PARTIDAS->prox;
        novo->ant = LISTA_PARTIDAS;
        LISTA_PARTIDAS->prox = novo;
    } 
    
    else if (atual != NULL)
    {
        anterior->prox = novo;
        novo->ant = anterior;
        novo->prox = atual;
        atual->ant = novo;
    }

    else
    {
        anterior->prox = novo;
        novo->ant = anterior;
        novo->prox = atual;
    }


    // Exibição dos times disponíveis
    time *time_atual = LISTA_TIMES->prox;
    
    printf("Times disponíveis:\n");
    while (time_atual != NULL) 
    {
        printf("%d: %s\n", time_atual->index, time_atual->nome);
        time_atual = time_atual->prox;
    }

    int escolha1, escolha2;

    printf("\nEscolha qual time jogará em casa (por índice):\n");
    scanf("%d", &escolha1);

    printf("Escolha qual time jogará fora de casa (por índice):\n");
    scanf("%d", &escolha2);

    // Encontre os times escolhidos na lista de times
    time_atual = LISTA_TIMES->prox;
    while (time_atual != NULL) 
    {
        if (escolha1 == time_atual->index) 
        {
            novo->casa = time_atual;
        } 
        else if (escolha2 == time_atual->index) 
        {
            novo->fora = time_atual;
        }
        time_atual = time_atual->prox;
    }

    // Verifica se os times foram escolhidos corretamente
    if (novo->casa == NULL || novo->fora == NULL) 
    {
        printf("Erro na escolha dos times!\n");

        // Libera a memória alocada para a nova partida
        free(novo);
        return;
    }

    if (novo->ant->rodada != rodada)
    {
        novo->id_partida = 1;
    }
    
    else
    {
        novo->id_partida = (novo->ant->id_partida);
        novo->id_partida++;
    }

    novo->casa->jogos++;
    novo->fora->jogos++;

    stats_partida(novo);
}


void exclui_partida (partidas *PARTIDA, int rodada, int id)
{

    partidas *atual = PARTIDA;

    // ajustando os indices das partidas posteriores na mesma rodada
    while (atual->prox != NULL)
    {
        if (atual->prox->rodada == atual->rodada)
            atual->prox->id_partida--;
        atual = atual->prox;
    }

    // ajusta os ponteiros anterior e prox
    PARTIDA->ant->prox = PARTIDA->prox; 
    PARTIDA->prox->ant = PARTIDA->ant; 


    PARTIDA->casa->GP -= PARTIDA->gol_casa;
    PARTIDA->casa->GS -= PARTIDA->gol_fora;

    PARTIDA->fora->GP -= PARTIDA->gol_fora;
    PARTIDA->fora->GS -= PARTIDA->gol_casa;

    PARTIDA->casa->SG -= PARTIDA->gol_casa - PARTIDA->gol_fora;
    PARTIDA->fora->SG -= PARTIDA->gol_fora - PARTIDA->gol_casa;


    if (PARTIDA->gol_casa > PARTIDA->gol_fora)
    {
        PARTIDA->casa->V--;
        PARTIDA->fora->D--;
    } 
    else if (PARTIDA->gol_casa < PARTIDA->gol_fora)
    {
        PARTIDA->casa->D--;
        PARTIDA->fora->V--;
    } 
    else
    {
        PARTIDA->casa->E--;
        PARTIDA->fora->E--;
    } 

    free (atual);

}

void opcao_stats(partidas *PARTIDA, int opt)
{

    switch (opt)
    {
        case 1:
            altera_escalacao (PARTIDA, CASA, NAO);
        break;
        
        case 2:
            altera_escalacao (PARTIDA, FORA, NAO);
        break;
     
        case 3:
            add_stats (PARTIDA, GOL);
        break;
        
        case 4:
            altera_escalacao (PARTIDA, CASA, SIM);
        break;
        
        case 5:
            altera_escalacao (PARTIDA, FORA, SIM);
        break;
        
        case 6:
            add_stats (PARTIDA, FALTA);
        break;
        
        case 7:
            add_stats (PARTIDA, YELLOW);
        break;

        case 8:
            add_stats (PARTIDA, RED);
        break;
      
        case 9:
            finaliza_partida (PARTIDA);
        break;

        default:
        break;
    }



}

int menu_partidas ()
{
    int opt;
    
    printf("\n<-----Menu de Partidas----->\n");
    printf("Escolha a Opcao\n");
    printf("1. Exibir Partidas de uma Rodada\n");
    printf("2. Editar Partida\n");
    printf("3. Adicionar Partida\n");
    printf("4. Excluir Partida\n");
    printf("5. Visualizar Relatorio de uma Partida\n");
    printf("6. Voltar ao Menu Inicial\n");
    printf("7. Visualizar Tabela\n");
    printf("8. Visualizar Estatisticas\n");
    printf("\nOpcao: "); 
    scanf("%d", &opt);
    printf("\n"); 

    return opt;
}

void opcao_partidas (time *LISTA_TIMES, partidas *LISTA_PARTIDAS)
{
    int opt = 1, id, rodada;

    while (1)    
    {
        if (opt != 5)
            exibe_partidas(LISTA_PARTIDAS);

        partidas *atual = LISTA_PARTIDAS->prox;
        opt = menu_partidas();

        switch(opt){
            
            case 1:
            
            break;
            
            case 2:
                if(LISTA_PARTIDAS->prox == NULL)
                {
                    printf("\nLista de Partidas Vazia!\n");
                    break;
                }    
                
                printf("\nQual a Rodada da Partida? ");
                scanf(" %d", &id);
                printf("\nQual o Indice da Partida? ");
                scanf(" %d", &id);
                edita_partidas(LISTA_PARTIDAS, rodada, id);
            break;
            
            case 3:
                
                if (LISTA_TIMES->prox == NULL)
                {
                    printf("\nNao ha times disponiveis!\n");
                    return;
                }
                 
                else if (LISTA_TIMES->prox->prox == NULL)
                {
                    printf("\nNao ha times disponiveis!\n");
                    return;
                }

                printf("\nQual a Rodada da Partida? ");
                scanf(" %d", &rodada);
                nova_partida(LISTA_PARTIDAS, rodada, LISTA_TIMES);
            break;  
            
            case 4:
                printf("Rodada da Partida que Deseja Excluir: ");
                scanf(" %d", &rodada);
                printf("Indice da Partida que Deseja Excluir: ");
                scanf(" %d", &id);
                
                while (atual->rodada != rodada && atual->id_partida != id)
                {
                    atual = atual->prox;
                    if (!atual)
                    {
                        printf("Partida Inexistente!\n");
                        break;
                    }
                }
                exclui_partida(atual, rodada, id);
            break;

            case 5:
                exibe_partidas (LISTA_PARTIDAS);
                printf("Rodada da Partida que Deseja Visualizar: ");
                scanf(" %d", &rodada);
                printf("Indice da Partida que Deseja Visualizar: ");
                scanf(" %d", &id);
                exibe_relatorio (LISTA_PARTIDAS, rodada, id);
            break;
    
            case 6:
                return;
            break;

            default:
                printf("Comando invalido\n\n");
            break;
        }
    }
}




void relatorio_partidas(partidas *LISTA_PARTIDAS)
{

}


void libera_partidas(partidas *LISTA_PARTIDAS)
{

    if (LISTA_PARTIDAS->prox != NULL)
    {
        partidas *atual, *prox;
        atual = LISTA_PARTIDAS->prox;
        
        while(atual != NULL)
        {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }

    free(LISTA_PARTIDAS);
}






