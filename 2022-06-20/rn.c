#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int val;
    struct nodo* next;
} Nodo;

void modificaLista(Nodo* testa) {
    testa = testa->next;
    if(testa->next->next!=NULL){
        modificaLista(testa);

    }
    testa->next->val=testa->next->val+testa->val;
}

// Funzione per stampare la lista
void stampaLista(Nodo* testa) {
    while (testa != NULL) {
        printf("%d -> ", testa->val);
        testa = testa->next;
    }
    printf("NULL\n");
}

// Funzione per liberare la memoria occupata dalla lista
void liberaLista(Nodo* testa) {
    while (testa != NULL) {
        Nodo* temp = testa;
        testa = testa->next;
        free(temp);
    }
}

int main() {
    // Esempio di utilizzo della funzione
    Nodo* lista = (Nodo*)malloc(sizeof(Nodo));
    lista->val = 1;
    lista->next = (Nodo*)malloc(sizeof(Nodo));
    lista->next->val = 2;
    lista->next->next = (Nodo*)malloc(sizeof(Nodo));
    lista->next->next->val = 10;
    lista->next->next->next = (Nodo*)malloc(sizeof(Nodo));
    lista->next->next->next->val = 3;
    lista->next->next->next->next = (Nodo*)malloc(sizeof(Nodo));
    lista->next->next->next->next->val = 6;
    lista->next->next->next->next->next = NULL;

    printf("Lista originale:\n");
    stampaLista(lista);

    modificaLista(lista);

    printf("Lista modificata:\n");
    stampaLista(lista);

    // Liberare la memoria allocata per la lista
    liberaLista(lista);

    return 0;
}
