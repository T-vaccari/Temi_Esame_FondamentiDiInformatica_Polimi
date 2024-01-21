#include <stdio.h>
#include <stdlib.h>

int check(int **matrice, int riga, int colonna, int val) {
    if (riga >= 0) {
        riga--;
        if (!check(&matrice[riga], riga, colonna, val)) {
            return 0;
        }
        return 1;
    }

    int somma = 0;
    for (int i = 0; i < colonna; i++) {
        somma += matrice[0][i];
    }

    return (somma == val);
}

int main() {
    // Creazione di una matrice di esempio 3x3
    int righe = 3;
    int colonne = 3;
    int **matrice = (int **)malloc(sizeof(int *) * righe);
    for (int i = 0; i < righe; i++) {
        matrice[i] = (int *)malloc(sizeof(int) * colonne);
        for (int j = 0; j < colonne; j++) {
            if(i==0){
                matrice[i][j] = 1;  // Valori di esempio
            }else{
                matrice[i][j] = 2;
            }
            
        }
    }

    // Stampa della matrice
    printf("Matrice di esempio:\n");
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }

    // Verifica se la somma di ogni riga è uguale a 10
    int val = 3;
    if (check(matrice, righe, colonne, val)) {
        printf("La somma di ogni riga è uguale a %d.\n", val);
    } else {
        printf("La somma di ogni riga non è uguale a %d.\n", val);
    }

    // Deallocazione della memoria
    for (int i = 0; i < righe; i++) {
        free(matrice[i]);
    }
    free(matrice);

    return 0;
}
