#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dado;
    struct Node* proximo;
    struct Node* anterior;
} Node;

typedef struct Descritor {
    int tamanho;
    Node* primeiro;
    Node* ultimo;
} Descritor;

void inicializarDescritor(Descritor* descritor) {
    descritor->tamanho = 0;
    descritor->primeiro = NULL;
    descritor->ultimo = NULL;
}

void imprimirLista(Descritor* descritor) {
    if (descritor->tamanho == 0) {
        printf("A lista esta vazia.\n");
        return;
    }

    Node* atual = descritor->primeiro;

    printf("Elementos da lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void inserirLista(Descritor* descritor, int index, int dadoDoUsuario){
    if((index < 0) && (index >= descritor->tamanho)){
        printf("A index fora do range da lista.\n");
        return;
    }

    Node* atual = descritor->primeiro;

    for(int i = 0; i < descritor->tamanho ; i++ , atual= atual->)
}

int main() {
    Descritor lista;
    inicializarDescritor(&lista);

    imprimirLista(&lista);

    return 0;
}
