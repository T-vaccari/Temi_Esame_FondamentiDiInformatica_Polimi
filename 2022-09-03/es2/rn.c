#include <stdio.h>
#include <stdlib.h>
#define LENMAX 200
typedef struct nodo{
    int numero;
    struct nodo * nextnode;

}nodo_t;

typedef nodo_t * nodoptr;



// Function to insert a new node at the end of the linked list
void insertNode(nodoptr* head, int data) {
    nodoptr newnode = (nodoptr)malloc(sizeof(nodo_t));
    if (!newnode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newnode->numero = data;
    newnode->nextnode = NULL;

    if (*head == NULL) {
        *head = newnode; // If the list is empty, the new node becomes the head
    } else {
        nodoptr current = *head;
        while (current->nextnode != NULL) {
            current = current->nextnode;
        }
        current->nextnode = newnode; // Insert the new node at the end
    }
}

// Function to print the linked list
void printList(nodoptr head) {
    nodoptr current = head;
    while (current != NULL) {
        printf("%d -> ", current->numero);
        current = current->nextnode;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(nodoptr head) {
    nodoptr current = head;
    while (current != NULL) {
        nodoptr temp = current;
        current = current->nextnode;
        free(temp);
    }
}
void rimuovirip(nodo_t * head);
int main (){

    nodo_t * head = NULL;

    insertNode(&head,1);
    insertNode(&head,1);
    insertNode(&head,1);
    insertNode(&head,1);
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,2);


    printList(head);
    puts("");
    rimuovirip(head);
    printList(head);



}

void rimuovirip(nodo_t * head){
    int array[LENMAX];
    int len=0;
    nodo_t * temp = head;
    nodo_t * last=head;;

    while (temp != NULL){
        int flag=0;
        for(int i=0 ; i<len && flag==0 ;i++){
            if(temp->numero == array[i]){
                flag=1;
                //printf("dio");
            }
        }
        if(flag==0){
            array[len]=temp->numero;
            len++;
            last = temp;
        }
        if(flag==1 ){
            last->nextnode=temp->nextnode;
            //free(temp);
            
        }
         

        
        temp=temp->nextnode;
    }



}