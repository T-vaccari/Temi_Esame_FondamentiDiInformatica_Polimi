#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del nodo della lista
typedef struct Nodo {
    int valore;
    struct Nodo* next;
} Nodo;

// Funzione per inserire un nuovo nodo in coda alla lista
void inserisciInCoda(Nodo** testa, int valore) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->valore = valore;
    nuovoNodo->next = NULL;

    if (*testa == NULL) {
        *testa = nuovoNodo;
    } else {
        Nodo* temp = *testa;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuovoNodo;
    }
}

// Funzione per rimuovere le ripetizioni dalla lista
void rimuoviRipetizioni(Nodo* testa) {
    if (testa == NULL) {
        return;  // Niente da fare se la lista è vuota
    }

    Nodo* temp = testa;

    while (temp != NULL) {
        Nodo* hold = temp->next;
        Nodo* last = temp;

        while (hold != NULL) {
            if (temp->valore == hold->valore) {
                last->next = hold->next;
                free(hold);
                hold = last->next;  // Aggiorniamo 'hold' dopo la rimozione
            } else {
                last = hold;
                hold = hold->next;
            }
        }

        temp = temp->next;
    }
}



// Funzione per stampare la lista
void stampaLista(Nodo* testa) {
    Nodo* corrente = testa;

    while (corrente != NULL) {
        printf("%d -> ", corrente->valore);
        corrente = corrente->next;
    }

    printf("NULL\n");
}

// Funzione principale
int main() {
    // Creazione della lista di esempio
    Nodo* lista = NULL;
    inserisciInCoda(&lista, 4);
    inserisciInCoda(&lista, 3);
    inserisciInCoda(&lista, 1);
    inserisciInCoda(&lista, 3);
    inserisciInCoda(&lista, 7);
    inserisciInCoda(&lista, 6);
    inserisciInCoda(&lista, 7);

    // Stampa della lista originale
    printf("Lista originale: ");
    stampaLista(lista);

    // Rimozione delle ripetizioni
    rimuoviRipetizioni(lista);

    // Stampa della lista dopo la rimozione delle ripetizioni
    printf("Lista senza ripetizioni: ");
    stampaLista(lista);

    return 0;
}
