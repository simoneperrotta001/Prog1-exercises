/*
 * ============================================================
 *                    PROVA INTERCORSO 2
 *                 ESERCIZIO 2 - A, B E C
 * ============================================================
 *
 * Scrivere una function C che prenda in input tre valori
 * reali mediante le variabili a, b e c e restituisca
 * in output:
 *
 * - le variabili a e b con i valori scambiati se a < b.
 *
 * - c = |b - a| (valore assoluto) se a >= b
 *   e c = 0.
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

void funzione(double *a, double *b, double *c) {
    if (*a < *b) {
        scambiare(a, b);
        *c = 0;
    } else {
        *c = valore_assoluto(*b - *a);
    }
}

int main() {
    double a, b, c;

    printf("Inserisci a: ");
    scanf("%lf", &a);

    printf("Inserisci b: ");
    scanf("%lf", &b);

    printf("Inserisci c: ");
    scanf("%lf", &c);

    funzione(&a, &b, &c);

    printf("a = %.2f\n", a);
    printf("b = %.2f\n", b);
    printf("c = %.2f\n", c);

    return 0;
}