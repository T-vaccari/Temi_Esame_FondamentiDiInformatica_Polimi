#include <stdio.h>     // Libreria standard di input/output
#include <stdlib.h>    // Libreria standard di utilità generale
#include <string.h>    // Libreria standard per la manipolazione di stringhe
#include <math.h>      // Libreria standard per funzioni matematiche
#include <ctype.h>     // Libreria standard per la manipolazione di caratteri
#include <time.h>      // Libreria standard per funzionalità legate al tempo
#include <stdbool.h>   // Libreria standard per il tipo di dato booleano
#include <stdint.h>    // Libreria standard per tipi di dati interi di larghezza fissa
#include <stddef.h>    // Libreria standard per la definizione di tipi e macro
#define MAX 100



int cercamax(int numero);

int main() {
    int numero;
    scanf("%d",&numero);
    printf("%d",cercamax(numero));
}

int cercamax(int numero){

    if (numero < 10) {
        return numero;
    }

    // Chiamata ricorsiva con il resto della divisione per ottenere l'ultima cifra
    int ultimaCifra = cercamax(numero / 10);

    // Restituisci la cifra più grande tra l'ultima cifra e la cifra più alta del numero senza l'ultima cifra
    return (numero % 10 > ultimaCifra) ? (numero % 10) : ultimaCifra;
}

    

    

    
    
    
    










