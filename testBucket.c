#include "bucket_sort.h"
#include "utilitarios.h"
#include <stdio.h>
#include "metodos.h"
#include <stdlib.h>

void testBucketSortDesordenado() {
    int *vetorDesordenado;

    int tamanho = 100000;
    vetorDesordenado =

    vetorDesordenado = geraVetorAleatorio(tamanho);

    bucketSort(vetorDesordenado, tamanho);

    for (int indice = 0; indice < tamanho - 1; indice++) {
        if (vetorDesordenado[indice] > vetorDesordenado[indice + 1]) {
            printf("Erro no bucket sort com vetor desordenado");
            return;
        }
    }

    double tempo = bucketSortTime(vetorDesordenado, tamanho);
    printf("\nTempo: %f", tempo);
    free(vetorDesordenado);
}

void imprimeResultadoTestBucket() {
    printf("Teste bucket sort\n");
    testBucketSortDesordenado();
}