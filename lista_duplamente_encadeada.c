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
    
    if (index < 0 || index > descritor->tamanho) {
        printf("O índice está fora do intervalo válido.\n");
        return;
    }

    Node* novoNode = (Node*) malloc(sizeof(Node));
    
    if (novoNode == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    novoNode->dado = dadoDoUsuario;
    novoNode->proximo = NULL;
    novoNode->anterior = NULL;

    if (descritor->tamanho == 0) {                            //Lista vazia 
        descritor->primeiro = novoNode;
        descritor->ultimo = novoNode;
    
    } else if (index == 0) {                                  //Insere no começo da lista
        novoNode->proximo = descritor->primeiro;
        descritor->primeiro->anterior = novoNode;
        descritor->primeiro = novoNode;
    
    } else if (index == descritor->tamanho) {                 //Insere no fim da lista
        novoNode->anterior = descritor->ultimo;
        descritor->ultimo->proximo = novoNode;
        descritor->ultimo = novoNode;
    
    } else {                                                 //Insere no index especificado
        
        Node* atual;

        if (index <= descritor->tamanho / 2) {               //Se o index estiver entre o inicio e a metade da lista
            atual = descritor->primeiro;
            for (int i = 0; i < index - 1; i++) {
                atual = atual->proximo;
            }

        } else {                                             //Caso contrário: entre metade e fim da lista
            atual = descritor->ultimo;
            for (int i = descritor->tamanho - 1; i > index; i--) {
                atual = atual->anterior;
            }

        }

        novoNode->proximo = atual->proximo;
        novoNode->anterior = atual;
        atual->proximo->anterior = novoNode;
        atual->proximo = novoNode;
    }

    descritor->tamanho++;
    printf("%d inserido no índice %d.\n", dadoDoUsuario, index);
}

int main() {
    Descritor lista;
    inicializarDescritor(&lista);

    imprimirLista(&lista);

    inserirLista(&lista, 0, 10);
    inserirLista(&lista, 1, 20);
    inserirLista(&lista, 1, 15);
    inserirLista(&lista, 3, 25);
    inserirLista(&lista, 0, 5);
    inserirLista(&lista, 5, 30);

    imprimirLista(&lista);

    return 0;
}
