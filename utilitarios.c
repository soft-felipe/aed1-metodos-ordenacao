#include <stdlib.h>
#include <time.h>
#include "utilitarios.h"
#include <stdio.h>
#include "metodos.h"

int *alocaMemoriaVetorInteiros(int tamanho) {
    return (int *) malloc(tamanho * sizeof(int));
}

int *geraVetorAleatorio(int tamanho) {
    int *vetor = alocaMemoriaVetorInteiros(tamanho);

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100000;
    }
    return vetor;
}

void printVetor(int *vetor, int numeroElementos) {
    for (int i = 0; i < numeroElementos; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int maiorElemento(int *vetor, int tamanho) {
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

double tempoDeExecucao(int *vetor, int numeroElementos, int indice) {
    double (*metodos[])(int *, int) = { insertionSortTime, selectionSortTime, bubbleSortTime, mergeSortTime, quickSortTime, countingSortTime, radixSortTime, bucketSortTime};
    return metodos[indice](vetor, numeroElementos);
}

void zeraArrayDouble(double *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = 0;
    }
}