#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void enqueue(int elemento, int fila[], int tamanho){
    int i;    
    printf("Inserindo elemento\n");
    for(i = 0; i < tamanho ; i++){
        if(fila[i] == 0){
            fila[i] = elemento;
            return;
        }
    }
    printf("fila cheia o elemento não foi inserido\n");
}

void listar(int fila[], int tamanho){
    int i; 
    if(fila[0]==0){
        printf("fila vazia\n");
        return;
    }

    printf("\nValores da fila:\n");
    for(i = 0; i < tamanho ; i++){
        
        if(fila[i] == 0)
            return;

        printf("%d\n", fila[i]);
    }
 }

void dequeue(int fila[], int tamanho){
    int i;    
    printf("\nRetirando o primeiro valor inserido da fila:");
    for(i = 0; i < tamanho  - 1; i++){
        
        if(fila[i + 1] == 0)
            return;
                    
        fila[i] = fila[i + 1];
        }
    fila[i] = 0;
}
 

int buscar(int key, int fila[], int tamanho){
    int i;    
    printf("\nbuscando...\n");
    for(i = 0; i < tamanho ; i++){
        if(fila[i] == key){
            return i;
        }
    }
    return -1;
 }

int main(){
    int tamanho = TAM;
    int elemento;
    int fila[tamanho];
    int key;

    while(1){
        if(elemento == 0)
            break;
        printf("\nDigite um elemento para ser adicionado na fila:");
        scanf(" %d",&elemento);
        enqueue(elemento, fila, tamanho);
    }
   
    dequeue(fila, tamanho);
    listar(fila, tamanho);
    printf("\n\n"); 
    printf("\nDigite um elemento que deseja buscar na fila:");
    scanf(" %d",&key);
    int res = buscar(key, fila, tamanho);
    if(res != -1){printf("indice do elemento:%d\n\n", res);}
    else {printf("Nenhum elemento com esse valor encontrado :(\n\n");}
    return (EXIT_SUCCESS);
}