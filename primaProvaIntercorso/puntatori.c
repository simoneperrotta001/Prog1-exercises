#include <stdio.h>

// Funzione che raddoppia il valore tramite puntatore
void raddoppia(int *p) {
    *p = *p * 2;
}

int main() {
    int numero;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    printf("Prima: %d\n", &numero);

    int *p = &numero; // Puntatore che punta alla variabile numero

    printf("Indirizzo di memoria di numero: %d\n", *p);

    raddoppia(p);

    printf("Dopo: %d\n", numero);

    return 0;
}