#include <stdio.h>
#define MAX 100

void stampa(char * stringa);
void stampa2(char * stringa);
int main(){

    char stringa[MAX]={"ciao."};
    stampa(stringa);
    puts("");
    stampa2(stringa);

    return 0;
}
void stampa(char * stringa){

    if(stringa[1]!= '.'){
        stampa(&stringa[1]);
    }
    printf("%c",stringa[0]);
    



}
void stampa2(char * stringa){
    int i=0;
    for(i=0;stringa[i]!='.';i++);
    for(int k=i-1;k>=0;k--){
        printf("%c",stringa[k]);
    }
    


}