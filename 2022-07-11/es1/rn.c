#include <stdio.h>

int maxarray(int *,int,int);
int main(){


    int array[] ={1,9,3,4,5,6};

    printf("%d",maxarray(array,6,0));



    return 0;
}



int maxarray(int* a,int len,int ind){
    if(ind>=len){
        return a[0];
    }

    return (a[0]>maxarray(a+1,len,ind+1))?a[0]:maxarray(a+1,len,ind+1);
   



}