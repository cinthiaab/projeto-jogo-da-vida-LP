#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "assinaturas.h"
#include <time.h>

// funcao que gera a matriz
void geraMatriz()
{
    int i, j;

    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++){
            matriz[j][i].view='.';
            matriz[j][i].vida=0;
        }
    }
}
// funcao que gera matriz auxiliar
void matrizCopiada()
{
    int i, j;

    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++){
            matrizAux[j][i].view='.';
            matrizAux[j][i].vida=0;
        }
    }

}
//funcao para salvar o jogo
void salvarJogo()
{
    fp = fopen("jogo_da_vida.txt", "wb");

    fwrite(&tamanho, sizeof(int), 1, fp);
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            fwrite(&matriz[i][j], sizeof(struct celula), 1, fp);
            fwrite(&matrizAux[i][j], sizeof(struct celula), 1, fp);
        }
    }

    mensagens(15);// mensagem: jogo salvo com sucesso

    fclose(fp);

}

//funcao que recupera os arquivos, lendo os arquivos salvos
void recuperarJogo()
{
    fp = fopen("jogo_da_vida.txt","rb");

    fread(&tamanho, sizeof(int), 1, fp);
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            fread(&matriz[i][j], sizeof(struct celula), 1, fp);
            fread(&matrizAux[i][j], sizeof(struct celula), 1, fp);
        }
    }

    mensagens(16);// mensagem: jogo recuperado com sucesso

    fclose(fp);
}

void matrizPadroes(){
    int i, j;

    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++){
            padrao1[i][j].view='.';
            padrao1[i][j].vida=0;
        }
    }
    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++){
            padrao2[i][j].view='.';
            padrao2[i][j].vida=0;
        }
    }
    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++){
            padrao3[i][j].view='.';
            padrao3[i][j].vida=0;
        }
    }

    padrao1[5][3].view='O';
    padrao1[5][3].vida=1;
    padrao1[4][3].view='O';
    padrao1[4][3].vida=1;
    padrao1[5][4].view='O';
    padrao1[5][4].vida=1;
    padrao1[4][5].view='O';
    padrao1[4][5].vida=1;
    padrao1[3][6].view='O';
    padrao1[3][6].vida=1;
    padrao1[2][7].view='O';
    padrao1[2][7].vida=1;
    padrao1[1][7].view='O';
    padrao1[1][7].vida=1;
    padrao1[1][6].view='O';
    padrao1[1][6].vida=1;


    padrao2[3][1].view='O';
    padrao2[3][1].vida=1;
    padrao2[4][1].view='O';
    padrao2[4][1].vida=1;
    padrao2[2][1].view='O';
    padrao2[2][1].vida=1;
    padrao2[1][2].view='O';
    padrao2[1][2].vida=1;
    padrao2[5][2].view='O';
    padrao2[5][2].vida=1;
    padrao2[5][3].view='O';
    padrao2[5][3].vida=1;
    padrao2[1][3].view='O';
    padrao2[1][3].vida=1;
    padrao2[4][4].view='O';
    padrao2[4][4].vida=1;
    padrao2[2][4].view='O';
    padrao2[2][4].vida=1;
    padrao2[3][5].view='O';
    padrao2[3][5].vida=1;

    padrao3[1][2].view='O';
    padrao3[1][2].vida=1;
    padrao3[2][3].view='O';
    padrao3[2][3].vida=1;
    padrao3[3][1].view='O';
    padrao3[3][1].vida=1;
    padrao3[3][2].view='O';
    padrao3[3][2].vida=1;
    padrao3[3][3].view='O';
    padrao3[3][3].vida=1;


}
