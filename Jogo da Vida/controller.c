#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "assinaturas.h"
#include <time.h>

// funcao com o menu principal do jogo
void menuInicial()
{
    int opcao, valido, opcaoJogo;
    do{
        do
        {
            menuInicialJogo();
            scanf("%d", &opcaoJogo);
            if(opcaoJogo<1 || opcaoJogo>4)
            {
                mensagens(6); // opcao invalida
            }
            switch(opcaoJogo){
                case 1:
                    mensagens(0); // escolher tamanho do mundo
                    scanf("%d", &tamanho);
                    flush_in();
                    if(tamanho<MIN || tamanho>MAX)
                    {
                        mensagens(1); //tamanho do mundo invalido
                        valido=0;
                    }
                    else valido=1;
                    if(valido==1){
                        geraMatriz();
                        matrizCopiada();
                    }
                    break;
                case 2:
                    recuperarJogo();
                    valido = 1;
                    break;
                case 3:
                    mensagens(0); // escolher tamanho do mundo
                    scanf("%d", &tamanho);
                    flush_in();
                    if(tamanho<MIN || tamanho>MAX)
                    {
                        mensagens(1); //tamanho do mundo invalido
                        valido=0;
                    }
                    else valido=1;
                    menuPadrao();
                    opcao = 1;
                    break;
                case 4:
                    break;
            }
        }
        while(valido==0);

        if(opcaoJogo!=4){
            do
            {
                subMenuPrincipal();
                scanf("%d", &opcao);
                flush_in();
                if(opcao>9 || opcao<1)
                {
                    mensagens(6); // opcao invalida
                }

                switch(opcao)
                {
                case 1:
                    imprimeMatriz();
                    menuGeracao();
                    break;
                case 2:
                    imprimeMatriz();
                    break;
                case 3:
                    limpaMatriz();
                    imprimeMatriz();
                    break;
                case 4:
                    escolheCelula();
                    imprimeMatriz();
                    break;
                case 5:
                    removeCelula();
                    imprimeMatriz();
                    break;
                case 6:
                    salvarJogo();
                    break;
                case 7:
                    break;
                }
            }
            while(opcao!=7);
        }
    }while(opcaoJogo!=4);

    mensagens(4); // programa foi encerrado
}
// funcao que permite o usuario escolher quais celulas ele quer criar
void escolheCelula()
{
    int linha, coluna, valido, escolha=0;

    do
    {
        do
        {
            linha=-1;
            coluna=-1;
            mensagens(2); // escolha linha
            scanf("%d", &linha);
            flush_in();

            mensagens(3); //escolha coluna
            scanf("%d", &coluna);
            flush_in();

            if(linha>60 || coluna>60 || linha>=tamanho || coluna>=tamanho || linha<0 || coluna<0) //crasha a partir de 89 na linha ou coluna
            {
                mensagens(5); // linha e coluna invalida
                valido=0;
            }

            if(matriz[linha][coluna].vida==1) //
            {
                mensagens(7); // posicao ja escolhida
                valido=0;

            } else valido=1;
        }while(valido==0);

        matriz[linha][coluna].vida=1;
        matriz[linha][coluna].view='O';
        imprimeMatriz();

        do
        {
            mensagens(9); //deseja continuar inserindo
            scanf("%d", &escolha);
            flush_in();
            if(escolha<1 || escolha>2)
            {
                escolha=3;
                mensagens(10); // escolha invalida
            }
        }
        while(escolha==3);
    }
    while(escolha==1);
}
//funcao que limpa a matriz
void limpaMatriz ()
{
    int i, j;
    i=tamanho;
    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++)
        {
            matriz[j][i].view='.';
            matriz[j][i].vida=0;
            matrizAux[j][i].view='.';
            matrizAux[j][i].vida=0;
        }

    }
}
// funcao que remove as celulas da matriz
void removeCelula()
{
    int linha, coluna, valido;
        do
        {
            mensagens(2); // escolha linha
            scanf("%d", &linha);
            flush_in();

            mensagens(3); //escolha coluna
            scanf("%d", &coluna);
            flush_in();

            if(linha>MAX || coluna>MAX|| linha>=tamanho || coluna>=tamanho || linha<0 || coluna<0)
            {
                mensagens(5); // linha e coluna invalida
                valido=0;
            }

            if(matriz[linha][coluna].vida==0)
            {

                mensagens(8); // nao ha celulas nessa posicao
                valido=0;
            }
            else valido=1;
        }
        while(valido==0);

        if(matriz[linha][coluna].vida==1) // quando existir c�lula no local escolhido ele apagar� ela
        {
            matriz[linha][coluna].view='.';
            matriz[linha][coluna].vida=0;
        }

    }
// funcao que verifica quais celulas vao morrer, viver ou nascer
void iniciarJogo(){
    int i, j, checado;

    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            checado=checaLados(i,j);
            if((checado<2 || checado>3) && matriz[j][i].vida==1){
                matrizAux[j][i].vida=0;
                matrizAux[j][i].view='.';
            }
            if(checado==3 && matriz[j][i].vida==0){
                matrizAux[j][i].vida=1;
                matrizAux[j][i].view='O';
            }
            if((checado==2 || checado==3) && matriz[j][i].vida==1){
                matrizAux[j][i].vida=1;
                matrizAux[j][i].view='O';
            }
        }
    }
    for(i=0;i<tamanho;i++){
        for(j=0;j<tamanho;j++){
            matriz[j][i].vida=matrizAux[j][i].vida;
            matriz[j][i].view=matrizAux[j][i].view;
        }
    }

}

// funcao que checa os lados de cada celula para ver quantas celulas vivas tem em volta
int checaLados(int i, int j){
    int cont=0, x;
    //if para quando a celula que esta sendo analisada nao esta em nenhuma das bordas
    if(j!=0 && j!=tamanho-1 && i!=0 && i!=tamanho-1){
        for(x=j-1;x<=j+1;x++){
            if (matriz[x][i-1].vida==1)
                cont++;
            if (matriz[x][i+1].vida==1)
                cont++;
        }
        if(matriz[j-1][i].vida==1)
            cont++;
        if(matriz[j+1][i].vida==1)
            cont++;
    }
    // if para quando a celula analisada esta na borda esquerda da matriz, porem nao esta nem na borda superior nem na inferior
    if(j==0 && i!=0 && i!=tamanho-1){
        for(x=j;x<=j+1;x++){
            if (matriz[x][i-1].vida==1)
                cont++;
            if (matriz[x][i+1].vida==1)
                cont++;
        }
        if(matriz[j+1][i].vida==1)
            cont++;

    }
    //if para quando a celula analisada esta na borda direita da matriz, porem nao esta nem na borda superior nem na inferior
    if(j==tamanho-1 && i!=0 && i!=tamanho-1){
        for(x=j-1;x<=j;x++){
            if (matriz[x][i-1].vida==1)
                cont++;
            if (matriz[x][i+1].vida==1)
                cont++;
        }
        if(matriz[j-1][i].vida==1)
            cont++;
    }
    //if para quando a celula analisada esta na borda superior da matriz, porem nao esta nem na borda direita nem esquerda
    if(j!=0 && j!=tamanho-1 && i==0){
        for(x=j-1;x<=j+1;x++){
            if (matriz[x][i+1].vida==1)
                cont++;
        }
        if(matriz[j-1][i].vida==1)
            cont++;
        if(matriz[j+1][i].vida==1)
            cont++;
    }
    //if para quando a celula analisada esta na borda inferior da matriz, porem nao esta nem na borda direita nem esquerda
    if(j!=0 && j!=tamanho-1 && i==tamanho-1){
        for(x=j-1;x<=j+1;x++){
            if (matriz[x][i-1].vida==1)
                cont++;
        }
        if(matriz[j-1][i].vida==1)
            cont++;
        if(matriz[j+1][i].vida==1)
            cont++;

    }
    //if para quando a celula analisada esta no ponto (0,0)
    if(j==0 && i==0){
        for(x=j;x<=j+1;x++){
            if (matriz[x][i+1].vida==1)
                cont++;
        }
        if(matriz[j+1][i].vida==1)
            cont++;
    }
    //if para quando a celula analisada esta no ponto (tamanho-1,tamanho-1), correspondente ao ponto no canto inferior esquerdo
    if(j==tamanho-1 && i==tamanho-1){
        for(x=j-1;x<=j;x++){
            if (matriz[x][i+1].vida==1)
                cont++;
        }
        if(matriz[j-1][i].vida==1)
            cont++;
    }
    //if para quando a celula analisada esta no ponto (0,tamanho-1)
    if(j==0 && i==tamanho-1){
        for(x=j;x<=j+1;x++){
            if (matriz[x][i-1].vida==1)
                cont++;
        }
        if(matriz[j+1][i].vida==1)
            cont++;
    }
    //if para quando a celula analisada esta no ponto (tamanho-1,0)
    if(j==tamanho-1 && i==0){
        for(x=j-1;x<=j;x++){
            if (matriz[x][i+1].vida==1)
                cont++;
        }
        if(matriz[j-1][i].vida==1)
            cont++;
    }
    return (cont);
}

//menu para a simulacao
void menuGeracao(){
    int i, opcao, repet, valido=1, tempo2;
    float tempo;

    do{
        geracaoView();
        scanf("%d", &opcao);
        flush_in();

        switch(opcao){
            case 1:
                iniciarJogo();
                imprimeMatriz();
                break;
            case 2:
                do{
                    mensagens(11); // qtd de geracao
                    scanf("%d", &repet);
                    flush_in();

                    mensagens(12); //vel de geracao
                    scanf("%f", &tempo);
                    flush_in();
                    tempo2=tempo*1000;

                    if(repet<=0){
                        mensagens(13);//qtd geracao invalido
                        valido=0;
                    }
                    if(tempo<=0){
                        mensagens(14);//tempo invalido
                        valido=0;
                    }

                }while(valido==0);

                for(i=0;i<repet;i++){
                    iniciarJogo();
                    imprimeMatriz();
                    Sleep(tempo2);

                }
                break;
        }
    }while(opcao!=3);
}

void menuPadrao(){
    int i, j, opcao;

    matrizPadroes();
    matrizCopiada();

    viewPadrao1();

    viewPadrao2();

    viewPadrao3();

    mensagens(17);
    scanf(" %d", &opcao);
    flush_in();

    switch(opcao){
        case 1:
            aplicaPadrao1();
            viewPadrao1();
            menuGeracao();
            break;
        case 2:
            aplicaPadrao2();
            viewPadrao2();
            menuGeracao();
            break;
        case 3:
            aplicaPadrao3();
            viewPadrao3();
            menuGeracao();
            break;
        case 4:
            break;
    }
}

void aplicaPadrao1(){
    int i, j;
    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++){
            matriz[j][i].view=padrao1[j][i].view;
            matriz[j][i].vida=padrao1[j][i].vida;
        }
    }
}

void aplicaPadrao2(){
    int i, j;
    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++){
            matriz[j][i].view=padrao2[j][i].view;
            matriz[j][i].vida=padrao2[j][i].vida;
        }
    }
}

void aplicaPadrao3(){
    int i, j;
    for(i=0; i<tamanho; i++)
    {
        for(j=0; j<tamanho; j++){
            matriz[j][i].view=padrao3[j][i].view;
            matriz[j][i].vida=padrao3[j][i].vida;
        }
    }
}
