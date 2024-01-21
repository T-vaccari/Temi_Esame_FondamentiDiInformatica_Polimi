#include <stdio.h>     // Libreria standard di input/output
#include <stdlib.h>    // Libreria standard di utilità generale
#include <string.h>    // Libreria standard per la manipolazione di stringhe
#include <math.h>      // Libreria standard per funzioni matematiche
#include <ctype.h>     // Libreria standard per la manipolazione di caratteri
#include <time.h>      // Libreria standard per funzionalità legate al tempo
#include <stdbool.h>   // Libreria standard per il tipo di dato booleano
#include <stdint.h>    // Libreria standard per tipi di dati interi di larghezza fissa
#include <stddef.h>    // Libreria standard per la definizione di tipi e macro
#include <limits.h>
#define N 10


int leggidimensioni (FILE *fpin);
void riempimatrice (FILE *fpin, int matrice[][N],int colonne);
void percorso(int mappa[][N],int dimensioni,int posizioni[][N], FILE *fpout,int x,int y ,int mosse,int quotamax);
void cercaminimo(int mappa[][N],int x, int y,int *xmin,int *ymin,int *minimo,int dimensioni);
int main (int argc,char * argv[]){
    int mappa[N][N];
    int posizioni [N][N]={};
    
    if(argc<2){
        printf("usage in.txt out.txt");
        return -1;
    }

    FILE * fpin;

    fpin = fopen(argv[1],"r");

    if(fpin==NULL){
        printf("could not open filein");
        return -1;
    }

    FILE *fpout;

    fpout= fopen(argv[2],"w");

    if(fpout == NULL){
        printf("could not open fileout");
        return -1;
    }

    int quotamax;
    int mosse;
    printf("Inserisci la quota massima: ");
    scanf("%d",&quotamax);
    
    printf("Inserisci il numero di mosse: ");
    scanf("%d",&mosse);

    int dimensioni = leggidimensioni(fpin); //Leggo le dimensioni
    riempimatrice(fpin,mappa,dimensioni); //Riempio la matrice

    printf("Inserisci x:");
    int x;
    scanf("%d",&x);
    printf("Inserisci y:");
    int y;
    scanf("%d",&y);


    
    
    
    percorso(mappa,dimensioni,posizioni ,fpout,x,y,mosse,quotamax);
    




    
    







    


    return 0;
}

int leggidimensioni(FILE * fpin){

    int dimensioni;

    fscanf(fpin,"%d",&dimensioni);

    return dimensioni;


}
void riempimatrice ( FILE *fpin, int matrice[][N],int colonne){
    int hold;
    int i=0;
    int j=0;
    
    while((fscanf(fpin,"%d",&hold))!= EOF && i<colonne ){

        matrice[i][j]=hold;

        j++;
        if(j == colonne){
            i++;
            j=0;
        }


    }



}
void percorso(int mappa[][N],int dimensioni,int posizioni[][N], FILE *fpout,int x,int y,int mosse,int quotamax){

    int flag=0;
    int xmin;
    int ymin;
    int minimo;

    for(int i=0;i<=mosse && flag ==0;i++){

        cercaminimo(mappa,x,y,&xmin,&ymin,&minimo,dimensioni);
        if(minimo<quotamax){

            if(posizioni[xmin][ymin]!=1){
                posizioni[xmin][ymin]=1;
                mappa[x][y]=INT_MAX;
                fprintf(fpout,"|%d,%d|\n",xmin,ymin);
                x=xmin;
                y=ymin;

            }
            else{
                flag=1;
            }
        }
        else{
            flag=1;
        }
        

        









    }




}
void cercaminimo(int mappa[][N],int x, int y,int *xmin,int *ymin,int *min,int dimensioni){
    int minimo = INT_MAX;
    for(int i = x-1 ; i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            //Sistemare le condizioni di ricerca
            if(i>=0 && j>=0 && j<dimensioni && i<dimensioni && (i != x ||  j!=y)){
                
                if(mappa[i][j]<=minimo){
                    *xmin = i;
                    *ymin =j;
                    minimo=mappa[i][j];
                    *min=minimo;

                
                }
            }
        }
    }




}