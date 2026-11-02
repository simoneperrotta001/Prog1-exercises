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