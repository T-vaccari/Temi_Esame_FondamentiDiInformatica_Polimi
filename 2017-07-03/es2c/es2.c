#include <stdio.h>     // Libreria standard di input/output
#include <stdlib.h>    // Libreria standard di utilità generale
#include <string.h>    // Libreria standard per la manipolazione di stringhe
#include <math.h>      // Libreria standard per funzioni matematiche
#include <ctype.h>     // Libreria standard per la manipolazione di caratteri
#include <time.h>      // Libreria standard per funzionalità legate al tempo
#include <stdbool.h>   // Libreria standard per il tipo di dato booleano
#include <stdint.h>    // Libreria standard per tipi di dati interi di larghezza fissa
#include <stddef.h>    // Libreria standard per la definizione di tipi e macro
#define N 3

void sommadiagonali(int matrice[][3],int colonne);

int main (){
    int matrice[3][3]={
        {1,2,1},
        {4,-1,6},
        {-1,8,1}

    };
    



    sommadiagonali(matrice,3);


    
    







    


    return 0;
}

void sommadiagonali(int matrice[][N],int colonne){
    colonne--;
    int indice1c=colonne;
    int indice1r=2-colonne;
    int indice2c=2-colonne;
    int indice2r = 2-colonne;
    
    if(colonne<0){
        if(matrice[0][0]==matrice[0][N-1]){
            printf("si");
            
            
        }
        else{
            printf("no");
            
        }
        return;
        
    }

    matrice[0][0]=matrice[0][0]+matrice[indice2r][indice2c];
    matrice[0][2]=matrice[0][2]+matrice[indice1r][indice1c];
    
    sommadiagonali(matrice ,indice1c);

    
    

}