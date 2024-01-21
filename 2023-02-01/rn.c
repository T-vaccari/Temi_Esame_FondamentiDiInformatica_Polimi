#include <stdlib.h>
#include <stdio.h>


int max (char * s){
    int val;
    if(s[2]!='\0'){
        val = max(s+1);
    }else{
        return (int) *(s+1)-'0';
    }
    if(((int) *s-'0')>val){
        return (int) *s-'0';

    }else{
        return val;
    }
}

int main(){
    char s[]={"123456789"};
    printf("%d",max(s));
    
}