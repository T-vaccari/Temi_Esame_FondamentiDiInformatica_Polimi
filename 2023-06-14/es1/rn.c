#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodo{
    char carattere;
    struct nodo * next;

}nodo_t;

typedef nodo_t * nodeptr;
void riempilista(nodeptr Testa,char * array);
void stampalista(nodeptr testa);
void comprimi ( nodeptr testa);
int main (){

    nodeptr testa = (nodeptr) malloc(sizeof(nodo_t)); // Puntatore alla testa della lista;
    testa->next = NULL;
    
    char caratteri[]={'s','a','b','b','b','a','s','s','a','s','e','m','m','m','m','p','r','e'};
    riempilista(testa,caratteri);
    stampalista(testa);
    puts("");
    comprimi(testa);
    stampalista(testa);
    






}

void riempilista (nodeptr testa,char * array){
    nodeptr temp = testa;
    for(int i=0;i<18;i++){
        temp->carattere=array[i];
        nodeptr newnode =(nodeptr) malloc (sizeof(nodo_t));
        temp->next=newnode;
        newnode->next= NULL;
        temp = newnode;
    }
}
void stampalista(nodeptr testa){
    
    while (testa->next != NULL){
        printf("(%c)",testa->carattere);
        testa = testa->next;

    }
}
void comprimi ( nodeptr testa){

    nodo_t * temp = testa;

    while (temp != NULL){
        char hold = temp ->carattere;
        nodo_t * scorri = temp;
        int counter = 0 ;
        while (scorri != NULL && scorri->carattere == hold){
            counter++;
            scorri = scorri ->next;
        }
        if(counter >=2){
            if(scorri == NULL){
                
                temp->next->next= NULL;
                temp->next->carattere=(char)(counter+'0');

            }else{
                temp->next->next=scorri;
                temp->next->carattere=(char)(counter+'0');

            }
        }
        temp = temp->next;
    }
}