#include <stdio.h>
#include <stdlib.h>

int main() {

    int number = 10;
    int * numberP = &number;
    int ** numberPP = &numberP;

    printf("valor da variavel number: %d\n", number);
    printf("endereço da variavel number: %p\n", &number);
    printf("valor da variavel number: %p\n", numberP);
    printf("valor apontado por numberP: %d\n", *numberP);
    printf("Endereço de memoria da variavel numberP: %p\n\n", &numberP);
    printf("Endereço de memoria da variavel numberPP: %p\n\n", &numberPP);
    printf("Conteudo de numberPP: %p\n", numberPP);
    printf("valor apontado no primeiro nivel de numberPP: %p\n", *numberPP);
    printf("valor apontado no ultimo nivel de numberpP: %d\n\n", **numberPP);
   // printf("valor da variavel numberP++: %p\n: ", ++numberP);
  /*
    float *pi = (float *) malloc(sizeof(float));

    printf("endereço de pi: %p\n", pi);
    *pi = 3,1415;
    //*pi = 0; para garantir a limpeza do conteudo caso free não faça
    free(pi);

    printf("valor de pi após free: %f\n", *pi);
    printf("valor de pi após free: %p\n", pi);
    pi = NULL; //Para garantir que o endereço não possa ser usado por acidente 
    printf("endereço de pi após atribuição: %p\n", pi); */

    return EXIT_SUCCESS;
}