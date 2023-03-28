#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct PilhaStruct
{
    /// @brief 
    int dados[TAM];
    int topo;
} PilhaStruct;

void inicializaFila(PilhaStruct* pilha){
    pilha->topo = -1;
}

void push(int elemento, PilhaStruct* pilha, int tamanho){
    int i;

    for(i = pilha->topo + 1; i < tamanho ; i++){
            if(pilha->dados[i] == 0)
            {            
                pilha->dados[i] = elemento;
                pilha->topo++;
                printf("o valor %d foi inserido na fila\n", elemento);
                return;
            }
    }
    printf("pilha cheia!!!o valor %d não foi inserido na fila\n", elemento);
}

void listar(PilhaStruct* pilha){
    int i; 
    if(pilha->topo == -1){
        printf("pilha vazia\n");
        return;
    }

    printf("\nValores da pilha:\n");
    for(i = pilha->topo; i > -1 ; i--) {printf("%d\n", pilha->dados[i]);}
 }

void pop(PilhaStruct* pilha){
    if(pilha->topo == -1){
        printf("pilha vazia\n");
        return;
    }
    int i;    

    printf("\nRetirando ultimo valor inserido da pilha:");
    pilha->dados[pilha->topo] = 0;
    pilha->topo--;
}
 

int buscar(int key, PilhaStruct* pilha){
   int i;    
    if(pilha->topo == -1){
        printf("pilha vazia\n");
        return -1;
    }

    printf("\nbuscando...\n");
    for(i = pilha->topo; i > -1 ; i--){
        if(pilha->dados[i] == key){
            return i;
        }
    }
    return -1;
 }

int main(){
    int tamanho = TAM;
    int elemento = 1;
    PilhaStruct pilha;
    inicializaFila(&pilha);                                             //Define ppilha->topo = -1
    int key;

    while(1){                                                           //loop para inserir elementos na pilha
        printf("\nDigite um elemento para ser adicionado na pilha:");
        scanf(" %d",&elemento);
        if(elemento == 0)
            break;
        push(elemento, &pilha, tamanho);
    }  
    pop(&pilha);                                            //retira o ultimo elemento adicionado na pilha
    listar(&pilha);                                             //lista os elementos da pilha

    printf("\nDigite um elemento para ser adicionado na pilha:");        
    scanf(" %d",&elemento);
    push(elemento, &pilha, tamanho);                                  //Adiciona outro elemento fornecido pelo user na pilha
    listar(&pilha);                                             //lista os elementos da pilha

    printf("\n\n\nDigite um elemento que deseja buscar na pilha:");
    scanf(" %d",&key);

    int res = buscar(key, &pilha);                              //Retorna o indice da "key" fornecida pelo user
    if(res != -1){printf("indice do elemento:%d\n\n", res);}
    else {printf("Nenhum elemento com esse valor encontrado :(\n\n");}
    return (EXIT_SUCCESS);
}