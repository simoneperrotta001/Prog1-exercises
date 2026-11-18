/*
 * ============================================================
 *              ESERCIZIO - MATRICI E PUNTATORI IN C
 * ============================================================
 *
 * Scrivere un programma C che acquisisca da tastiera una
 * matrice di numeri interi di dimensione massima 10 x 10.
 *
 * Realizzare le seguenti funzioni:
 *
 * 1. leggi_matrice():
 *    Acquisisce gli elementi della matrice.
 *
 * 2. visualizza_matrice():
 *    Visualizza la matrice per righe e colonne.
 *
 * 3. somma_matrice_standard():
 *    Calcola la somma utilizzando a[i][j].
 *
 * 4. somma_matrice_puntatori():
 *    Calcola la somma utilizzando un doppio puntatore
 *    e la notazione *(*(a + i) + j).
 *
 * Nel main costruire un vettore di puntatori alle righe
 * della matrice e utilizzarlo per chiamare la quarta funzione.
 *
 * Visualizzare i risultati delle due somme.
 * ============================================================
 */

#include <stdio.h>                                       // Libreria per input e output

#define MAX 10                                           // Dimensione massima della matrice


// Prototipi delle funzioni
void leggi_matrice(int a[][MAX], int righe, int colonne);          // Lettura della matrice
void visualizza_matrice(int a[][MAX], int righe, int colonne);     // Visualizzazione della matrice
int somma_matrice_standard(int a[][MAX], int righe, int colonne);  // Somma con notazione standard
int somma_matrice_puntatori(int **a, int righe, int colonne);      // Somma con doppio puntatore


int main() {                                           // Inizio del programma
    int a[MAX][MAX];                                   // Matrice di 10 x 10 interi
    int *puntatori_righe[MAX];                         // Vettore di puntatori a int
    int righe, colonne;                                // Dimensioni effettive della matrice
    int somma1, somma2;                                // Risultati delle due somme

    do {                                               // Controllo del numero di righe
        printf("Inserire il numero di righe (1-10): ");
        scanf("%d", &righe);
    } while (righe < 1 || righe > MAX);                 // Ripete se le righe non sono valide

    do {                                               // Controllo del numero di colonne
        printf("Inserire il numero di colonne (1-10): ");
        scanf("%d", &colonne);
    } while (colonne < 1 || colonne > MAX);             // Ripete se le colonne non sono valide

    leggi_matrice(a, righe, colonne);                   // Acquisisce gli elementi della matrice

    printf("\nLa matrice e':\n");                       // Messaggio iniziale
    visualizza_matrice(a, righe, colonne);              // Visualizza la matrice
    printf("\n");                                      // Riga vuota

    // 1. Somma con notazione standard
    somma1 = somma_matrice_standard(a, righe, colonne); // Passa la matrice tradizionale

    printf("\nSomma con notazione standard: %d\n", somma1);

    // Preparazione dei puntatori alle righe
    for (int i = 0; i < righe; i++) {                   // Scorre tutte le righe
        puntatori_righe[i] = a[i];                     // Memorizza l'indirizzo del primo elemento della riga i
    }                                                  // Fine del ciclo

    // 2. Somma con doppio puntatore
    somma2 = somma_matrice_puntatori(
        puntatori_righe, righe, colonne
    );                                                 // Passa il vettore di puntatori alle righe

    printf("\nSomma con doppio puntatore: %d\n", somma2);
    printf("\n");

    return 0;                                          // Termine del programma
}


// ============================================================
// FUNZIONE 1 - ACQUISIZIONE DELLA MATRICE
// ============================================================

void leggi_matrice(int a[][MAX], int righe, int colonne) { // Riceve la matrice
    for (int i = 0; i < righe; i++) {                      // Scorre le righe
        for (int j = 0; j < colonne; j++) {                // Scorre le colonne
            printf("Inserisci elemento [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);                        // Memorizza il valore nella cella
        }                                                 // Fine ciclo colonne
    }                                                     // Fine ciclo righe
}


// ============================================================
// FUNZIONE 2 - VISUALIZZAZIONE DELLA MATRICE
// ============================================================

void visualizza_matrice(int a[][MAX], int righe, int colonne) { // Riceve la matrice
    for (int i = 0; i < righe; i++) {                           // Scorre le righe
        for (int j = 0; j < colonne; j++) {                     // Scorre le colonne
            printf("%d\t", a[i][j]);                           // Stampa l'elemento
        }                                                      // Fine ciclo colonne
        printf("\n");                                          // Passa alla riga successiva
    }                                                          // Fine ciclo righe
}


// ============================================================
// FUNZIONE 3 - SOMMA CON NOTAZIONE STANDARD
// ============================================================

int somma_matrice_standard(int a[][MAX], int righe, int colonne) { // Riceve la matrice
    int somma = 0;                                                // Accumulatore inizializzato

    for (int i = 0; i < righe; i++) {                              // Scorre le righe
        for (int j = 0; j < colonne; j++) {                        // Scorre le colonne
            somma = somma + a[i][j];                              // Somma l'elemento corrente
        }                                                         // Fine ciclo colonne
    }                                                             // Fine ciclo righe

    return somma;                                                 // Restituisce la somma
}


// ============================================================
// FUNZIONE 4 - SOMMA CON DOPPIO PUNTATORE
// ============================================================

int somma_matrice_puntatori(int **a, int righe, int colonne) { // Riceve un doppio puntatore
    int somma = 0;                                            // Accumulatore inizializzato

    for (int i = 0; i < righe; i++) {                          // Scorre i puntatori alle righe
        for (int j = 0; j < colonne; j++) {                    // Scorre gli elementi della riga
            somma = somma + *(*(a + i) + j);                  // Accede all'elemento tramite doppio puntatore
        }                                                     // Fine ciclo colonne
    }                                                         // Fine ciclo righe

    return somma;                                             // Restituisce la somma totale
}