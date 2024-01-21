#include <stdio.h>


int mystrcmp1(char * stringa1, char * stringa2);
int main (){

    printf("%d",mystrcmp1("a","aa"));


    return 0;
}


int mystrcmp1(char * stringa1, char * stringa2){  //Strcmp che ritorn 0 se le stringhe sono uguali un valore < 0 se s1 precede alfabeticamente s2

    if(*stringa1 == '\0' && *stringa2 == '\0'){



        return  0;
    }

    if(*stringa1 == *stringa2 ){
        return mystrcmp1 (stringa1+1,stringa2+1);
    }
    if(*stringa1<*stringa2){
        return -1;
    }else{
        return 1;
    }







}