#include <stdio.h>     // Libreria standard di input/output
#include <stdlib.h>    // Libreria standard di utilità generale
#include <string.h>    // Libreria standard per la manipolazione di stringhe
#include <math.h>      // Libreria standard per funzioni matematiche
#include <ctype.h>     // Libreria standard per la manipolazione di caratteri
#include <time.h>      // Libreria standard per funzionalità legate al tempo
#include <stdbool.h>   // Libreria standard per il tipo di dato booleano
#include <stdint.h>    // Libreria standard per tipi di dati interi di larghezza fissa
#include <stddef.h>    // Libreria standard per la definizione di tipi e macro
#define N 100

typedef struct{
    int riga;
    int colonna;
    int valore;
}nondominante_t;

void legginfo(FILE * filein,int * righePtr, int * colonnePtr,int * valoredominantePtr);
int leggivalori(FILE *filein,nondominante_t nondominanti[]);
void riempimatrice(int matrice [][N],int righe, int colonne, nondominante_t nondominanti[],int numeronondominanti,int posizioni[][N],int dominante);
void stampamatrice(FILE *fileout,int matrice[][N],int righe,int colonne);
int main (int argc, char *argv[]){

    if(argc<3){
        printf("Usage : es4 filein fileout");
        return -1;
    }

    FILE *fpin;
    FILE *fpout;
    nondominante_t nondominanti [N*N];
    int posizioni[N][N]={};
    fpin=fopen(argv[1],"r");
    fpout=fopen(argv[2],"w");

    if(fpin == NULL || fpout == NULL){
        printf("File's couldn't be opened");
        return -1;
    }

    int righe, colonne, valoredominante;
    legginfo(fpin,&righe,&colonne,&valoredominante);
    
    if(colonne >= N || righe >=N){
        printf("Too many rows or cols");
        return -1;
    }

    int matrice [righe][colonne];
    for(int i=0;i<righe;i++){
        for(int j=0;j<colonne;j++){
            matrice[i][j]=0;
        }
    }
    
    int numeronondominanti = leggivalori(fpin,nondominanti);
    riempimatrice(matrice,righe,colonne,nondominanti,numeronondominanti,posizioni,valoredominante);
    stampamatrice(fpout,matrice,righe,colonne);
    
    
    





    
    







    


    return 0;
}

void legginfo(FILE * filein,int * righePtr, int * colonnePtr,int * valoredominantePtr){

    fscanf(filein,"%d",righePtr);
    fscanf(filein,"%d",colonnePtr);
    fscanf(filein,"%d",valoredominantePtr);


}
int leggivalori(FILE *filein,nondominante_t nondominanti[]){

    int riga;
    int counter=0;
    while( fscanf(filein,"%d",&riga)!=EOF){
        nondominanti[counter].riga=riga;
        fscanf(filein,"%d",&nondominanti[counter].colonna);
        fscanf(filein,"%d",&nondominanti[counter].valore);
        counter++;
    }
    return counter;

}


void riempimatrice(int matrice [][N],int righe, int colonne, nondominante_t nondominanti[],int numeronondominanti,int posizioni[][N],int dominante){

    for(int i=0;i<numeronondominanti+1;i++){
        matrice[nondominanti[i].riga][nondominanti[i].colonna]=nondominanti[i].valore;
        posizioni[nondominanti[i].riga][nondominanti[i].colonna]=-1;
        
    }
    
    for(int i=0;i<righe;i++){
        for(int j=0;j<colonne;j++){
            if(posizioni[i][j]==0){
                matrice[i][j]=dominante;
            }
        }
    }
    

    
}
void stampamatrice(FILE *fileout,int matrice[][N],int righe,int colonne){

    for(int i=0;i<righe;i++){
        for(int j=0;j<colonne;j++){
            fprintf(fileout,"%d ",matrice[i][j]);
            
        }
        fprintf(fileout,"\n");
    }


}