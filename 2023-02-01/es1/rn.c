#include <stdio.h>
#include <stdlib.h>

void ordina (int array1 [],int array2[],int array3[],int len1,int len2,int len3);
typedef struct n_t{
    int ele;
    struct n_t * next;

}nodo_t;

int main (){
    //nodo_t * nodo;
    
    int array1[3]={0,2,4};
    int array2[3]={1,3,5};
    int array3[6]={};
    ordina(array1,array2,array3,2,2,5);
    for(int i=0;i<6;i++){
        printf("%d",array3[i]);
    }
    



    return 0;
}

// 0| 2| 4|len1=3
// 1| 3| *5*|len2=3
//  |  |  |  |  |  5|       len3=5

// 0| 2| *4*|len1=2
// 1| 3| *5*|len2=2
//  |  |  |  |  4|  5|       len3=4

// 0| 2| *4*|len1=2
// 1| *3*| *5*|len2=1
//  |  |  | 3 |  4|  5|       len3=4

// 0| 2| *4*|len1=2
// 1| *3*| *5*|len2=1
//  |  |  | 3 |  4|  5|       len3=4

// 0|*2*| *4*|len1=2
// 1| *3*| *5*|len2=1
//  |  |  2| 3 |  4|  5|       len3=3

// 0|*2*| *4*|len1=2
// *1*| *3*| *5*|len2=1
//  |  1|  2| 3 |  4|  5|       len3=2








void ordina(int a1[], int a2[], int a3[], int len1, int len2,int len3) {
    if(len1 <0 && len2 <0 ){
        return ;
    }

    if(len1>=0 && len2>=0){
        if(a1[len1]>a2[len2]){
            a3[len3]=a1[len1];
            len1--;
            len3--;
            ordina(a1,a2,a3,len1,len2,len3);
        }else{
            a3[len3]=a2[len2];
            len3--;
            len2--;
            ordina(a1,a2,a3,len1,len2,len3);
        }
    }else if(len1<0){
        a3[len3]=a2[len2];
        len2--;
        len3--;
        ordina(a1,a2,a3,len1,len2,len3);
    }else{
        a3[len3]=a1[len1];
        len1--;
        len3--;
        ordina(a1,a2,a3,len1,len2,len3);

    }
    
    
}
