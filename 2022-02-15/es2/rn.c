#include <stdio.h>
#include <stdlib.h>

typedef struct nt1
{
    int numero;
    struct nt1* nextnode;

}nodo_t1 ;

typedef struct nt
{
    int numero;
    int occ;
    struct nt* nextnode;

}nodo_t2 ;

void printlist1(nodo_t1 * head){
    printf("List : ");
    nodo_t1 * temp = head ;

    while (temp != NULL){
        printf("%d -> ",temp->numero);
        temp = temp->nextnode;
    }
    printf("NULL");
}
void freelist1(nodo_t1 * head){
    nodo_t1 * current = head;

    while (current != NULL){
        nodo_t1 * temp = current;
        current = current->nextnode;
        free(temp);
    }

}
void insertnode1 ( nodo_t1 ** head , int data){
    nodo_t1 * newnode = (nodo_t1 *) malloc(sizeof(nodo_t1));
    newnode->nextnode = NULL;
    newnode->numero = data; 
    if(*head==NULL){
        
        *head = newnode;
        
    }else{

        nodo_t1 * last = *head;
        nodo_t1 * temp = *head;
        while (temp != NULL){
            last= temp;
            temp=temp->nextnode;
        }
        last->nextnode=newnode;


    }


}



void printlist2(nodo_t2 * head){
    printf("List : ");
    nodo_t2 * temp = head ;

    while (temp != NULL){
        printf("(%d,%d) -> ",temp->numero,temp->occ);
        temp = temp->nextnode;
    }
    printf("NULL");
}
void freelist2(nodo_t2 * head){
    nodo_t2 * current = head;

    while (current != NULL){
        nodo_t2 * temp = current;
        current = current->nextnode;
        free(temp);
    }

}
void insertnode2(nodo_t2 **head, int data) {
    nodo_t2 *newnode = (nodo_t2 *)malloc(sizeof(nodo_t2));
    newnode->nextnode = NULL;
    newnode->numero = data;
    newnode->occ++;

    if (*head == NULL) {
        *head = newnode;
    } else {
        nodo_t2 *last = *head;
        nodo_t2 *temp = *head;
        while (temp != NULL && temp->numero != data) {
            last = temp;
            temp = temp->nextnode;
        }
        if (temp == NULL) {
            last->nextnode = newnode;
        } else {
            free(newnode);
            temp->occ++;
        }
    }
}
nodo_t2 * costruiscilista(nodo_t1 * lista1);
void swapointer(nodo_t2 ** last,nodo_t2 **temp);
void bubblesort(nodo_t2  **testa);
int main (){
    nodo_t1 * testa = NULL;

    insertnode1(&testa,10);
    insertnode1(&testa, 5);
    insertnode1(&testa,8);
    insertnode1(&testa,10);
    insertnode1(&testa, 6);
    insertnode1(&testa,5);
    insertnode1(&testa,4);
    printlist1(testa);
    puts("");
    printlist2(costruiscilista(testa));

    freelist1(testa);



    return 0;
}

nodo_t2 * costruiscilista(nodo_t1 * lista1){
    nodo_t1 * temp = lista1;
    nodo_t2 * testa = NULL;
    while(temp!=NULL){

        insertnode2(&testa,temp->numero);



        temp = temp->nextnode;


    }
    bubblesort(&testa);
    
    return testa;









}
void swapointer(nodo_t2** last, nodo_t2** temp) {
    (*last)->nextnode = (*temp)->nextnode;
    (*temp)->nextnode = (*last)->nextnode->nextnode;
    (*last)->nextnode->nextnode = *temp;
}

void bubblesort(nodo_t2** testa) {
    int change = 1;
    while (change) {
        nodo_t2* temp = *testa;
        nodo_t2* last = NULL;
        change = 0;

        while (temp != NULL && temp->nextnode != NULL) {
            if (temp->numero > temp->nextnode->numero) {
                change = 1;
                if (last == NULL) {
                    // Adjusted this part to properly swap the first two nodes
                    (*testa)=temp->nextnode;
                    temp->nextnode=(*testa)->nextnode;
                    (*testa)->nextnode=temp;
                } else {
                    swapointer(&last, &temp);
                }
            }
            last = temp;
            temp = temp->nextnode;
        }
    }
}
