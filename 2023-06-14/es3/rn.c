#include <stdio.h>
#define N 3
#define M 4



int check (int matrice [][M],int righe,int colonne);
int indicemax ( int array[],int len);
int main(){
    int matrice[N][M]={
        {1, 3, 8, 2 },
        {10 ,5 ,12 ,3 },
        {3 ,2 ,12, 16} 
    };
    printf("%d",check(matrice,N,M));





}

int check(int matrice [][M], int righe, int colonne){
    int indiceprecedente=indicemax(matrice[0],colonne);
    //printf("%d",indiceprecedente);
    for(int i=1;i<righe;i++){

        if(indicemax(matrice[i],colonne)<=indiceprecedente){
            return 0;
        }
        indiceprecedente=indicemax(matrice[i],colonne);
        

    }

    
    return 1;


}
int indicemax ( int array[],int len){

    int max= array[0];
    int indice=0;
    for(int i=0;i<len;i++){
        if(array[i]>max){
            max = array[i];
            indice = i;
        }
    }
    printf("%d",indice);
    return indice;



}