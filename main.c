#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_1 5
#define TAM_2 8
#define BASE 5
#define VALOR_PADRAO 0
#define VALOR_BOMBA 5
//ctrl +shif + c Comenta
//ctrl +shif + x descomenta
int i = 0;
int j = 0;
int k = 0;
int p = 0;

int main()
{
    srand(time(NULL));
    //%2d printa 2 casas

    int campo_matriz[TAM_1][TAM_2] = {VALOR_PADRAO};
    campo_matriz[2][5] = VALOR_BOMBA;
//    campo_matriz[1][1] = VALOR_BOMBA;
    campo_matriz[1][6] = VALOR_BOMBA;



    //identifica se é bomba
    for (i=0; i<TAM_1; i++)
    {
        for (j=0; j< TAM_2; j++)
        {
            if (campo_matriz[i][j] == VALOR_BOMBA){
                printf("matriz %d\n", campo_matriz[i][j]);

                for(k=-1;k<2;k++){
                   for(p=-1;p<2;p++){
                    printf("p = %2d    ",p);
                    printf("k = %2d    ",k);
//                    campo_matriz[i+k][j+p] = VALOR_PADRAO+1;
//                    int valor_p = campo_matriz[i+k][j+p];
//                    printf("Matriz + p = %d\n",valor_p);
                    //se o valor nao for da bomba (valor central)
                    if (campo_matriz[i+k][j+p] != VALOR_BOMBA){
//                      printf("valor i %d\n", i);
//
                        campo_matriz[i+k][j+p] = campo_matriz[i+k][j+p]+1;
                       }
//                      printf("matriz ij = %d\n",campo_matriz[i+k][j+p]);
//                      printf("matriz j %d\n",campo_matriz[j+p]);
//

                   }

//                 campo_matriz[i+k][j] = 2;
                }
            }
            // printf("entrou\n");
            //printf("%d ",campo_matriz[i][j]);
        }
        printf("\n");
    }


    //printa matriz
    for (i=0; i<TAM_1; i++)
    {
        for (j=0; j< TAM_2; j++)
        {
            // printf("entrou\n");
            printf("%d ",campo_matriz[i][j]);
        }
        printf("\n");
    }




//
// for(k=-1;k<2;k++){
//    for(p=-1;p<2;p++){
//       //p = p + BASE;
//       campo_matriz[i+k][j+p] = campo_matriz[i+1][j+1];
////       printf("%3d",p);
//       //p = p - BASE;
//    }
//    //k = k + BASE;
//    printf("\n",k);
//    //k = k - BASE;
// }


    // printf("Hello world!\n");
    return 0;
}
