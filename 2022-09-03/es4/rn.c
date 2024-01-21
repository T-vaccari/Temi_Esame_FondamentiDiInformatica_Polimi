#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
int isvalid(char stringa[],char special[],int min,int max);
int main (){


    char caratterispeciali[LEN];
    char password[LEN];



}

int isvalid(char stringa[],char special[],int min,int max){

    int len = strlen(stringa);

    if(len<min){
        return -2;
    }
    if(len > max){
        return -1;
    }

    int flag=0;
    for(int i=0;i<strlen(stringa)&&flag==0;i++){
        for(int j=0;j<strlen(special)&&flag==0;j++){
            if(stringa[i]==special[j]){
                flag=1;
            }
        }
    }
    if(flag=1){
        return 1;
    }else{
        return 0;
    }


}