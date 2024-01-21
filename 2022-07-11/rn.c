#include <stdio.h>

int somma(int * a,int size){
    size--;
    if(size==0){
        return a[0];
    }
    return a[0]+somma(a+1,size);
}
int cfr(int n){
    if(n==0){
        return 0;
    }
    return ((n%10)>cfr(n/10)) ? n%10 : cfr(n/10);
}
void inv(int n){
    printf("%d",n%10);
    if(n/10!=0){
        inv(n/10);
    }
    
}
int main(){

    int a[4]={1,2,3,4};

    printf("%d    ",somma(a,4));
    printf("%d",cfr(123456789));
    puts("");
    inv(123456789);





}