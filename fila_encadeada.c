#include <stdio.h>
#include <stdlib.h>

// definição da estrutura que representa um nó da lista encadeada
typedef struct SFila {
    int dado;                               // valor armazenado no nó
    struct SFila *next;                     // ponteiro para o próximo nó da lista
} TFila;

// função responsável por criar o primeiro nó da lista
void primeiro(int info, TFila **fila) {
    (*fila) = malloc(sizeof(TFila));           // aloca memória para o primeiro nó
    (*fila)->dado = info;                      // atribui o valor informado ao nó
    (*fila)->next = NULL;                      // o primeiro nó aponta para NULL
}

// função responsável por adicionar novos nós à lista
void proximos(int info, TFila *fila) {
    TFila *novo = malloc(sizeof(TFila));    // aloca memória para o novo nó
    TFila *ultimo;                          // ponteiro para o último nó da lista

    novo->dado = info;                      // atribui o valor informado ao novo nó
    novo->next = NULL;                      // o novo nó aponta para NULL

    ultimo = fila;                          // começa a busca pelo último nó a partir do primeiro
    while (ultimo->next != NULL) {          // percorre a lista até o último nó
        ultimo = ultimo->next;
    }

    ultimo->next = novo;                    // insere o novo nó após o último nó
}

// função que adiciona um novo nó à lista, chamando primeiro() ou proximos() conforme a situação
void enqueue(int info, TFila **fila) {
    if (*fila == NULL)                       // se a lista estiver vazia, cria o primeiro nó
        primeiro(info, fila);
    else                                    // se já houver nós na lista, adiciona o novo nó após o último
        proximos(info, *fila);
}

// função que imprime na tela todos os valores da lista
void listar( TFila *fila) {
    TFila *ultimo;                          // ponteiro para o último nó da lista
    printf("\n\nValores da lista\n");
    ultimo = fila;                          // começa a busca pelo último nó a partir do primeiro
    while (ultimo != NULL) {                // percorre a lista até o último nó
        printf("%d\n", ultimo->dado);       // imprime o valor armazenado no nó
        ultimo = ultimo->next;              // avança para o próximo nó
    }
}

// função que busca um nó com um determinado valor na lista
TFila *buscar(int key, TFila *fila) {
    TFila *ultimo;                          // ponteiro para o último nó da lista
    ultimo = fila;                          // começa a busca pelo último nó a partir do primeiro
    while (ultimo != NULL) {                // percorre a lista até o último nó
        if (ultimo->dado == key)            // verifica se o valor do nó é igual ao valor buscado
            return ultimo;                  // se sim, retorna um ponteiro para o nó
        ultimo = ultimo->next;              // avança para o próximo nó
    }

    return NULL;                            // se não encontrar nenhum nó com o valor buscado, retorna NULL
}

// função que remove o primeiro nó da lista
void dequeue(TFila **fila){
    TFila * destroyer = *fila;               // ponteiro para o primeiro nó da lista
    *fila = (*fila)->next;                      // define o próximo nó como o primeiro da lista
    free(destroyer);                        // libera o nó que foi removido da memória
}

int main(int argc, char** argv) {
    TFila *fila = NULL;                     // ponteiro para o primeiro nó da lista (sentinela) 
    int leitura;
    int chave, i = 0;
    TFila * posicao;

    while(1){
    printf("Informe o valor: ");
        scanf("%d",&leitura);
        if (leitura == 0)
        break;

        enqueue(leitura, &fila);                   // adiciona um novo nó na lista
    }
    listar(fila);                               

    dequeue(&fila);                              // remove o primeiro nó da lista
    dequeue(&fila);                              // remove o segundo nó da lista
    listar(fila);

    printf("Informe o valor que deseja buscar: ");
    scanf("%d",&chave);

    posicao = buscar( chave, fila);               // busca um nó com um determinado valor na lista

    if (posicao == NULL){
        printf("Não encontramos nenhum registro para a sua busca\n\n");
    }else{
        printf("O valor foi encontrado na posição: %p\n\n", posicao);
    }

    return (EXIT_SUCCESS);
}