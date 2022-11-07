#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "assinaturas.h"
#include <time.h>

// funcao que imprime a matriz principal
void imprimeMatriz()
{
    int i, j, qtcel = 0;
    printf("\n\n  ");
    for (i = 0; i < tamanho; i++)
    {
        printf("%3d", i);
    }
    for (i = 0; i < tamanho; i++)
    {
        printf("\n %2d ", i);
        for (j = 0; j < tamanho; j++)
        {
            printf("%c", matriz[i][j].view);
            printf("  ");
        }
    }
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            if (matriz[j][i].vida == 1)
            {
                qtcel++;
            }
        }
    }
    printf("\n\nQuantidade de celulas vivas: %d\n", qtcel);
}
// funcao que armazena todas as mensagens
void mensagens(int idMsg)
{
    msg mensagem[] =
        {
            {"\nEscolha o tamanho do mundo\n\nTamanho desejado: "},                                                  // id 0
            {"\nTamanho invalido!\n"},                                                                               // id 1
            {"\nEscolha a linha: "},                                                                                 // id 2
            {"\nEscolha a coluna: "},                                                                                // id 3
            {"\nO programa foi encerrado!\n"},                                                                       // id 4
            {"\nLinha/coluna com tamanha invalido!\n"},                                                              // id 5
            {"\nOpcao invalida!"},                                                                                   // id 6
            {"\nPosicao ja escolhida"},                                                                              // id 7
            {"\nNao ha celulas nessa posicao"},                                                                      // id 8
            {"\nDeseja continuar inserindo?\n1-Sim\n2-Nao\nOpcao:"},                                                 // id 9
            {"\nEscolha Invalida!"},                                                                                 // id 10
            {"\nInsira a quantidade de geracoes: "},                                                                 // id 11
            {"\nInsira a velocidade de geracao (Em segundos): "},                                                    // id 12
            {"\nQuantidade de geracoes invalida\n"},                                                                 // id 13
            {"\nTempo invalido\n"},                                                                                  // id 14
            {"\nJogo salvo com sucesso.\n"},                                                                         // id 15
            {"\nJogo recuperado com sucesso.\n"},                                                                    // id 16
            {"\n\nEscolha um dos tres modelos prontos acima para prosseguir (ou digite 4 para sair dessa opcao): "}, // id 17
        };
    printf("%s", mensagem[idMsg].txt);
}

void menuInicialJogo()
{
    printf("\n=========== JOGO DA VIDA ===========");
    printf("\n[1] - Novo jogo");
    printf("\n[2] - Recuperar jogo salvo");
    printf("\n[3] - Escolher modelo pronto de jogo");
    printf("\n[4] - Sair do Jogo");
    printf("\n====================================");
    printf("\nOpcao: ");
}

// funcao que contem as opcoes visuais do menu principal
void subMenuPrincipal()
{

    printf("\n\n============MENU============");
    printf("\n[1] - Iniciar jogo");
    printf("\n[2] - Apresentar Mundo");
    printf("\n[3] - Limpar o Mundo");
    printf("\n[4] - Escolher uma celula");
    printf("\n[5] - Remover uma celula");
    printf("\n[6] - Salvar Jogo");
    printf("\n[7] - Voltar para o Menu Inicial");
    printf("\n============================");
    printf("\nOpcao: ");
}

void flush_in()
{
    int ch;

    do
    {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

// funcao que contem as opcoes visuais do menu da simulacao
void geracaoView()
{
    printf("\n\n============MENU============");
    printf("\n[1] - Proxima geracao");
    printf("\n[2] - Gerar automatico (10x)");
    printf("\n[3] - Interromper geracao");
    printf("\n============================");
    printf("\nOpcao: ");
}

void viewPadrao1()
{
    int i, j;
    printf("\n\n  [1] - Padrao 1\n\n");
    printf("  ");
    for (i = 0; i < tamanho; i++)
    {
        printf("%3d", i);
    }
    for (i = 0; i < tamanho; i++)
    {
        printf("\n %2d ", i);
        for (j = 0; j < tamanho; j++)
        {
            printf("%c", padrao1[j][i].view);
            printf("  ");
        }
    }
}

void viewPadrao2()
{
    int i, j;
    printf("\n\n  [2] - Padrao 2\n\n");
    printf("  ");
    for (i = 0; i < tamanho; i++)
    {
        printf("%3d", i);
    }
    for (i = 0; i < tamanho; i++)
    {
        printf("\n %2d ", i);
        for (j = 0; j < tamanho; j++)
        {
            printf("%c", padrao2[i][j].view);
            printf("  ");
        }
    }
}

void viewPadrao3()
{
    int i, j;
    printf("\n\n  [3] - Padrao 3\n\n");
    printf("  ");
    for (i = 0; i < tamanho; i++)
    {
        printf("%3d", i);
    }
    for (i = 0; i < tamanho; i++)
    {
        printf("\n %2d ", i);
        for (j = 0; j < tamanho; j++)
        {
            printf("%c", padrao3[i][j].view);
            printf("  ");
        }
    }
}
