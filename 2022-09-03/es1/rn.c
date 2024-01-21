#include <stdio.h>

int pari(int array[],int lastnumber);

int main (){

    int array [10]={2,2,3,4,5,6,7,8,9,36};
    printf("%d",pari(array,10));
    

}

int pari(int array[],int len){
    //1-2-3-4-5
    //1+1+1+1+1
    if(len-1<0){
        return 0;

    }

    if(array[len-1]%2==0){
        return 1+pari(array,len-1);
    }else{
        return 0+pari(array,len-1);
    }
}