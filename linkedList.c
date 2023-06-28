#include<stdio.h>
#include<stdlib.h>

int tamanho = -1;

struct Node{
    int value;
    struct Node * next;
};

void createList(struct Node ** head_ref, int data){
    struct Node * new_head = (struct Node *)malloc(sizeof(struct Node));

    new_head->value = data;
    new_head->next = (*head_ref);

    (*head_ref) = new_head;
    tamanho++;
}

void insert(struct Node *node, int value1, int index) {
    if (index < 0 || index > tamanho) {
        printf("Invalid index, enter an index in the list range\n");
        return;
    }

    for (int i = 0; i <= index; i++) {
        if (i == index) {
            if (node != NULL) {
                node->value = value1;
            } else {
                printf("Error: node pointer is NULL\n");
            }
        }
        node = node->next;
    }
}

void printList(struct Node * node){

    while(node != NULL){
        printf(" %d", node->value);
        node = node->next;
    }
    printf("\n");
}

void remove_element(struct Node *node, int index){
        insert(node, 0 , index);
}

int search(struct Node * node, int value){
    for(int i = 0; node != NULL ; i++ , node = node->next){
        if(node->value == value) return i;
    }
    return -1;
}

int main(){
    struct Node * head = NULL;

    createList(&head, 5);
    createList(&head, 4);
    createList(&head, 3);
    createList(&head, 2);
    createList(&head, 1);
    
    printList(head);

    insert(head, 3 , 8);
    insert(head, 9 , 4);

    printList(head);

    remove_element(head, 0);

    printList(head);

    int res = search(head, 9);
    if(res != -1){printf("element index:%d\n\n", res);}
    else {printf("Element index not found :(\n\n");}

    return 0;
}