/*
 * ============================================================
 *                    PROVA INTERCORSO 2
 *                 ESERCIZIO 1 - SUPERMERCATO
 * ============================================================
 *
 * Scrivere una function C che riceva come parametri il
 * budget disponibile per una spesa al supermercato e il
 * numero di prodotti da acquistare.
 *
 * La funzione deve acquisire da tastiera il prezzo di
 * ciascun prodotto, calcolare il costo totale della spesa
 * e determinare l'esito degli acquisti:
 *
 * - positivo, se il costo totale e' strettamente inferiore
 *   al budget;
 *
 * - negativo, se il costo totale e' maggiore o uguale
 *   al budget.
 *
 * La funzione deve restituire l'esito (1 per esito positivo,
 * 0 per esito negativo) e il costo totale.
 *
 * Implementare un programma completo di main che acquisisca
 * il budget e il numero di prodotti, richiami la funzione
 * e visualizzi il costo totale e l'esito degli acquisti.
 *
 * Si controlli che il budget e il numero di prodotti siano
 * strettamente positivi e si assume che i prezzi inseriti
 * siano non negativi.
 *
 * ============================================================
 */

#include <stdio.h>

int verifica_spesa(double budget, int n, double *costo_totale) {
    double prezzo;

    *costo_totale = 0;

    for (int i = 0; i < n; i++) {
        do {
            printf("Inserisci il prezzo del prodotto %d: ", i + 1);
            scanf("%lf", &prezzo);
        } while (prezzo < 0);

        *costo_totale += prezzo;
    }

    if (*costo_totale < budget)
        return 1;
    else
        return 0;
}

int main() {
    double budget, costo_totale;
    int n, esito;

    do {
        printf("Inserisci il budget: ");
        scanf("%lf", &budget);
    } while (budget <= 0);

    do {
        printf("Inserisci il numero di prodotti: ");
        scanf("%d", &n);
    } while (n <= 0);

    esito = verifica_spesa(budget, n, &costo_totale);

    printf("\nCosto totale: %.2f\n", costo_totale);

    if (esito == 1)
        printf("Esito positivo.\n");
    else
        printf("Esito negativo.\n");

    return 0;
}