#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
    int R, F, quant;
    int vet[TAM];
} filavet;

void enfileirar(int valor,  filavet *p){
    if( p -> quant == TAM){
        printf("\n Fila Cheia!");
        exit(0);
    }
    if (p -> R == TAM){
        p -> R = 0;
    } else {
        p -> R++;
    }
    p -> vet[p -> R] = valor;
    p -> quant++;
}

int desenfileirar (filavet *p){
    int elem;
    if( p-> quant == 0){
        printf("\n Fila Vazia!");
        exit(1);
    }
    elem = p -> vet[p -> F];
    if (p -> F == TAM-1){
        p -> F = 0;
    } else {
        p -> F++;
    }
    p -> quant --;
    return elem;
}

int main () {
     filavet fila;
     int valor;
     fila.R = -1;
     fila.F = 0;
     fila.quant = 0;
     for (int i=0; i<TAM; i++){
         printf("Digite o valor a ser enfileirado: \n");
         scanf("%d", &valor);
         enfileirar(valor, &fila);
     }
     for (int i=0; i<TAM; i++){
         printf("\n %d", desenfileirar(&fila));
     }
}
