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

int porcentagem_bombas_input;
float porcentagem_bombas;


int func_chama_linha();
int func_chama_coluna();
int printa_menu();
int chama_endgame();

int campo_matriz[TAM_1][TAM_2] = {VALOR_PADRAO};


int main()
{
    srand(time(NULL));
    //%2d printa 2 casas

//---------------------------------------
//    SOLICITA A PORCENTAGEM DE BOMBAS NO JOGO
    printf("Digite um numero de 10 a 20 para escolher a porcentagem de bombas\n");
    scanf("%d",&porcentagem_bombas_input);
    porcentagem_bombas = (float)porcentagem_bombas_input/100;
    printf("Porcentagem de bomba escolhida = %.0f%%\n",porcentagem_bombas*100);

    printf("\n");
//---------------------------------------
//    BOMBAS FIXADAS!
    campo_matriz[4][0] = VALOR_BOMBA;
    campo_matriz[2][7] = VALOR_BOMBA;
//    campo_matriz[0][0] = VALOR_BOMBA;

//---------------------------------------
    //TAMANHO TOTAL da MATRIZ
    tamanho_matriz = sizeof(campo_matriz);
    tamanho_elemento = sizeof(campo_matriz[0][0]);
    total_elementos = tamanho_matriz/tamanho_elemento;
    printf("Tamanho Matriz = %d  | ", total_elementos);

    //CALCULO DE BOMBAS
    total_elementos = ceil(total_elementos * porcentagem_bombas);
    printf(" QTD de bombas = %d  | ", total_elementos);


//---------------------------------------


    //ADICIONA BOMBAS ALEATORIAS NA MATRIZ
//    int e = 1;
//    int linha;
//    int coluna;
//    while (e <= total_elementos) {
//       linha  = rand() % TAM_1;
//       coluna = rand() % TAM_2;
//        if (campo_matriz[linha][coluna] == VALOR_PADRAO){
//        campo_matriz[linha][coluna] = VALOR_BOMBA;
//        e = e+1;
//        }
//    }


//---------------------------------------

    //identifica se é bomba
    for (i=0; i<TAM_1; i++)
    {
        for (j=0; j< TAM_2; j++)
        {
            if (campo_matriz[i][j] == VALOR_BOMBA){
                printf("\n\nMatrizzzz == BOMBA %d\n", campo_matriz[i][j]);
                 printf("\nPosicao BOMBA =  %d e %d\n\n",i,j);

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

                        //---------------------------------------
//                        AVALIA OS VIZINHOS DA BOMBA
                        int temp_k = i+k;
                        int temp_p = j+p;

                        // SE FOR DIFERENTE DE BOMBA
                        if (campo_matriz[temp_k][temp_p]!= VALOR_BOMBA ){

                            printf("valor i+k %d\n",temp_k);
                            printf("valor j+p %d\n",temp_p);
                            // se for maior que 7 colunas pula
                            if (temp_p >=TAM_2){
                                continue;
                            }
                            if (temp_p < 0){
                                continue;
                            }
                            if (temp_k < 0){
                                continue;
                            }
                             if (temp_k >= TAM_1){
                                continue;
                            }
                            // SOMA 1 AO CAMPO AO REDOR DA BOMBA
                            campo_matriz[i+k][j+p] = campo_matriz[i+k][j+p]+1;

                           //---------------------------------------
//    //                      Faz o loop na matriz inteira novamente pra pegar o começo da matriz e o final da coluna
//                            for (i=0; i<TAM_1; i++){
//                                if (campo_matriz[i+k] < 0){
//                                    continue; }
//                                for (j=0; j < TAM_2; j++){
//                                    if (campo_matriz[j+p] > TAM_2){
//                                    continue;
//                                    }
//                                       // && (i+k && j+p < 0 )
//                                    printf("ENTROU NA CONDICAO\n");
//
//                                }
//                            }
                        }
                          if (campo_matriz[temp_k][temp_p]== VALOR_BOMBA ) {
                                 continue;
//                                campo_matriz[i+k][j+p] = campo_matriz[i+k][j+p]+1;
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


    printf("\n");


    printa_menu();
    //printa matriz
    printf("     0   1   2   3   4   5   6   7\n");
    printf("     -----------------------------\n");
    for (i=0; i<TAM_1; i++)
    {
    printf("%d  | ",i);
        for (j=0; j< TAM_2; j++)
        {
            // printf("entrou\n");
            if (campo_matriz[i][j]  == 0) {
                printf("  | ");
            }
            else{
                printf("%d | ",campo_matriz[i][j]);
            }

        }
        printf("\n     -----------------------------");
        printf("\n");
    }


    printf("\n");


//---------------------------------------

//chama coluna e linha input usuario
    func_chama_coluna();
    func_chama_linha();

    printf("linha = %d coluna = %d\n",linha_jogador, coluna_jogador );


//---------------------------------------

//    Caso a célula seja bomba
    chama_endgame();


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

//---------------------------------------

//Declara função input linha
int func_chama_linha(){
    {
        do
        {
            printf("Digite a linha \n");
            scanf("%d", &linha_jogador);
            getchar();
            if (linha_jogador < 0 || linha_jogador > TAM_1)
            {
                printf("o numero deve ser de 0 a %d\n", TAM_1-1);
                //chamar a mesma função de solicitar linha novamente
                return func_chama_linha();

            }
        }while (linha_jogador < 0 || linha_jogador > TAM_1);
    }

    return 0;
}

//---------------------------------------

  //Declara função imput coluna
int  func_chama_coluna(){

//    printf("Nice!\n");

     {
        do
        {
            printf("Digite a coluna \n");
            scanf("%d", &coluna_jogador);
            getchar();
            if (coluna_jogador < -1 || coluna_jogador > TAM_2)
            {
                printf("o numero deve ser de 0 a %d\n", TAM_2-1);
                //chamar a mesma função de solicitar coluna novamente
                return func_chama_coluna();

            }
        }while (coluna_jogador < -1 || coluna_jogador > TAM_2);
    }


  return 0;
}

int printa_menu(){
    printf("   --- O numero 9 significa BOMBA ---  \n\n");

return 0;
}

int chama_endgame(){

    printf("Entrou no endgame\n");
    printf("linha = %d coluna = %d\n",linha_jogador, coluna_jogador );

    if(campo_matriz[linha_jogador][coluna_jogador] == VALOR_BOMBA){
        printf("POSICAO DA MATRIZ = BOMBA\n");
        //chama função da matriz aberta

        //chama função da tela de derrota
    }
    else{


    }

//    for (i=0; i<TAM_1; i++)
//    {
//        for (j=0; j< TAM_2; j++)
//        {
//
//            }
//        }
//    }

return 0;
}
