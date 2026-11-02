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