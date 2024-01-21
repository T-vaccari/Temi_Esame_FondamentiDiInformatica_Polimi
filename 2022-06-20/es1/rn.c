#include <stdio.h>
#include <stdlib.h>
typedef struct n_t{
    int numero;
    struct n_t * nextnode;
}nodo_t;


/*Si supponga di avere, già presente in memoria (non è quindi 
necessario crearla), una lista che memorizza una sequenza di interi. I nodi della lista sono definiti in base 
al seguente tipo: 
typedef struct nodo { 
 int val; 
 struct nodo * next; 
} Nodo; 
Si scriva una funzione ricorsiva in C che, ricevuta come parametro la testa della lista, modifichi i valori 
nella lista sommando a ogni elemento il valore dell’elemento precedente. Il primo elemento resta 
invariato.  
Es. :  Data la lista 1-> 2-> 10-> 3-> 6  la funzione la modificherà in  1 -> 3 -> 12 -> 13 -> 9*/
void printlist(nodo_t * head){
    printf("List : ");
    nodo_t * temp = head ;

    while (temp != NULL){
        printf("%d -> ",temp->numero);
        temp = temp->nextnode;
    }
    printf("NULL");
}
void insertnode ( nodo_t ** head , int data){
    nodo_t * newnode = (nodo_t *) malloc(sizeof(nodo_t));
    newnode->nextnode = NULL;
    newnode->numero = data; 
    if(*head==NULL){
        
        *head = newnode;
        
    }else{

        nodo_t * last = *head;
        nodo_t * temp = *head;
        while (temp != NULL){
            last= temp;
            temp=temp->nextnode;
        }
        last->nextnode=newnode;


    }


}
void sommanodi(nodo_t * testa);

int main (){


    nodo_t * testa = NULL;
    insertnode(&testa,1);
    insertnode(&testa,2);
    insertnode(&testa,10);
    insertnode(&testa,3);
    insertnode(&testa,6);
    printlist(testa);

    sommanodi(testa);
    puts("");
    printlist(testa);
    return 0;
}

void sommanodi(nodo_t * testa){


    if(testa->nextnode->nextnode != NULL){
        sommanodi(testa->nextnode);
        
    }
    testa->nextnode->numero=testa->nextnode->numero+testa->numero;

    return;



}
