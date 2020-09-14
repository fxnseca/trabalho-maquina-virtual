#include <stdio.h>
#include <stdlib.h>
#include <time.h> //para a função time()
#include <limits.h>


//funçoes usadas:
void montarRAM(); 
void alocarMI(int nLinhas);
void desalocarMI(int nLinhas);
void maquina();
void menu(int nLinhas, int multiplicando, int multiplicador, int dividendo, int divisor, int aux, int anterior, 
int lado, int base, int expoente, int numero, int altura, int raio, int maior, int menor, int velocidade, int tempo, int baseT);
void montarInstrucoesProgramaAleatorio();
void soma();
void subtracao();
void multiplicacao(int multiplicando, int multiplicador);
void divisao(int dividendo, int divisor);
void fibonacci(int aux, int anterior, int nLinhas);
void areaQuadrado(int lado);
void areaCirculo(int raio);
void areaRetangulo(int base,int altura);
void areaLosango(int maior, int menor);
void areaTriangulo(int base, int altura);
void potencia(int base, double expoente); 
void fatorial(int numero);
void volumeCubo(int lado);
void velocidadeMedia(int velocidade, int tempo);
void raizquadrada(int numero);
void distancia(int velocidade, int tempo);
int **memoriaInstrucoes;
int *RAM;
int cont;
int aux = 1;

int main(){

    int nLinhas = 10;
    int multiplicador = 5; int multiplicando = 5;
    int dividendo = 1000; int divisor = 10;
    int aux = 1; int anterior =1;
    int lado = 4; 
    int base = 2; double expoente = 5;
    int numero = 25;
    int altura = 4;
    int raio = 2;
    int maior = 5; int menor = 2;
    int velocidade = 10; int tempo = 2;
    int baseT = 2;

    //chamando as funcoes no main
    montarRAM();

    alocarMI(nLinhas);

    menu(nLinhas, multiplicando, multiplicador, dividendo, divisor, aux, anterior, lado, base, expoente, numero, altura, raio, maior, menor, velocidade, tempo, baseT);

    desalocarMI(nLinhas);
    free(RAM);

    return 0;
}

//Funções completas

void montarRAM()
    {

        RAM = malloc(100 * sizeof(int));

        srand(time(NULL));
        int r;

        for (int i = 0; i < 100; i++)
        {
            r = rand() % 1000;
            RAM[i] = r;
            // printf("RAM: %d\n", RAM[i]);
        }
    }

void alocarMI(int nLinhas)
    {
        memoriaInstrucoes = malloc(nLinhas * sizeof(int *)); //o 10 é o nro de instruções e o 4 é nro de funçao que a maquina faz

        for (int i = 0; i < nLinhas; i++)
        {
            (memoriaInstrucoes)[i] = malloc(4 * sizeof(int));
        }
    }

void maquina(){
        //registradores

        int PC = 0;
        int opcode = INT_MAX; //maior inteiro possivel  (2^31 -1)
        int *umaInstrucao;

        while (opcode != -1)
        {
            umaInstrucao = memoriaInstrucoes[PC];
            //printf ("UMA INSTRUÇÃO = %d\n\n\n", umaInstrucao[0]);
            opcode = umaInstrucao[0]; //indice 0 opcode
            switch (opcode)
            {

                //levar pra RAM
                case 0:
                {
                    RAM[umaInstrucao[2]] = umaInstrucao[1];
                    // printf("Levando para RAM o valor: %d\n", umaInstrucao[1]);
                    break;
                }

                //somar
                case 1:
                {
                    //somar
                    int end1 = umaInstrucao[1];
                    int end2 = umaInstrucao[2];

                    //realizando a operacao
                    int conteudoRam1 = RAM[end1];
                    int conteudoRam2 = RAM[end2];
                    int soma = conteudoRam1 + conteudoRam2;

                    //salvando resultado na RAM
                    int end3 = umaInstrucao[3];
                    RAM[end3] = soma;

                    // printf ("Somando %d\n", soma);
                    break;
                }

                //subtrair
                case 2:
                {
                    //subtrair
                    int end1 = umaInstrucao[1];
                    int end2 = umaInstrucao[2];

                    //realizando a operacao
                    int conteudoRam1 = RAM[end1];
                    int conteudoRam2 = RAM[end2];
                    int sub = conteudoRam1 - conteudoRam2;

                    //salvando resultado na RAM
                    int end3 = umaInstrucao[3];
                    RAM[end3] = sub;
        
                    //printf ("Subtraindo %d\n", sub);

                    break;
                }

                //trazer da RAM
                case 3:
                {
                    umaInstrucao[1] = RAM[umaInstrucao[2]];
                    break;
                }
            }
            PC++;
        }
        
}

void menu(int nLinhas, int multiplicando, int multiplicador, int dividendo, int divisor, int aux, int anterior, 
int lado, int base, int expoente, int numero, int altura, int raio, int maior, int menor, int velocidade, int tempo, int baseT)
{

    int opcao;

    printf("\n--------- BEM VINDO A MAQUINA ---------\n");

    do{
        printf("\n----------------MENU-------------------\n\n");
        printf("1 = Programa aleatório\n");
        printf("2 = SOMA\n");
        printf("3 = SUBTRAÇÃO\n");
        printf("4 = MULTIPLICAÇÃO\n");
        printf("5 = DIVISÃO\n");
        printf("6 = POTENCIA\n");
        printf("7 = AREA DO CIRCULO\n");
        printf("8 = AREA DO RETANGULO\n");
        printf("9 = AREA DO TRIANGULO\n");
        printf("10 = AREA DO LOSANGO\n");
        printf("11 = DISTANCIA\n");
        printf("12 = VOLUME DO CUBO\n");
        printf("13 = FATORIAL\n");
        printf("14 = TESTES\n");
        printf("0= Sair\n\n");
        printf("INFORME A OPÇÃO: ");
        scanf("%d", &opcao);
        printf("\n---------------------------------------\n\n");

        printf("Informe os valores:");

        switch (opcao){
            int resultado;

            case 1:
                montarInstrucoesProgramaAleatorio();
                break;

            case 2:
                soma();
                resultado = RAM[3];
                printf("\nSOMA: %d\n\n", resultado);
                break;

            case 3:
                subtracao();
                resultado = RAM[3];
                printf("\n SUBTRAÇÃO: %d\n\n", resultado);
                break;

            case 4:
                nLinhas = multiplicando + 3;

                multiplicacao(multiplicando, multiplicador);
                resultado = RAM[1];
                printf("\nMultiplicação = %d \n\n", resultado);

                break;

            case 5:
                divisao(dividendo, divisor);
                resultado = cont;
                printf("\nDivisão = %d\n\n", resultado);
                break;

            case 6:
                potencia(base, expoente);
                break;

            case 7:    
                areaCirculo(raio);
                break;

            case 8:    
                areaRetangulo(base, altura);
                break;

            case 9:
                areaTriangulo(baseT, altura);
                break;

            case 10:
                areaLosango(maior, menor);
                break;

            case 11:
                distancia(velocidade, tempo);
                break;

            case 12:    
                volumeCubo(lado);
                break;

            case 13:
                fatorial(numero);
                break;

            case 14: //TESTES
                
                //raizquadrada(numero);
                break;

            case 0:
                printf("FIM!\n");
                break;
            }
    } while (opcao != 0);
}

void montarInstrucoesProgramaAleatorio(){
    //01:22:13:45 => isto é uma instrução na lingua CAVE LANGUAGE
	
    // 0 => somar
	// 1 => subtrair
    // 2 => salvar na RAM
	// 3 => trazer da RAM
    //-1 => halt

    int i;
    srand(time(NULL));

    for( i = 0; i < 9; i++){

        memoriaInstrucoes[i][0] = rand() % 4;
        memoriaInstrucoes[i][1] = rand() % 100;
        memoriaInstrucoes[i][2] = rand() % 100;
        memoriaInstrucoes[i][3] = rand() % 100;
    }

    //inserindo a ultima instrução do programa
    memoriaInstrucoes[9][0] = -1;
    memoriaInstrucoes[9][1] = -1;
    memoriaInstrucoes[9][2] = -1;
    memoriaInstrucoes[9][3] = -1;
   
    maquina();
    printf("Numeros aleatorios gerados!\n");
}

void multiplicacao(int multiplicando, int multiplicador){
    
    int* umaInstrucao = NULL;

    umaInstrucao = malloc (4 * sizeof(int));
    umaInstrucao[0] = 0;   //Levar para RAM
    umaInstrucao[1] = multiplicando;
    umaInstrucao[2] = 0;      // levando pra RAM
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao;
  
    //zera pra entrar no for
    umaInstrucao = malloc(4 * sizeof(int));
    umaInstrucao[0] = 0;			//Levar para RAM
	umaInstrucao[1] = 0;   //valor levado pra RAM = multiplicador 
	umaInstrucao[2] = 1; 			//RAM[1]
	umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;
    
    //precisa zerar pra poder entrar no for e não começar com lixo

    for(int i=0; i < multiplicador; i++){
        umaInstrucao = malloc(4 * sizeof(int));
        umaInstrucao[0] = 1;         //opcode para soma sempre
		umaInstrucao[1] = 0;         //RAM[0]
		umaInstrucao[2] = 1;         //RAM[1]
		umaInstrucao[3] = 1;         //RAM[1]
        memoriaInstrucoes[i+2] = umaInstrucao;
	}

    umaInstrucao = malloc(4 * sizeof(int));
    umaInstrucao[0] = -1; 
	umaInstrucao[1] = -1;       //opcode para sair
	umaInstrucao[2] = -1;         
	umaInstrucao[3] = -1;  
    memoriaInstrucoes[multiplicador+2] = umaInstrucao;

    //fazer a operação
    maquina();
    
}

void divisao(int dividendo, int divisor)
{
    int *umaInstrucao = NULL;
    umaInstrucao = malloc(4 * sizeof(int));
    umaInstrucao[0] = 0;
    umaInstrucao[1] = divisor;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[0] = umaInstrucao; // vetor de 4 posicoes
    //RAM[0] = divisor


    umaInstrucao = malloc(4 * sizeof(int));
    umaInstrucao[0] = 0;
    umaInstrucao[1] = dividendo;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[1] = umaInstrucao;
    //RAM[1] = dividendo

    umaInstrucao = malloc(4 * sizeof(int));
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[2] = umaInstrucao;
    //RAM[2] = 1
    //representa uma constante de incremento

    umaInstrucao = malloc(4 * sizeof(int));
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[3] = umaInstrucao;
    //RAM[3] = 0
    //representa quantas subtracoes foram feitas
    //representa o resultado da divisao
    


    umaInstrucao = malloc(4 * sizeof(int));
    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;
    memoriaInstrucoes[4] = umaInstrucao;

    maquina();
   
    int Ram0 = dividendo;
    cont = 0;
    while (Ram0 >= divisor)
    {
        
        //subtrair
        umaInstrucao = malloc(4 * sizeof(int));
        umaInstrucao[0] = 2;
        umaInstrucao[1] = 1;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = 1;
        memoriaInstrucoes[2] = umaInstrucao;
        maquina();

        //trazer da RAM[0]
        umaInstrucao = malloc(4 * sizeof(int));
        umaInstrucao[0] = 3;
        umaInstrucao[1] = divisor;
        umaInstrucao[2] = 0;
        umaInstrucao[3] = -1;
        memoriaInstrucoes[0] = umaInstrucao;
        maquina();

        //trazer da RAM[1]
        umaInstrucao = malloc(4 * sizeof(int));
        umaInstrucao[0] = 3;
        umaInstrucao[1] = RAM[1];
        umaInstrucao[2] = 1;
        umaInstrucao[3] = -1;
        memoriaInstrucoes[1] = umaInstrucao;
        maquina();
        Ram0 -= divisor;
        cont++;
    }
}

void desalocarMI(int nLinhas)
{

    for (int i = 0; i < nLinhas; i++){
        free(memoriaInstrucoes[i]);
    }
    free(memoriaInstrucoes);
}

void fibonacci(int aux, int anterior, int nLinhas){
    //fibonacci 
    
    memoriaInstrucoes[0][0] = 0; //LEVAR PARA ram
    memoriaInstrucoes[0][1] = aux;
    memoriaInstrucoes[0][2] = 0; //NA POSIÇÃO RAM[0]
    memoriaInstrucoes[0][3] = -1;
    //RAM[AUX, LIXO1, LIXO2, LIXO...., LIXO99]

    memoriaInstrucoes[1][0] = 0;   //LEVAR PARA ram
    memoriaInstrucoes[1][1] = anterior; //anterior
    memoriaInstrucoes[1][2] = 1;   //NA POSIÇÃO RAM[1]
    memoriaInstrucoes[1][3] = -1;
    //RAM[AUX, ANT, LIXO2, LIXO...., LIXO99]

    memoriaInstrucoes[2][0] = 1; // para ser tudo soma
    memoriaInstrucoes[2][1] = 0; //pega da RAM[0]
    memoriaInstrucoes[2][2] = 1; //pega da RAM[1]
    memoriaInstrucoes[2][3] = 3; //armazena o resultado na RAM[3]

    memoriaInstrucoes[3][0] = -1; //HALT
    memoriaInstrucoes[3][1] = -1;
    memoriaInstrucoes[3][2] = -1;
    memoriaInstrucoes[3][3] = -1;

    maquina();

    int end1 = memoriaInstrucoes[0][2];
    int end2 = memoriaInstrucoes[1][2];
    int end3 = memoriaInstrucoes[2][3];

    printf("Fibonacci 1\n");

        for (int i = 0; i <= nLinhas; i++)
    {
        if (RAM[end1] == 0)
        {
            printf("Fibonacci %d\n", RAM[end1]);
        }
        printf("Fibonacci %d\n\n", RAM[end2]);
        memoriaInstrucoes[0][1] = RAM[end2]; // aux
        memoriaInstrucoes[1][1] = RAM[end3]; // ant
        maquina();
    }
}

void areaQuadrado(int lado){
    int area;
    multiplicacao(lado, lado);

    area = RAM[1];
    printf("Area do Quadrado: %d\n\n", area);
}

void potencia(int base, double expoente){
    multiplicacao (base, base);
    for (int i = 0; i < expoente-2; i++)
    {
        multiplicacao(RAM[1], base);
    }
    if (aux == 1) {
        printf("Potencia: %d\n\n", RAM[1]);
        aux++;
    }
}

void areaCirculo(int raio) {
    int pi = 3;
    potencia(raio, 2);
    raio = RAM[1];
    multiplicacao(pi, raio);
    int ac = RAM[1];

    printf("Area do Circulo: %d\n\n", ac);
}

void areaRetangulo(int base, int altura)
{

    int ar;
    multiplicacao(base, altura);
    ar = RAM[1];
    printf("Area do Retangulo: %d\n\n", ar);
}

void volumeCubo(int lado)
{
    int resultado;
    multiplicacao(lado, lado);
    multiplicacao(RAM[1], lado);
    resultado = RAM[1];
    printf("Volume do Cubo: %d\n\n", resultado);
}

void distancia(int velocidade, int tempo)
{
    int distancia;
    multiplicacao(velocidade, tempo);

    distancia = RAM[1];
    printf("Distancia: %d\n\n", distancia);
}

void fatorial(int numero)
{
    int fatorial = 1;

    for (int i = numero; i > 0; i--)
    {
        multiplicacao(fatorial, i);
        fatorial = RAM[1];
    }
    printf("\nFatorial de %d: %d\n", numero, RAM[1]);
}

void areaTriangulo(int base, int altura){
    int area;
    multiplicacao(base, altura);
    divisao(RAM[1], 2);
    area = cont;
    printf("Area do Triangulo: %d\n", area);
}

void areaLosango(int maior, int menor){
    int resultado;
    multiplicacao(maior, menor);
    resultado = RAM[1];
    divisao(resultado, 2);
    

    printf("Area do Losango: %d\n", cont);
}

//não funciona
void raizquadrada(int numero){
    int resultado;
    potencia(numero, 0.5);
    resultado = RAM[1];
    

    printf("Raiz Quadrada: %d\n\n", resultado);
}

void soma(){
    int soma1, soma2;

    printf("\nTermo 1:");
    scanf("%d", &soma1);
    printf("Termo 2:");
    scanf("%d", &soma2);

    memoriaInstrucoes[0][0] = 0; //LEVAR PARA ram
    memoriaInstrucoes[0][1] = soma1;
    memoriaInstrucoes[0][2] = 0; //NA POSIÇÃO RAM[0]
    memoriaInstrucoes[0][3] = -1;
    //RAM[AUX, LIXO1, LIXO2, LIXO...., LIXO99]

    memoriaInstrucoes[1][0] = 0;        //LEVAR PARA ram
    memoriaInstrucoes[1][1] = soma2; 
    memoriaInstrucoes[1][2] = 1;        //NA POSIÇÃO RAM[1]
    memoriaInstrucoes[1][3] = -1;
    //RAM[AUX, ANT, LIXO2, LIXO...., LIXO99]

    memoriaInstrucoes[2][0] = 1; // para ser tudo soma
    memoriaInstrucoes[2][1] = 0; //pega da RAM[0]
    memoriaInstrucoes[2][2] = 1; //pega da RAM[1]
    memoriaInstrucoes[2][3] = 3; //armazena o resultado na RAM[3]

    memoriaInstrucoes[3][0] = -1; //HALT
    memoriaInstrucoes[3][1] = -1;
    memoriaInstrucoes[3][2] = -1;
    memoriaInstrucoes[3][3] = -1;

    maquina();
}

void subtracao(){
    int sub1, sub2;

    printf("\nTermo 1:");
    scanf("%d", &sub1);
    printf("Termo 2:");
    scanf("%d", &sub2);

    memoriaInstrucoes[0][0] = 0; //LEVAR PARA ram
    memoriaInstrucoes[0][1] = sub1;
    memoriaInstrucoes[0][2] = 0; //NA POSIÇÃO RAM[0]
    memoriaInstrucoes[0][3] = -1;
    //RAM[AUX, LIXO1, LIXO2, LIXO...., LIXO99]

    memoriaInstrucoes[1][0] = 0; //LEVAR PARA ram
    memoriaInstrucoes[1][1] = sub2;
    memoriaInstrucoes[1][2] = 1; //NA POSIÇÃO RAM[1]
    memoriaInstrucoes[1][3] = -1;
    //RAM[AUX, ANT, LIXO2, LIXO...., LIXO99]

    memoriaInstrucoes[2][0] = 2; // para ser tudo subtração
    memoriaInstrucoes[2][1] = 0; //pega da RAM[0]
    memoriaInstrucoes[2][2] = 1; //pega da RAM[1]
    memoriaInstrucoes[2][3] = 3; //armazena o resultado na RAM[3]

    memoriaInstrucoes[3][0] = -1; //HALT
    memoriaInstrucoes[3][1] = -1;
    memoriaInstrucoes[3][2] = -1;
    memoriaInstrucoes[3][3] = -1;

    maquina();
    }
