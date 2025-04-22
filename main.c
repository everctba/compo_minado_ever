#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAM_1 5
#define TAM_2 8
#define BASE 5
#define VALOR_PADRAO 0
#define VALOR_BOMBA 9

//ctrl +shif + c Comenta
//ctrl +shif + x descomenta
int i = 0;
int j = 0;
int k = 0;
int p = 0;
int tamanho_matriz;
int tamanho_elemento;
int linha_jogador;
int coluna_jogador;
int porcentagem_de_bombas;
int total_elementos;
int main()
{
    srand(time(NULL));
    //%2d printa 2 casas

    int campo_matriz[TAM_1][TAM_2] = {VALOR_PADRAO};
//    campo_matriz[2][5] = VALOR_BOMBA;
    campo_matriz[2][7] = VALOR_BOMBA;
//    campo_matriz[1][6] = VALOR_BOMBA;

    //TAMANHO TOTAL da MATRIZ
    tamanho_matriz = sizeof(campo_matriz);
    tamanho_elemento = sizeof(campo_matriz[0][0]);
    total_elementos = tamanho_matriz/tamanho_elemento;
    printf("Tamanho Matriz = %d  | ", total_elementos);

    //CALCULO DE BOMBAS
        total_elementos = ceil(total_elementos *0.15);
    printf("15 Porcento de bombas = %d  | ", total_elementos);


    //ADICIONA BOMBAS ALEATORIAS NA MATRIZ
//    int e = 1;
//    int linha;
//    int coluna;
//    while (e<=total_elementos) {
//       linha  = rand() % TAM_1;
//       coluna = rand() % TAM_2;
//        if (campo_matriz[linha][coluna] == VALOR_PADRAO){
//        campo_matriz[linha][coluna] = VALOR_BOMBA;
//        e = e+1;
//        }
//    }

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
                    printf("\n");
//                    campo_matriz[i+k][j+p] = VALOR_PADRAO+1;
//                    int valor_p = campo_matriz[i+k][j+p];
//                    printf("Matriz + p = %d\n",valor_p);
                    //se o valor nao for da bomba (valor central)
                    //&& campo_matriz[i+k][j+p] >= 0
//                    && (campo_matriz[i][j] + p < TAM_2  )
//                    int valorx = campo_matriz[i+k][j+p];
//                    printf("valorx = %2d\n",valorx);
//                     printf("matriz ij = %2d\n",campo_matriz[i+k][j+p]);
//                     printf("                    matriz ij = %2d\n",campo_matriz[i][j]);

                        if (campo_matriz[i+k][j+p]!= VALOR_BOMBA ){
//                      printf("valor i %d\n", i);
                            if (j+p >= TAM_2 ) {
                                    //&& (i+k && j+p < 0 )
                                 printf("ENTROU NA CONDICAO\n");
                                continue;

                            }
                            else {
                                campo_matriz[i+k][j+p] = campo_matriz[i+k][j+p]+1;
                            }

//                         if ((campo_matriz[i+k] >=0) && (campo_matriz[j+p] >= 0) && (campo_matriz[i+k] < TAM_1) && (campo_matriz[j+p] < TAM_2)){
//                            campo_matriz[i+k][j+p] = campo_matriz[i+k][j+p]+1;
//                         }
                           // {}



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

    printf("\n");
    //printa matriz
    printf("     0 1 2 3 4 5 6 7\n");
    printf("     ---------------\n");
    for (i=0; i<TAM_1; i++)
    {
    printf("%d  | ",i);
        for (j=0; j< TAM_2; j++)
        {
            // printf("entrou\n");
            printf("%d ",campo_matriz[i][j]);
        }
        printf("\n");
    }


    printf("\n");
    //identifica linha e coluna da jogada
    printf("Digite a linha e coluna: \n");
    scanf("%d", &linha_jogador);
    printf("Digite a coluna: \n");
    scanf("%d", &coluna_jogador);
    printf("linha = %d coluna = %d",linha_jogador, coluna_jogador );

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
