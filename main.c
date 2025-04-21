#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_X 5
#define TAM_Y 7

#define VALOR_PADRAO 0
#define VALOR_BOMBO 5

int i = 0;
int j = 0;

int main()
{
    srand(time(NULL));
    //%2d printa 2 casas

    int campo_matriz[TAM_X][TAM_Y] = {VALOR_PADRAO};

    for (i=0; i<TAM_X; i++){
        for (j=0; j< TAM_Y; j++){
           // printf("entrou\n");
            printf("%d ",campo_matriz[i][j]);
        }
        printf("\n");
    }



   // printf("Hello world!\n");
    return 0;
}
