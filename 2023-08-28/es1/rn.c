#include <stdio.h>     // Libreria standard di input/output
#include <stdlib.h>    // Libreria standard di utilità generale
#include <string.h>    // Libreria standard per la manipolazione di stringhe
#include <math.h>      // Libreria standard per funzioni matematiche
#include <ctype.h>     // Libreria standard per la manipolazione di caratteri
#include <time.h>      // Libreria standard per funzionalità legate al tempo
#include <stdbool.h>   // Libreria standard per il tipo di dato booleano
#include <stdint.h>    // Libreria standard per tipi di dati interi di larghezza fissa
#include <stddef.h>    // Libreria standard per la definizione di tipi e macro


//Funzione ricorsiva di strcmp

//
int mystrcmp(char string1[],char string2[]);
int main (){

    




    printf("%d",mystrcmp("ciao","ciaoe"));

    
    







    


    return 0;
}


int mystrcmp(char string1[],char string2[]){

    if(string1[0]== '\n' && string2[0]== '\n'){

        return 0;
        

    }else if( string1[0] == string2[0]){

        return mystrcmp(&string1[1],&string2[1]);


    }else if(string1[0]<string2[0]){

        return -1;
    }else {
        return 1;
    }

    




}