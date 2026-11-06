/*
 * ============================================================
 *                    PROVA INTERCORSO 1
 *                  ESERCIZIO 1 - BAGAGLIO
 * ============================================================
 *
 * Scrivere una function C che riceva come parametri il peso
 * massimo consentito per un bagaglio e il numero di oggetti
 * da inserire.
 *
 * La funzione deve acquisire da tastiera il peso di ciascun
 * oggetto, calcolare il peso totale del bagaglio e determinare
 * l'esito della verifica:
 *
 * - positivo, se il peso totale e' minore o uguale al limite
 *   consentito;
 *
 * - negativo, se il peso totale supera tale limite.
 *
 * La funzione deve restituire l'esito (1 per esito positivo,
 * 0 per esito negativo) e il peso totale.
 *
 * Implementare un programma completo con main che acquisisca
 * il peso massimo consentito e il numero di oggetti, richiami
 * la funzione e visualizzi il peso totale e l'esito della
 * verifica.
 *
 * Si controlli che il peso massimo consentito e il numero
 * di oggetti siano strettamente positivi e si assume che
 * tutti i pesi siano positivi.
 *
 * ============================================================
 */

#include <stdio.h>

int verifica_bagaglio(double peso_massimo, int n, double *peso_totale) {
    double peso;

    *peso_totale = 0;

    for (int i = 0; i < n; i++) {
        do {
            printf("Inserisci il peso dell'oggetto %d: ", i + 1);
            scanf("%lf", &peso);
        } while (peso <= 0);

        *peso_totale += peso;
    }

    if (*peso_totale <= peso_massimo)
        return 1;
    else
        return 0;
}

int main() {
    double peso_massimo, peso_totale;
    int n, esito;

    do {
        printf("Inserisci il peso massimo consentito: ");
        scanf("%lf", &peso_massimo);
    } while (peso_massimo <= 0);

    do {
        printf("Inserisci il numero di oggetti: ");
        scanf("%d", &n);
    } while (n <= 0);

    esito = verifica_bagaglio(peso_massimo, n, &peso_totale);

    printf("\nPeso totale: %.2f\n", peso_totale);

    if (esito == 1)
        printf("Esito positivo.\n");
    else
        printf("Esito negativo.\n");

    return 0;
}