#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node * next;
};

void insert(struct Node ** head_ref, int data){
    //Allocate memory for a new node
    struct Node * new_head = (struct Node *)malloc(sizeof(struct Node));

    //Set the data and next pointer to the node
    new_head->value = data;
    new_head->next = (*head_ref);

    //Update the head_ref
    (*head_ref) = new_head;
}

void printList(struct Node * node){
    //Loop though the list printint the data values until a node be NULL
    while(node != NULL){
        printf(" %d", node->value);
        node = node->next;
    }
}

int main(){
    //Create a head of the type struct Node that will be the last node in the list
    struct Node * head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    
    printList(head);

    return 0;
}