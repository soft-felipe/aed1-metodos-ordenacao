/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <time.h>
#include "metodos.h"

/**
 * @author Daniel Nogueira
 * Ordena um vetor de inteiros utilizando o método de ordenação Merge Sort, fragmentando o vetor em sub-vetores
 * @param vetor Vetor a ser ordenado
 * @param tamanhoVetor Tamanho do vetor
 */
void mergeSort(int *vetor, int tamanhoVetor) {
    if (tamanhoVetor < 2) {
        return;
    }

    int meio = (double)tamanhoVetor * 1.0 / 2.0;
    int esquerda[meio];
    int direita[tamanhoVetor - meio];

    for (int i = 0; i < meio; i++) {
        esquerda[i] = vetor[i];
    }
    for (int i = meio; i < tamanhoVetor; i++) {
        direita[i - meio] = vetor[i];
    }

    mergeSort(vetor, meio);
    mergeSort(vetor, tamanhoVetor - meio);
    merge(vetor, esquerda, direita, meio, tamanhoVetor - meio);
}

/**
 * @author Felipe Moreira
 * Ordena os sub-vetores
 * @param vetor Vetor a ser ordenado
 * @param esquerda Vetor da esquerda
 * @param direita Vetor da direita
 * @param tamanhoEsquerda Tamanho do vetor da esquerda
 * @param tamanhoDireita Tamanho do vetor da direita
 */
void merge(int *vetor, int *esquerda, int *direita, int tamanhoEsquerda, int tamanhoDireita) {
    int i = 0, j = 0, k = 0;
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            vetor[k++] = esquerda[i++];
        } else {
            vetor[k++] = direita[j++];
        }
    }
    while (i < tamanhoEsquerda) {
        vetor[k++] = esquerda[i++];
    }
    while (j < tamanhoDireita) {
        vetor[k++] = direita[j++];
    }
}

/**
* @author Daniel Nogueira
 * Computao tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @return Tempo gasto para ordenar o vetor
 */
double mergeSortTime(int *vetor, int numeroElementos) {
    clock_t inicio, fim;
    double tempoGasto;
    inicio = clock();
    mergeSort(vetor, numeroElementos);
    fim = clock();
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}

