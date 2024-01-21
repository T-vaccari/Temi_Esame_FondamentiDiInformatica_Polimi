#include <stdio.h>

typedef struct mosse{
    int riga;
    int colonna;
}mosse_t;
void checkpercorso (int matrice[][5],mosse_t * mosse, int k);
int main(){
    int matrice [5][5]={
       { 0, 1,0 ,1 ,1},
       {0 ,0 ,1,1 ,0 },
       {1 ,0 ,0 ,0 ,0},
       {1 ,1 ,0 ,1 ,0},
       {1 ,1 ,1 ,1 ,0},
       

    };
    mosse_t mosse [5]={{1, 0},  {0,  1},  {1,  0},  {0,  3},  {-1, 0}};
    checkpercorso(matrice,mosse,5);
    
}
void checkpercorso (int matrice[][5],mosse_t * mosse, int k){

    int riga=0;
    int colonna =0;
    int counter =0;
    int sentinel = 0;
    while (counter<k && sentinel == 0 ){
        riga = riga+ mosse[counter].riga;
        colonna=colonna+mosse[counter].colonna;

        if(matrice[riga][colonna]==1){
            sentinel = 1;
            printf("Il percorso si è interrotto in %d,%d",riga,colonna);
        }



        counter++;
    }
    if(sentinel == 0){
        printf("Il percorso è andato a buon fine");
    }
        
}