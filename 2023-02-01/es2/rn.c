#include <stdio.h>
#include <stdlib.h>
#define R 10
#define C 10

typedef struct{
    int riga;
    int colonna;
    int minimo;
}minimorc_t;
int  minimo(minimorc_t * mimimi,int matrice[][C],int righe, int colonne);
int isminimoriga(int array[],int colonne,int elem);
int isminimocolonna(int matrice[][C],int righe,int colonna,int elemento);
int numrighe(FILE * fpin);
int numcolonne(FILE *fp);

void riempimatrice(FILE *fpin,int matrice[][C],int righe,int colonne);
int main (int argc,char * argv[]){
    if(argc<2){
        printf("Usage");
        return -1;
    }
    FILE *fp = fopen(argv[1],"r");
    if(fp == NULL){
        printf("Error");
        return -1;
    }
    
    
    
    int righe = numrighe(fp);
    int ** matrice = (int **)calloc(sizeof(int *),righe);

    int colonne = numcolonne(fp);
    for(int i=0;i<righe;i++){
        matrice[i]=(int *)calloc(sizeof(int),colonne);
    }
    riempimatrice(fp,matrice,righe,colonne);
        


    
    minimorc_t * minimi  = (minimorc_t *)malloc(sizeof(minimorc_t)*R);
    int elem=minimo(minimi,matrice,righe,colonne);
    
    for(int i=0;i<elem;i++){
        printf("Minimo:%d,riga:%d,colonna:%d\n",minimi[i].minimo,minimi[i].riga,minimi[i].colonna);
    }

    free(minimi);
    return 0;
}
int minimo(minimorc_t * minimi,int matrice[][C],int righe,int colonne){
    int counter=0;
    for(int i=0;i<righe;i++){
        for(int j=0;j<colonne;j++){
            if(isminimoriga(matrice[i],colonne,matrice[i][j])&&isminimocolonna(matrice,righe,j,matrice[i][j])){
                (minimi[counter]).minimo=matrice[i][j];
                (minimi[counter]).riga=i;
                (minimi[counter]).colonna=j;
                
                counter++;
            }
        }
    }
    return counter;
}
int numrighe(FILE *fp){
    int hold;
    fscanf(fp,"%d",&hold);
    return hold;
}
int numcolonne(FILE *fp){
    int hold;
    fscanf(fp,"%d",&hold);
    return hold;

}
int isminimoriga(int array[],int colonne,int elem){
    for(int i=0;i<colonne;i++){
        if(array[i]<elem){
            return 0;
        }
    }
    return 1;
}
int isminimocolonna(int matrice[][C],int righe,int colonna,int elemento){
    for(int i=0;i<righe;i++){
        if(matrice[i][colonna]<elemento){
            return 0;
        }
    }
    return 1;
}
void riempimatrice(FILE *fpin,int matrice[][C],int righe,int colonne){
    int hold;
    int flag=0;
    for(int i=0;i<righe&&flag==0;i++){
        for(int j=0;j<colonne&&flag==0;j++){
            if(fscanf(fpin,"%d",&hold)!=EOF){
                matrice [i][j]=hold;

            }
            else{
                flag =1;
            }
        }
    }
}