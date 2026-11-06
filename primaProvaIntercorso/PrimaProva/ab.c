/*
 * ============================================================
 *                    PROVA INTERCORSO 1
 *                  ESERCIZIO 2 - A E B
 * ============================================================
 *
 * Scrivere una function C che prenda in input due valori
 * reali (tipo double) mediante le variabili a, b e
 * restituisca in output:
 *
 * - le due variabili con i valori scambiati se a < b.
 *
 * - a = (a - b)^2 (quadrato) e
 *   b = |b - a| (valore assoluto)
 *   se a >= b.
 *
 * Implementare un programma contenente un main per fare
 * un esempio di esecuzione della function C realizzata.
 *
 * N.B.: usare e scrivere le funzioni scambiare() e
 * valore_assoluto() viste a lezione.
 *
 * ============================================================
 */

#include <stdio.h>

void scambiare(double *x, double *y) {
    double temp = *x;
    *x = *y;
    *y = temp;
}

double valore_assoluto(double x) {
    if (x < 0)
        return -x;
    else
        return x;
}

void funzione(double *a, double *b) {
    if (*a < *b) {
        scambiare(a, b);
    } else {
        *a = (*a - *b) * (*a - *b);
        *b = valore_assoluto(*b - *a);
    }
}

int main() {
    double a, b;

    printf("Inserisci a: ");
    scanf("%lf", &a);

    printf("Inserisci b: ");
    scanf("%lf", &b);

    funzione(&a, &b);

    printf("a = %.2f\n", a);
    printf("b = %.2f\n", b);

    return 0;
}