#include <stdio.h> 

void modifica(int *p) {  //questo p, si trova all'indirizzo di memoria 3000, e contiene nella sua locazione di memoria, l'indirizzo di memoria di x, ovvero 1000
    *p = *p + 5; // modifica il valore di memoria puntato da p, ovvero x, aggiungendo 5
}

int main() { 
    int x = 10; // il valore di memoria della variabile x è 10, e si trova all'indirizzo 1000
    int *ptr = &x; // il puntatore (all'inizio consideratelo ance solo una variabile normale) ptr punta all'indirizzo di memoria di x, ovvero 1000 nel nostro esempio, e quindi contiene nella sua locazione di memoria, 1000, e si trova all'indirizzo 2000

    modifica(ptr); //funzione che modifica il valore di x tramite il puntatore ptr
     
    return 0; 
}