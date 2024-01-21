#include <stdio.h>
#include <stdlib.h>


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

int ruota (nodo_t ** head,int k);
void modifica(int ** num);

int main() {
    nodoptr head = NULL; // Initialize an empty linked list
    
    // Populate the linked list with integers
    insertNode(&head, 6);
    insertNode(&head, 8);
    insertNode(&head, 3);
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 4);
    
    
    
    
    // Print the linked list
    printf("Linked List: ");
    printList(head);

    
    ruota(&head,4);

    puts("");
    printf("Linked List: ");
    printList(head);
    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
//10 -> 20 -> 30 -> 12 -> 15 -> 17 -> NULL

int ruota (nodo_t ** head,int k){
    int counter=0;
    nodo_t * temp = *head;
    nodo_t * lastnode = *head;
    nodo_t * save;
    while(temp!= NULL){
        
        if(counter>k){

            lastnode = lastnode->nextnode;
            
            

        }
        save = temp;
        temp = temp->nextnode;
        counter++;
    }
    //printList(lastnode);
    if(k>=counter || counter==0){ //Se la lista è vuota;
        return 1;
    }

    save->nextnode= *head;
    *head=lastnode->nextnode;
    lastnode->nextnode=NULL;
    




    return 1;
}
