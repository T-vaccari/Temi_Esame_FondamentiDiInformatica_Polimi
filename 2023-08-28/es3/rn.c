#include <stdio.h>     // Libreria standard di input/output
#include <stdlib.h>    // Libreria standard di utilità generale
#include <string.h>    // Libreria standard per la manipolazione di stringhe
#include <math.h>      // Libreria standard per funzioni matematiche
#include <ctype.h>     // Libreria standard per la manipolazione di caratteri
#include <time.h>      // Libreria standard per funzionalità legate al tempo
#include <stdbool.h>   // Libreria standard per il tipo di dato booleano
#include <stdint.h>    // Libreria standard per tipi di dati interi di larghezza fissa
#include <stddef.h>    // Libreria standard per la definizione di tipi e macro
#define N 10


struct node_t{
    int indice1;
    int indice2;
    struct node_t * nextPtr;
};
typedef struct node_t node_t;
typedef node_t * nodePtr;



nodePtr trovapartizioni(int a[],int numsize,int y);
void createnode(node_t * lista,int indice1,int i);
void stampalista(nodePtr lista);
int main (){

    int a [8]= {2, 8, 0, 3, 9, 6, 1, 3};
    
    nodePtr lista = trovapartizioni(a,8,10);

    stampalista(lista);








    


    return 0;
}

void createnode(node_t *lista,int indice1,int i){
    nodePtr temp=lista;
    if(lista->nextPtr==NULL){

        lista->indice1=indice1;
        lista->indice2=i;
        nodePtr newnode= (nodePtr) malloc(sizeof(node_t));
        newnode->nextPtr=NULL;
        lista->nextPtr=newnode;

    }else{
        while(temp->nextPtr != NULL){
            temp = temp->nextPtr;
        }
        temp->indice1=indice1;
        temp->indice2=i;
        nodePtr newnode= (nodePtr) malloc(sizeof(node_t));
        newnode->nextPtr=NULL;
        temp->nextPtr=newnode;




    }

}

nodePtr trovapartizioni(int a[],int asize,int y){

    nodePtr lista = (nodePtr) malloc(sizeof(node_t));
    lista->nextPtr=NULL;

    int somma=0;
    int indice=0;
    //2, 8, 0, 3, 9, 6, 1, 3
    for(int i=0;i<asize;i++){
        
        somma = somma+a[i];

        if(somma>y){
            somma=0;
            
            createnode(lista, indice,i-1);
            somma= somma+a[i];
            indice = i;


        }

        
        
        

    }
    if (somma > 0) {
        
        createnode(lista, indice,asize-1);
    }
    return lista;

}
void stampalista ( nodePtr lista){
    nodePtr temp = lista;

    while(temp!=NULL){
        printf("%d,%d|",temp->indice1,temp->indice2);
        temp = temp->nextPtr;
    }
}
    
    
    

    




