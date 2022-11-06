#define MIN 10
#define MAX 60

typedef struct celula
{
    int vida;
    char view;
} celula;

typedef struct msg
{
    char txt[150];
} msg;

celula matriz[MAX][MAX];
celula matrizAux[MAX][MAX];
celula padrao1[MAX][MAX];
celula padrao2[MAX][MAX];
celula padrao3[MAX][MAX];

int tamanho;
int idMsg;

FILE *fp;
