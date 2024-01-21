#include <stdio.h>


int somma(int m[][3],int r,int c,int val){
    c--;
    if(c==0){
        int somma = 0;
        for(int i=0;i<r;i++){
            somma+=m[i][0];
        }
        if(somma/r == val){
            return 1;
        }else{
            return 0;
        }

    }
    for(int i =0;i<r;i++){
        m[i][c-1]=m[i][c-1]+m[i][c];

    }
    return somma(m,r,c,val);
}



int main (){

    int a[3][3]={
        {1,2,3},
        {1,2,3},
        {1,2,3},
    };



    printf("%d",somma(a,3,3,6));





}