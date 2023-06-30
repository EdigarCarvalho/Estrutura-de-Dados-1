#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    int i = 0;
    printf("\nElementos da lista: \n");
    
    while (atual != NULL) {
        printf("[%d] %d \n", i, atual->dado);
        atual = atual->proximo;
        i++;
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
    printf("\n%d inserido no índice %d.\n", dadoDoUsuario, index);
}

void removerLista(Descritor * descritor, int index){
    if (index < 0 || index >= descritor->tamanho) {
        printf("O índice está fora do intervalo válido.\n");
        return;
    }

    if(descritor->tamanho == 0){
        printf("Nada para remover, lista vazia.\n");
        return;
    }

    Node* destroyer;

    if(index == 0){
        destroyer = descritor->primeiro;
        descritor->primeiro = descritor->primeiro->proximo;
        if (descritor->primeiro != NULL)
            descritor->primeiro->anterior = NULL;
        if (descritor->ultimo == destroyer)
            descritor->ultimo = NULL;

    } else if(index == descritor->tamanho - 1) {
        destroyer = descritor->ultimo;
        descritor->ultimo = descritor->ultimo->anterior;
        descritor->ultimo->proximo = NULL;
        if (descritor->primeiro == destroyer)
            descritor->primeiro = NULL;

    } else {
        Node* atual;
        
        if (index <= descritor->tamanho / 2) {
            atual = descritor->primeiro;
            for (int i = 0; i < index - 1; i++) {
                atual = atual->proximo;
            }

        } else {
            atual = descritor->ultimo;
            for (int i = descritor->tamanho - 1; i > index + 1; i--) {
                atual = atual->anterior;
            }

        }

        destroyer = atual->proximo;
        atual->proximo = destroyer->proximo;
        destroyer->proximo->anterior = atual;
    }

    free(destroyer);
    descritor->tamanho--;
    printf("Elemento removido do índice %d.\n", index);
}

int buscar(Descritor* descritor, int key) {
    if (descritor->tamanho == 0) {
        printf("A lista esta vazia.\n");
        return -1;
    }

    Node* atual = descritor->primeiro;
    int i = 0;
    
    while (atual != NULL) {
        if(key == atual->dado)
            return i;

        atual = atual->proximo;
        i++;
    }
    return -1;
}

void wait(){
    fflush(stdout);

    char buffer[1];
    read(STDIN_FILENO, buffer, 1);
}

int main() {
    Descritor lista;
    inicializarDescritor(&lista);

    int opcao = -1;
    int index, dado;

    while (opcao != 0) {
        system("clear");
        printf("\nEscolha uma opção:\n\n"
               "1. Inserir \n"
               "2. Remover \n"
               "3. Buscar \n"
               "4. Imprimir \n"
               "0. Sair\n\n"
               "Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n(tamanho atual da lista: %d)"
                    "\nInforme o valor e o índice: ", lista.tamanho);
                scanf("%d %d", &dado, &index);
                inserirLista(&lista, index, dado);
                break;

            case 2:
                printf("Informe o índice do elemento a ser removido: ");
                scanf("%d", &index);
                removerLista(&lista, index);
                break;

            case 3:
                printf("Informe o valor a ser buscado: ");
                scanf("%d", &dado);
                index = buscar(&lista, dado);
                if (index != -1) {
                    printf("O valor %d foi encontrado no índice %d.\n", dado, index);
                } else {
                    printf("O valor %d não foi encontrado na lista.\n", dado);
                }
                wait();
                break;

            case 4:
                imprimirLista(&lista);
                wait();
                break;
            case 0:
                printf("\nFlw.\n");
                break;
            default:
                printf("Digite uma opção válida :}.\n");
                break;
        }

    }

    return 0;
}