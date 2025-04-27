#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAM_1 5
#define TAM_2 8
#define BASE 5
#define VALOR_PADRAO 0
#define VALOR_BOMBA 9
#define VALOR_TEMP 7

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
int numero_digitado_ok = 5;
int jogando = 2;
int porcentagem_bombas_input;
float porcentagem_bombas;


int func_chama_linha();
int func_chama_coluna();
int printa_menu();
int chama_endgame();
int printa_matriz_aberta();
int printa_matriz_fechada();
int printa_matriz_2();

int campo_matriz[TAM_1][TAM_2] = {VALOR_PADRAO};
int campo_matriz2[TAM_1][TAM_2] = {VALOR_TEMP};

int main()
{
    srand(time(NULL));
    //%2d printa 2 casas

//---------------------------------------
//    SOLICITA A PORCENTAGEM DE BOMBAS NO JOGO
 while (numero_digitado_ok == 5){
    printf("Digite um numero de 10 a 20 para escolher a porcentagem de bombas\n");
    scanf("%d",&porcentagem_bombas_input);

    if (porcentagem_bombas_input >= 10 && porcentagem_bombas_input <= 20){
        porcentagem_bombas = (float)porcentagem_bombas_input/100;
        printf("Porcentagem de bomba escolhida = %.0f%%\n",porcentagem_bombas*100);

        printf("\n");
        numero_digitado_ok = numero_digitado_ok + 1;
    }
    else {
        printf("numero fora do range...\n");
    }
 }

//---------------------------------------
//    BOMBAS FIXADAS!
//    campo_matriz[4][0] = VALOR_BOMBA;
//    campo_matriz[2][7] = VALOR_BOMBA;
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
    int e = 1;
    int linha;
    int coluna;
    while (e <= total_elementos) {
       linha  = rand() % TAM_1;
       coluna = rand() % TAM_2;
        if (campo_matriz[linha][coluna] == VALOR_PADRAO){
        campo_matriz[linha][coluna] = VALOR_BOMBA;
        e = e+1;
        }
    }

//---------------------------------------

    //identifica se � bomba
    for (i=0; i<TAM_1; i++) {
        for (j=0; j< TAM_2; j++){
            //POPULA MATRIZ 2
            campo_matriz2[i][j] = VALOR_TEMP;
            //---------------------------------------
            if (campo_matriz[i][j] == VALOR_BOMBA){
//                printf("\n\nMatrizzzz == BOMBA %d\n", campo_matriz[i][j]);
//                printf("\nPosicao BOMBA =  %d e %d\n\n",i,j);

                for(k=-1;k<2;k++){
                   for(p=-1;p<2;p++){
//                    printf("p = %2d    ",p);
//                    printf("k = %2d    ",k);
//                    printf("\n");

                        //---------------------------------------
//                        AVALIA OS VIZINHOS DA BOMBA
                        int temp_k = i+k;
                        int temp_p = j+p;

                        // SE FOR DIFERENTE DE BOMBA
                        if (campo_matriz[temp_k][temp_p]!= VALOR_BOMBA ){
//                            printf("valor i+k %d\n",temp_k);
//                            printf("valor j+p %d\n",temp_p);

                            // CONDI��ES PRA VERIFICAR SE EST� DENTO DO LIMITE DO TABULEIRO
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
//    //
                        }
                          if (campo_matriz[temp_k][temp_p] == VALOR_BOMBA ) {
                                 continue;
                        }
                    }
                  }
                } //FIM DO == BOMBA
            }
            // printf("entrou\n");
            //printf("%d ",campo_matriz[i][j]);

        printf("\n");

        }


//---------------------------------------
//COME�A O JOGO EM LOOP

while (jogando == 2){

        printf("\n");


        printa_menu();

//        printa_matriz_fechada();
    //  printa_matriz_aberta();
        printf("\n");

    //---------------------------------------

    //CHAMA CULUNA DE IMPUT DO USUARIO
        func_chama_coluna();
        func_chama_linha();

        printf("linha = %d coluna = %d\n",linha_jogador, coluna_jogador );

    //---------------------------------------

    chama_endgame();

    //AVALIA JOGADA
    chama_matriz_jogada();
    printa_matriz_2();
    printa_matriz_aberta();

} // finaliza o While do game loop

    return 0;
}

//---------------------------------------

//Declara fun��o input linha
int func_chama_linha(){
    {
        do
        {
            printf("Digite a linha \n");
            scanf("%d", &linha_jogador);
            getchar();
            if (linha_jogador < 0 || linha_jogador > TAM_1-1)
            {
                printf("o numero deve ser de 0 a %d\n", TAM_1-1);
                //chamar a mesma fun��o de solicitar linha novamente
                return func_chama_linha();

            }
        }while (linha_jogador < 0 || linha_jogador > TAM_1-1);
    }

    return 0;
}

//---------------------------------------

  //Declara fun��o imput coluna
int  func_chama_coluna(){
     {
        do
        {
            printf("Digite a coluna \n");
            scanf("%d", &coluna_jogador);
            getchar();
            if (coluna_jogador < 0 || coluna_jogador > TAM_2-1)
            {
                printf("o numero deve ser de 0 a %d\n", TAM_2-1);
                //chamar a mesma fun��o de solicitar coluna novamente
                return func_chama_coluna();

            }
        }while (coluna_jogador <0 || coluna_jogador > TAM_2-1);
    }


  return 0;
}

int printa_menu(){
    printf("   --- O numero 9 significa BOMBA ---  \n\n");
     printf(" \n");
return 0;
}

//---------------------------------------
//FIM DE GAME
int chama_endgame(){

//    printf("Entrou no endgame\n");
//    printf("linha = %d coluna = %d\n",linha_jogador, coluna_jogador );

    if(campo_matriz[linha_jogador][coluna_jogador] == VALOR_BOMBA){
        printf("POSICAO DA MATRIZ = BOMBA\n");
        //chama fun��o da matriz aberta
        printf("\n ------------\n");
        printf("\n VOCE PERDEU!\n");
        printf("\n ------------\n");
         printf("\n");
        printa_matriz_aberta();
        //chama tela de derrota
        printf("\n VOCE PERDEU!\n");

        //SAI DO LOOP DO GAME WHILE
        jogando = jogando +1;
    }
    else{

    }
return 0;
}

 //---------------------------------------
    //PRINTA MATRIZ ABERTA 1
 int  printa_matriz_aberta(){

    printf("     0   1   2   3   4   5   6   7\n");
    printf("     -------------------------------\n");
    for (i=0; i<TAM_1; i++)
    {
    printf("%d  | ",i);
        for (j=0; j< TAM_2; j++)
        {
            // printf("entrou\n");
            if (campo_matriz[i][j]  == 0) {
                printf("0 | ");
            }
            else{
                printf("%d | ",campo_matriz[i][j]);
            }

        }
        printf("\n     -------------------------------");
        printf("\n");
    }
    return 0;
}


 //---------------------------------------
 //PRINTA MATRIZ FECHADA 1

int printa_matriz_fechada(){

    printf("     0   1   2   3   4   5   6   7\n");
    printf("     -------------------------------\n");
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
                printf("  | ",campo_matriz[i][j]); //%d
            }
        }
        printf("\n     -------------------------------");
        printf("\n");
    }

  return 0;
}

int chama_matriz_jogada(){

//            printf("     0   1   2   3   4   5   6   7\n");
//            printf("     -------------------------------\n");
            printf(" campo_matriz1[linha_jogador][coluna_jogador] = %d | \n",campo_matriz[linha_jogador][coluna_jogador]);
            printf(" campo_matriz2[linha_jogador][coluna_jogador] = %d | \n",campo_matriz2[linha_jogador][coluna_jogador]);
            if ( campo_matriz[linha_jogador][coluna_jogador] != VALOR_BOMBA){
                printf(" CAMPO DA MATRIZ e DIFERENTE DE BOMBA E VAMOS SUBSTITUIR\n");
                campo_matriz2[linha_jogador][coluna_jogador] = campo_matriz[linha_jogador][coluna_jogador];
            }
            printf(" campo_matriz1[linha_jogador][coluna_jogador] = %d | \n",campo_matriz[linha_jogador][coluna_jogador]);
            printf(" campo_matriz2[linha_jogador][coluna_jogador] = %d | \n",campo_matriz2[linha_jogador][coluna_jogador]);


            for (i=0; i<TAM_1; i++)
            {
//             if (i == linha_jogador) {
//
//             }
//            printf("%d  | ",i);
                for (j=0; j< TAM_2; j++)
                {


//                    if (j == coluna_jogador){
////                     printf("i = %d  | ",i);
////                     printf("j = %d  | ",j);
//                    }
////                printf(" campo_matriz = %d | ",campo_matriz[linha_jogador][coluna_jogador]);
////                    if ( campo_matriz[linha_jogador][coluna_jogador] == VALOR_BOMBA){
////                        printf("\n chamando endgame PELO CHAMA MATRIZ_JOGADA\n");
////                        chama_endgame();
//                    }
//                    printf(" campo_matriz1[linha_jogador][coluna_jogador] = %d | \n",campo_matriz[linha_jogador][coluna_jogador]);
                    if ( campo_matriz[linha_jogador][coluna_jogador] != VALOR_BOMBA){
//                     printf(" campo_matriz{valro jogada diferente de bomba!!!!!!!! = %d | ",campo_matriz[linha_jogador][coluna_jogador]);
                        campo_matriz2[linha_jogador][coluna_jogador] == campo_matriz[linha_jogador][coluna_jogador];
//                     for (i=0; i<TAM_1; i++){
//                        for (j=0; j< TAM_2; j++){
//                        if(campo_matriz[linha_jogador][coluna_jogador] == )
//                       // ESSE MAGIC NUMBER SIGNIFICA QUE FOI ABERTO O CARD
////
//
//                        }
//                     }

//                        chama_endgame();
                    }
//                    else{


//                    if (campo_matriz[i][j]  == 0) {
//                        printf("  | ");
//                    }
//                    else{
//                        printf("  | ",campo_matriz[i][j]); //%d
//                    }
                }
//                printf("\n   22  -------------------------------");
//                printf("\n");
            }
return 0;
}

int printa_matriz_2(){
    printf("PRINTANTDO MATRIZ 2\n");
    printf("     0   1   2   3   4   5   6   7\n");
    printf("     -------------------------------\n");
    for (i=0; i<TAM_1; i++)
    {

    printf("%d  | ",i);
        for (j=0; j< TAM_2; j++)
        {

            if (campo_matriz2[i][j] == VALOR_TEMP) {
                printf("  | " );
            }
            else{
                printf("%d | ",campo_matriz2[i][j]);
            }

        }
        printf("\n     -------------------------------");
        printf("\n");
    }
    return 0;
}
