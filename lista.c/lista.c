#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
}Item;

typedef struct{
    Item *array;
    int Tamanho
    int Capacidade;
}Lista;
Lista* criarLista(int Capacidade) {
    Lista *X = (Lista*) malloc(sizeof(Lista));
    if(X == NULL){
        perror("Erro ao alocar memória para a lista.");
        exit(1);
    }
    X->array = (Item *) malloc (Capacidade * sizeof(Item))
}


int main() {



}
