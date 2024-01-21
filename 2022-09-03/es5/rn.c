#include <stdio.h>
#include <stdlib.h>

int unisci(FILE * fp1, FILE * fp2, FILE *fp3);
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
int main (int argc,char *argv[]){

    FILE * fp1 = fopen (argv[1],"r");
    FILE * fp2 = fopen (argv[2],"r");
    FILE * fp3 = fopen (argv[3],"w");
    if(unisci(fp1,fp2,fp3)){
        printf("Tutto ok!");
    }


}

int unisci(FILE * fp1, FILE * fp2, FILE *fp3){

    nodo_t * head = NULL;
    nodo_t * newnode=(malloc(sizeof(nodo_t)));
    newnode->nextnode=NULL;
    nodo_t * last;
    if(newnode == NULL){
        printf("Malloc error");
        return 0;
    }
    head = newnode;
    
    int hold;
    while (fscanf(fp1, "%d", &hold) != EOF) {
        nodo_t *temp = head;
        nodo_t *newnode = (nodo_t *)malloc(sizeof(nodo_t));
        
        if (newnode == NULL) {
            printf("Malloc error");
            return 0;
        }

        newnode->numero = hold;

        if (temp == NULL || hold < temp->numero) {
            // Inserimento del nuovo nodo all'inizio
            newnode->nextnode = head;
            head = newnode;
        } else {
            // Inserimento ordinato
            nodo_t *last = NULL;
            while (temp != NULL && hold > temp->numero) {
                last = temp;
                temp = temp->nextnode;
            }

            if (temp != NULL && hold == temp->numero) {
                // Nodo duplicato, dealloca il nuovo nodo
                free(newnode);
            } else {
                // Inserimento del nuovo nodo in mezzo alla lista
                newnode->nextnode = temp;
                last->nextnode = newnode;
            }
    }
}
    
    while(fscanf(fp2,"%d",&hold) != EOF){
        nodo_t * temp = head;
        nodo_t * newnode = (nodo_t *) malloc(sizeof(nodo_t));
        newnode->numero=hold;

        if(temp == NULL || hold < temp->numero){
            newnode->nextnode=head;
            head=newnode;
        }else{

            while(temp != NULL && hold>temp->numero){
                last = temp;
                temp=temp->nextnode;
            }
            if(temp != NULL && temp->numero == hold){
                free(newnode);
            }else{
                last->nextnode= newnode;
                newnode->nextnode=temp;
            }



        } 
        
    }
    
    nodo_t * temp = head;

    while (temp !=NULL){
        fprintf(fp3,"%d\n",temp->numero);
        temp=temp->nextnode;
    }

    return 1;





}