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