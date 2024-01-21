#include <stdio.h>     // Libreria standard di input/output
#include <stdlib.h>    // Libreria standard di utilità generale
#include <string.h>    // Libreria standard per la manipolazione di stringhe
#include <math.h>      // Libreria standard per funzioni matematiche
#include <ctype.h>     // Libreria standard per la manipolazione di caratteri
#include <time.h>      // Libreria standard per funzionalità legate al tempo
#include <stdbool.h>   // Libreria standard per il tipo di dato booleano
#include <stdint.h>    // Libreria standard per tipi di dati interi di larghezza fissa
#include <stddef.h>    // Libreria standard per la definizione di tipi e macro
#define MAX 20
#define MAXPAROLE 200
typedef struct{
    char parola[MAX];
}parole_t;

void stringtoword (parole_t * parolePtr,FILE * textpr, int * numparolePtr);
void controlloparole(parole_t *parolePtr,FILE *nonvalidoptr,int * numparolePtr);
int main (int argc,char *argv[]){

    if(argc<3){
        printf("usage rn filein fileout");
        return -1;

    }
    FILE *textptr;
    textptr=fopen(argv[1],"r");

    FILE *nonvalidoptr;
    nonvalidoptr=fopen(argv[2],"w");

    if(nonvalidoptr==NULL || textptr == NULL){
        printf("Impossibile aprire i file");
    }

    parole_t parole[MAXPAROLE];
    int numparole=0;
    int * numparolePtr = &numparole;


    stringtoword(parole,textptr,numparolePtr);
    controlloparole(parole,nonvalidoptr, numparolePtr);


    
    







    


    return 0;
}

void stringtoword(parole_t * parolePtr,FILE * textpr,int *numparolePtr){
    int counter=0;
    while(fscanf(textpr,"%s",parolePtr[counter].parola) != EOF && counter <MAXPAROLE){
        counter++;
        (*numparolePtr)++;
    }





}
void controlloparole(parole_t *parolePtr,FILE *nonvalidoptr,int * numparolePtr){
    int counter=0;
    int array[MAXPAROLE]={};
    while(counter < *numparolePtr){
        int flag=0;
        for(int i=0;flag == 0 && i<strlen(parolePtr[counter].parola);i++){
            if(parolePtr[counter].parola[i] != 'a' && parolePtr[counter].parola[i] != 'b' && parolePtr[counter].parola[i] != 'c'){
                array[counter]=-1;
                fprintf(nonvalidoptr,"%s\n",parolePtr[counter].parola);
                flag=-1;
                //printf("Errore");
            }
        }
        counter++;
    }
    counter=0;
    while(counter< *numparolePtr){
        if(array[counter]!= -1){
            int numerob =0;
            int flag=0;
            for(int i=0;flag == 0 && i<strlen(parolePtr[counter].parola);i++){
                
                if(parolePtr[counter].parola[i]=='b'){
                    numerob++;
                }
                if(parolePtr[counter].parola[i] != 'b'&& numerob!=0){
                    if(numerob%2 !=0 ){
                        flag=-1;
                        fprintf(nonvalidoptr,"%s",parolePtr[counter].parola);
                        array[counter]=-1;
                    }
                }


            }



        }
        counter++;
    }

    counter=0;
    while(counter<*numparolePtr){


        if(array[counter]==0){
            
            int presenzac=0;
            for(int i=0; i<strlen(parolePtr[counter].parola);i++){
                
                if(parolePtr[counter].parola[i]== 'c'){
                    presenzac++;
                }

            }
            if(presenzac>2){
                array[counter]=-1;
                fprintf(nonvalidoptr,"%s\n",parolePtr[counter].parola);

            }




        }



        counter++;
    }




}