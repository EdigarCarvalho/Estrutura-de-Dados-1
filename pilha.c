#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void push(int elemento, int pilha[], int tamanho){
    int i;    
    printf("\nInserindo elemento\n");
    for(i = 0; i < tamanho ; i++){
        if(pilha[i] == 0){
            pilha[i] = elemento;
            return;
        }
    }
    printf("pilha cheia o elemento não foi inserido\n");
}

void listar(int pilha[], int tamanho){
    int i;

    if(pilha[0] == 0){
        printf("A pilha está vazia :(\n)");
        return;
    }    
    printf("\nValores da pilha:");
    for(i = tamanho - 1; i >= 0 ; i--){
        if(pilha[i] != 0){
            printf("%d\n", pilha[i]);
        }
    }
 }

void pop(int pilha[], int tamanho){
    int i;    
    printf("\nRetirando ultimo valor inserido da pilha:");
    for(i = tamanho - 1; i >= 0 ; i--){
        if(pilha[i] != 0){
            pilha[i] = 0;
            return;
        }
    }
    printf("A pilha está vazia");
 }

int buscar(int key, int pilha[], int tamanho){
    int i;    
    printf("\nbuscando...\n");
    for(i = tamanho - 1; i >= 0 ; i--){
        if(pilha[i] == key){
            return i;
        }
    }
    return -1;
 }

int main(){
    int tamanho = TAM;
    int elemento;
    int pilha[tamanho];
    int key;

    while(1){
        if(elemento == 0)
            break;
        printf("\nDigite um elemento para ser adicionado na pilha:");
        scanf(" %d",&elemento);
        push(elemento, pilha, tamanho);
    }
   
    pop(pilha, tamanho);
    listar(pilha, tamanho);
    printf("\n\n"); 

    printf("\nDigite um elemento que deseja buscar na pilha:");
    scanf(" %d",&key);
    int res = buscar(key, pilha, tamanho);
    if(res != -1){printf("indice do elemento:%d", res);}
    else {printf("Nenhum elemento com esse valor encontrado :(");}

}