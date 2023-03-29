#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void insere(int elemento, int lista[], int tamanho, int indice){
    if((indice < 0) || (indice > tamanho - 1)){
        printf("indíce invalido, insira um indice no range da lista");
        return;
    }
    lista[indice] = elemento;
    printf("elemento inserido\n");
}

void remove_elemento(int indice, int lista[], int tamanho){
        insere(0, lista, tamanho, indice);
}

int indexcorreto(int elemento, int lista[], int tamanho){
    if(elemento < lista[0]) {return -1;}  
    int i;    
    printf("\nanalisando...\n");
    for(i = 0; i < tamanho ; i++){
        if(elemento < lista[i]) {return i;}
    }
    return tamanho;
}


void listar(int lista[], int tamanho){
    int i; 

    printf("\nValores da lista:\n");
    for(i = 0; i < tamanho ; i++){
        
        if(lista[i] == 0){continue;}

        printf("[%d] -> %d\n", i, lista[i]);
    }
 }

 

int buscar(int key, int lista[], int tamanho){
    int i;    
    printf("\nbuscando...\n");
    for(i = 0; i < tamanho ; i++){
        if(lista[i] == key){
            return i;
        }
    }
    return -1;
 }

int main(){
    int tamanho = TAM;
    int elemento = 1;
    int lista[tamanho];
    int key;
    int indice;

    while(1){
        printf("\nDigite um elemento e a posição (0 até %d)para ser adicionado na lista:", tamanho - 1);
        scanf(" %d %d",&elemento, &indice);
        if(elemento == 0)
            break;
        insere(elemento, lista, tamanho, indice);
    }
   
    listar(lista, tamanho);
    printf("Digite um valor para saber em qual indice ele seria inserido:");
    scanf(" %d",&elemento);
    indice = indexcorreto(elemento, lista, tamanho);
    printf("indice do elemento:%d\n\n", indice);
    if(indice == -1){printf("menor do que o primeiro elemento");}
    else if(indice == tamanho){printf("maior do que o ultimo elemento");}

    printf("\nDigite uma posição (0 até %d)para remover o elemento na lista:", tamanho - 1);
    scanf(" %d", &indice);
    remove_elemento(indice, lista, tamanho);
    listar(lista, tamanho);


    printf("\n\n"); 
    printf("\nDigite um elemento que deseja buscar na lista:");
    scanf(" %d",&key);
    int res = buscar(key, lista, tamanho);
    if(res != -1){printf("indice do elemento:%d\n\n", res);}
    else {printf("Nenhum elemento com esse valor encontrado :(\n\n");}
    return (EXIT_SUCCESS);
}