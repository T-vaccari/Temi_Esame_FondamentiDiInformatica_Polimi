#include <stdio.h>
#include <stdlib.h>
#define R 4
#define C 8

typedef struct nodo_t{
    int dominante;
    int riga;
    int colonna;
    struct nodo_t * nextnode;


}nodo_t;

typedef  nodo_t * nodePtr;



nodePtr dominante(int matrice [][C]);
void minimointesta(nodePtr *testa);
void ordina (nodePtr * testa);
int main (int argc, char *argv[]){

    FILE * fpin;
    int matrice[R][C];
    fpin = fopen(argv[1],"r");
    int righe;
    fscanf(fpin,"%d",&righe);
    int colonne;
    fscanf(fpin,"%d",&colonne);
    for(int i=0;i<righe;i++){
        for(int j=0;j<colonne;j++){
            fscanf(fpin,"%d",&matrice[i][j]);
        }
    }


    
    nodePtr const lista = dominante(matrice);
    nodePtr temp = lista;
   

    
    temp = lista;
    
    ordina(&temp);
    while(temp!=NULL){
        printf("(%d,%d,%d)",temp->dominante,temp->riga,temp->colonna);
        temp=temp->nextnode;
    }
    




    return 0;
}

nodePtr dominante(int matrice [][C]){

    nodePtr Lista = (nodePtr) malloc(sizeof(nodo_t)); // Creo il puntatore alla testa della lista
    Lista->nextnode= NULL;
    nodePtr testa = Lista;
    for(int i=0 ;i<R-1;i++){
        for(int j=0 ; j<C-1;j++){ //Controllo ogni elemento che non si trovi nella ultima riga o colonna
            int flag = 0;
            for(int k=i+1;k<R && flag ==0;k++){ //Controllo ogni elemento della sottomatrice
                for(int z=j+1;z<C && flag==0;z++){

                    if(matrice[i][j]<=matrice[k][z]){
                        flag=1;
                    }

                }
            }

            if(flag==0){ //Se è un dominante lo metto nella lista
                //printf("%d",matrice[i][j]);
                testa->dominante=matrice[i][j];
                testa->riga=i;
                testa->colonna=j;
                
                nodePtr newnode = (nodePtr)malloc(sizeof(nodo_t));

                newnode->nextnode= testa;
                testa=newnode;
                



            }


        }
    }















    return testa->nextnode ;


}
void minimointesta(nodePtr *testa) {

    nodePtr temp = *testa;
    int minimo= temp->dominante;
    nodePtr nodominimo = temp;
    while(temp!=NULL){
        if(minimo>temp->dominante){
            minimo = temp->dominante;
            nodominimo = temp;
        }
        temp=temp->nextnode;
    }
    temp = *testa;
    int flag=0;
    if(nodominimo != *testa){

        while(temp != NULL&&flag==0){
            if((temp->nextnode)->dominante== minimo){
                temp->nextnode = nodominimo->nextnode;

                flag=1;

            }
        }
        nodominimo->nextnode= *testa;
        *testa= nodominimo;
    }
    
    
}
void ordina (nodePtr * testa){

    if( testa == NULL){
        return;
    }

    minimointesta(&((*testa)->nextnode));




}