// 1. Realizzare una function C che determina il massimo elemento di un array

// 2. Realizzare una function C che determina il minimo elemento di un array

// 3. Realizzare una function C che determina il massimo e il minimo elemento di un array

// 4. Realizzare una function C che calcola la somma degli elementi di un array


#include <stdio.h>

// Prototipi delle funzioni
void legge_da_tastiera_aI(int [], int);
void visualizza_aI(int [], int);
int massimo_arrayI(int [], int);
int minimo_arrayI(int [], int n);
void max_min_arrayI(int a[], int n, int *max, int *min);
int somma_arrayI(int *, int);

int main() {
    int a[100], massimo, minimo, n_elem, somma;

    do {
        printf("Inserire il numero di elementi (1-100): ");
        scanf("%d", &n_elem);
    } while (n_elem < 1 || n_elem > 100);

    legge_da_tastiera_aI(a, n_elem);

    printf("\nL'array e':\n");
    visualizza_aI(a, n_elem);
    printf("\n");

    // 1. Massimo elemento dell'array
    massimo = massimo_arrayI(a, n_elem);

    printf("\nIl massimo tra gli elementi: %d\n", massimo);

    // 2. Minimo elemento dell'array
    minimo = minimo_arrayI(a, n_elem);

    printf("\nIl minimo tra gli elementi: %d\n", minimo);

    // 3. Massimo e minimo tramite puntatori
    max_min_arrayI(a, n_elem, &massimo, &minimo);

    printf("\nIl massimo tramite puntatore: %d\n", massimo);
    printf("Il minimo tramite puntatore: %d\n", minimo);

    // 4. Somma degli elementi dell'array
    somma = somma_arrayI(a, n_elem);

    printf("\nLa somma degli elementi: %d\n", somma);
    printf("\n");

    return 0;
}

// Legge gli elementi dell'array da tastiera
void legge_da_tastiera_aI(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Inserisci elemento %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// Visualizza tutti gli elementi dell'array
void visualizza_aI(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}


// Restituisce il massimo tra gli elementi dell'array
int massimo_arrayI(int a[], int n) {
    int max, i;

    max = a[0]; 

    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}


/* Minimo tra gli elementi di un array int - notazione standard */
int minimo_arrayI(int a[], int n) {
    int min, i;

    min = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    return min;
}


/* Massimo e minimo tra gli elementi di un array int - notazione standard */
void max_min_arrayI(int a[], int n, int *max, int *min) {
    int i;

    *max = a[0];
    *min = a[0];

    for (i = 1; i < n; i++) { //max: 70    min: 2
        if (a[i] > *max) {
            *max = a[i];
        }
        else if (a[i] < *min) {
            *min = a[i];
        }
    }
}


/* Somma degli elementi di un array int - notazione a puntatore */
int somma_arrayI(int *a, int n) {
    int i, somma = 0;

    for (i = 0; i < n; i++) {
        somma = somma + *(a + i*sizeof(int)); // somma = somma + a[i]
    }

    return somma;
}