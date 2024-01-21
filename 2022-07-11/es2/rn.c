#include <stdio.h>
#include <stdlib.h>


int isvalid(int **,int,int,int,int);
int calcola_sm(int ** matrice,int , int ,int);
int main (){
    int riga = 5;
    int colonne = 5;
    int ** matrice=(int **) malloc(sizeof(int*)*riga);
    for(int i=0;i<riga;i++){
        matrice[i]=(int *)malloc(sizeof(int)*colonne);
    }

    
    FILE * fp= fopen("in.txt","r");

    for(int i=0;i<riga;i++){
    for(int j=0;j<colonne;j++){

        fscanf(fp,"%d",&matrice[i][j]);

        }
    }
      
    printf("%d",calcola_sm(matrice,riga,2,7));
    

    for(int i=0;i<riga;i++){
        free(matrice[i]);
    }
    free(matrice);
    return 0;
}

int calcola_sm(int ** matrice,int dimensione, int dimensione_sm ,int val){

    int counter=0;
    for(int i=0;i<=dimensione-dimensione_sm;i++){
        for(int j=0;j<=dimensione-dimensione_sm;j++){
            if(isvalid(matrice, dimensione_sm, val, i, j)){
                counter++;
            }
        }
    }
    return counter;

}

int isvalid(int ** matrice,int dim,int val,int riga,int colonna){
    int somma=0;
    for(int i=riga;i<dim+riga;i++){
        for(int j=colonna;j<dim+colonna;j++){

            somma+=matrice[i][j];

        }
    }
    if(somma==val){
        return 1;
    }
    return 0;
}