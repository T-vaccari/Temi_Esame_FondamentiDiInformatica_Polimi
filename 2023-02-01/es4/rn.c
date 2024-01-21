#include <stdio.h>
#include <stdlib.h>

// Definizione del tipo di dato per i nodi della lista
typedef struct Nodo {
    int valore;
    struct Nodo* next;
} Nodo;

// Prototipo della funzione per la rotazione a destra della lista
Nodo* rotazioneDestra(Nodo* lista, int k);

// Funzione principale per testare la rotazione a destra
int main() {
    // Creazione di una lista di esempio: 6 → 8 → 3 → 1 → 10
    Nodo* lista = malloc(sizeof(Nodo));
    lista->valore = 6;
    lista->next = malloc(sizeof(Nodo));
    lista->next->valore = 8;
    lista->next->next = malloc(sizeof(Nodo));
    lista->next->next->valore = 3;
    lista->next->next->next = malloc(sizeof(Nodo));
    lista->next->next->next->valore = 1;
    lista->next->next->next->next = malloc(sizeof(Nodo));
    lista->next->next->next->next->valore = 10;
    lista->next->next->next->next->next = NULL;

    // Stampa la lista originale
    printf("Lista originale: ");
    Nodo* temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->valore);
        temp = temp->next;
    }
    printf("NULL\n");

    // Esegui la rotazione a destra di k posizioni
    int k = 3;
    Nodo* nuovaLista = rotazioneDestra(lista, k);

    // Stampa la lista dopo la rotazione
    printf("Lista dopo la rotazione a destra di %d posizioni: ", k);
    temp = nuovaLista;
    while (temp != NULL) {
        printf("%d -> ", temp->valore);
        temp = temp->next;
    }
    printf("NULL\n");

    // Libera la memoria allocata per le liste
    free(lista);
    free(nuovaLista);

    return 0;
}

// Definizione della funzione per la rotazione a destra della lista
Nodo* rotazioneDestra(Nodo* testa, int k) {

    Nodo * temp = testa;
    int counter = 0;
    Nodo * last = testa;

    while (temp != NULL){
        if(counter>k){
            last=last->next;
        }
        counter++;
        temp = temp->next;
    }
    if(k>=counter+1){
        return testa;
    }
    temp = testa;
    testa = last->next;
    Nodo * hold = last;
    while (hold->next!= NULL){
        hold = hold->next;
    }
    hold->next=temp;
    last->next=NULL;
    return testa;
}


