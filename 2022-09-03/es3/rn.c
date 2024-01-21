#include <stdio.h>

#define N 10

//int checkarray(int riga[], int colonna[][N], int righe, int colonne);
int checkarray(int riga[], int colonna[][N], int righe, int colonne, int colonnA);
int compare(int matrice[][N], int righe, int colonne) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (checkarray(matrice[i], matrice, righe, colonne, j) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int checkarray(int riga[], int colonna[][N], int righe, int colonne, int colonnA) {
    for (int i = 0; i < righe; i++) {
        if (colonna[i][colonnA] != riga[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Esempio di utilizzo
    int matrice[][N] = {
        {1, 2, 3},
        {2, 5, 6},
        {3, 8, 9}
    };

    int risultato = compare(matrice, 3, N);
    
    if (risultato == 1) {
        printf("La colonna è presente in almeno una riga della matrice.\n");
    } else {
        printf("La colonna non è presente in nessuna riga della matrice.\n");
    }

    return 0;
}