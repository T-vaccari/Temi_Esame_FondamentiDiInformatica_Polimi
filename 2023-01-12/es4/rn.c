#include <stdio.h>
#include <stdlib.h>
/*
Scrivere una funzione che, ricevendo in ingresso una lista dinamica e un intero k > 0, individui il nodo che si trova 
k posizioni dopo il nodo centrale e ne restituisca il puntatore al chiamante. Se tale nodo non esiste, ad esempio 
a causa di un insufficiente numero di nodi nella lista, la funzione deve restituire il valore NULL.*/
typedef struct n_t{
    int elem;
    struct n_t * next;

}nodo_t;
nodo_t * insertNode(nodo_t * testa, int nuovoElemento) {
    nodo_t * nuovoNodo = (nodo_t *)malloc(sizeof(nodo_t));
    nuovoNodo->elem = nuovoElemento;
    nuovoNodo->next = NULL;

    if (testa == NULL) {
        return nuovoNodo;
    }

    nodo_t * temp = testa;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = nuovoNodo;

    return testa;
}
void printList(nodo_t * testa) {
    if (testa == NULL) {
        return;
    }

    nodo_t * temp = testa;

    while (temp != NULL) {
        printf("%d ", temp->elem);
        temp = temp->next;
    }

    printf("\n");
}

nodo_t * cercanodo(nodo_t * ,int );

int main (){

    nodo_t * testa = NULL;

    testa = insertNode(testa,1);
    testa = insertNode(testa,1);
    testa = insertNode(testa,1);
    testa = insertNode(testa,1);
    testa = insertNode(testa,1);
    testa = insertNode(testa,2);
    testa = insertNode(testa,1);
    testa = insertNode(testa,1);
    testa = insertNode(testa,1);
    testa = insertNode(testa,1);
    printList(testa);

    nodo_t * nodo = cercanodo(testa,0);
    printf("%d",nodo->elem);

    return 0;
}

nodo_t * cercanodo(nodo_t * testa,int k){
    nodo_t * temp = testa;
    nodo_t * array= (nodo_t*)malloc(sizeof(nodo_t));
    int counter=0;

    while(temp!=NULL){
        array[counter].next=temp;
        array = (nodo_t *) realloc(array,sizeof(array)+sizeof(nodo_t));
        counter++;
        temp=temp->next;
    }
    int mid=(counter/2);
    if(mid+k>=counter){
        return NULL;
    }else{
        return array[mid+k-1].next;
    }
}

