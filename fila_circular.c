#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct filaCircular
{
    int inicio;
    /// @brief 
    int dados[TAM];
    int fim;
} filaCircular;

void inicializaFila(filaCircular* fila){
    fila->inicio = 0;
    fila->fim = -1;
}

void enqueue(int elemento, filaCircular* fila, int tamanho){

    if(((fila->fim + 1)% tamanho == fila->inicio ) && fila->fim != -1){
        printf("fila cheia!!! o valor %d não foi inserido\n", elemento);
        return;
    }

    fila->fim = (fila->fim + 1) % tamanho;
    fila->dados[fila->fim] = elemento;
    printf("o valor %d foi inserido na fila\n", elemento);
}

void listar(filaCircular* fila, int tamanho){
    int i; 
    if(fila->fim == -1){
        printf("fila vazia\n");
        return;
    }

    printf("\nValores da fila:\n");
    for(i = fila->inicio; i != fila->fim  ; i = (i+1)%tamanho){
        printf("%d\n", fila->dados[i]);
    }
    printf("%d\n", fila->dados[i]);
 }

void dequeue(filaCircular* fila, int tamanho){
    if(fila->fim == -1){
        printf("fila vazia\n");
        return;
    }
    fila->dados[fila->inicio] = 0;
    fila->inicio = (fila->inicio + 1)%tamanho;
}
 

int buscar(int key, filaCircular* fila, int tamanho){
    int i;
    if(fila->dados[fila->fim] == key)
        return fila->fim;

    printf("\nbuscando...\n");
    for(i = fila->inicio; i != fila->fim ; i = (i + 1)%tamanho){
        if(fila->dados[i] == key){
            return i;
        }
    }
    return -1;
 }

int main(){
    int tamanho = TAM;
    int elemento = 1;
    filaCircular fila;
    inicializaFila(&fila);                                             //Define fila->inicio = 0 e fila->fim = -1
    int key;

    while(1){                                                           //loop para inserir elementos na fila
        
        printf("\nDigite um elemento para ser adicionado na fila:");
        scanf(" %d",&elemento);
        if(elemento == 0)
            break;
        enqueue(elemento, &fila, tamanho);
    }  
    dequeue(&fila, tamanho);                                            //retira o primeiro elemento adicionado na fila
    listar(&fila, tamanho);                                             //lista os elementos da fila

    printf("\nDigite um elemento para ser adicionado na fila:");        
    scanf(" %d",&elemento);
    enqueue(elemento, &fila, tamanho);                                  //Adiciona outro elemento fornecido pelo user na fila
    listar(&fila, tamanho);                                             //lista os elementos da fila

    printf("\n\n\nDigite um elemento que deseja buscar na fila:");
    scanf(" %d",&key);

    int res = buscar(key, &fila, tamanho);                              //Retorna o indice da "key" fornecida pelo user
    if(res != -1){printf("indice do elemento:%d\n\n", res);}
    else {printf("Nenhum elemento com esse valor encontrado :(\n\n");}
    return (EXIT_SUCCESS);
}