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