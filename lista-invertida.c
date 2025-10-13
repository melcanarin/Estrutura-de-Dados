#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dupla{
	char dado;
	struct dupla *elink, *dlink;
}no;

no *criaListaPalavra(char palavra[]){
	no *ini = NULL, *p;
	int i = 0;
	
	while (palavra[i] != 0){
		p = (no*) malloc(sizeof(no));
		p -> dado = palavra[i];
		p -> elink = ini; //próximo nó é antigo
		p -> dlink = NULL; //anterior é NULL (novo início)
		if (ini != NULL){
			ini -> dlink = p; //antigo primeiro nó aponta para o novo anterior
		}
		ini = p; //atualiza o início
		i++;
	}
	return ini;
}

void imprimeInversa(no *p){
	printf("\nPalavra invertida: ");
	while (p != NULL){
		printf("%c", p -> dado);
		p = p -> elink;
	}
	printf("\n");
}

int main(){
	char palavra[100];
	no *lista;
	
	printf("Digite uma plavra: ");
	scanf("%s", palavra);
	lista = criaListaPalavra(palavra);
	
	if (lista != NULL){
		imprimeInversa(lista);
	} else {
		printf("\nLista vazia\n");
	}
	return 0;
}
