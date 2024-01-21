#include <stdio.h>     // Libreria standard di input/output
#include <stdlib.h>    // Libreria standard di utilità generale
#include <string.h>    // Libreria standard per la manipolazione di stringhe
#include <math.h>      // Libreria standard per funzioni matematiche
#include <ctype.h>     // Libreria standard per la manipolazione di caratteri
#include <time.h>      // Libreria standard per funzionalità legate al tempo
#include <stdbool.h>   // Libreria standard per il tipo di dato booleano
#include <stdint.h>    // Libreria standard per tipi di dati interi di larghezza fissa
#include <stddef.h>    // Libreria standard per la definizione di tipi e macro
#define M 5
#define N 5
#define MOSSE 5

typedef struct{
    int i;
    int j;
}mosse_t;

void checkpercorso(int matrice [][N],mosse_t mosse[]);
int main (){
    mosse_t mosse [MOSSE]={{1,0},{0,2},{2,0},{0,3},{-1,0}};
    int percorsi [M][N]={
        {0,1,0,1,1},
        {0,0,1,1,0},
        {1,0,0,0,0},
        {1,1,0,1,0},
        {1,1,1,1,0}

    };

    



    checkpercorso(percorsi,mosse);


    
    







    


    return 0;
}
void checkpercorso(int matrice [][N],mosse_t mosse[]){

    int i=0,j=0;
    int flag=0;
    int k;
    for( k=0;flag==0 && k<3;k++){
        i=mosse[k].i+i;
        j=mosse[k].j+j;

        if(matrice[i][j]==1 || i<0 || j<0 || j>4 || i>4){
            flag=1;
        }
    }
    if(flag==1){
        printf("Percorso non riuscito ultima posizione valida : (%d,%d)",i-mosse[k].i,j-mosse[k].j);
    }
    else{
        printf("Percorso riuscito");
    }


}