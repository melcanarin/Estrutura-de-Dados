#include <stdio.h>
#include <stdlib.h>

typedef struct dupla {
    int dado;
    struct dupla *elink, *dlink;
} no;

no *crialde (int n){
    no *ini = NULL, *p, *aux = NULL;
    int valor;
   
    for (int i =1; i<= n; i++){
        printf("\nDigite o valor %d da lista: ", i);
        scanf("%d", &valor);
       
        p = (no*) malloc(sizeof(no));
        p -> dado = valor;
        p -> elink = NULL;
        p -> dlink = ini;
       
        if (ini != NULL){
            ini -> elink = p;
        } else{
            aux = p; //guarda o primeiro nó
        }
        ini = p; // último nó passa a ser o atual
    }
    return aux; //retorna o primeiro nó
}

void ordenaLista(no *inicio){
    no *i, *j;
    int temp;
    if (inicio == NULL) return;
    for (i = inicio; i -> elink != NULL; i = i -> elink){
        for (j = i -> elink; j != NULL; j = j -> elink){
            if (i -> dado > j -> dado){ //troca simples dos valores
                temp = i -> dado;
                i -> dado = j -> dado;
                j -> dado = temp;
            }
        }
    }
}

void escrevelista(no *p){
    printf("\nLista: ");
    while (p != NULL){
        printf("%d \t", p -> dado);
        p = p -> elink;
    }
    printf("\n");
}

int main(){
    no *primeira;
    int n;
   
    printf("Criando uma lista duplamente encadeada");
   
    do {
        printf("\nEntre com o numero de nós: ");
        scanf("%d", &n);
    } while (n < 0);
   
    primeira = crialde(n);
   
    if (primeira != NULL){
        printf("\nLista original: \n");
        escrevelista(primeira);
        ordenaLista(primeira);
        printf("\nLista ordenada em ordem crescente: \n");
        escrevelista(primeira);
    } else{
        printf("\nLista vazia");
    }
    return 0;
}
