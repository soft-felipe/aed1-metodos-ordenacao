/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include "utilitarios.h"
#include <stdio.h>
#include "metodos.h"
#include <stdlib.h>
#include "bucket_sort.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void testBucketSortDesordenado() {
    int *vetorDesordenado;

    int tamanho = 100000;
    vetorDesordenado =

    vetorDesordenado = geraVetorAleatorio(tamanho);

    bucketSort(vetorDesordenado, tamanho);

    for (int indice = 0; indice < tamanho - 1; indice++) {
        if (vetorDesordenado[indice] > vetorDesordenado[indice + 1]) {
            printf(ANSI_COLOR_RED "testBucketSort(): FAIL" ANSI_DEFAULT);
            return;
        }
    }
    printf(ANSI_COLOR_GREEN "testBucketSort(): SUCCESS" ANSI_DEFAULT);

    free(vetorDesordenado);
}

void imprimeResultadoTestBucket() {
    testBucketSortDesordenado();
}