/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <time.h>
#include "metodos.h"

/**
 * @author Felipe Moreira
 * Ordena um vetor de inteiros utilizando o método de ordenação Selection Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void selectionSort(int *vetor, int numeroElementos) {
    int i, j, min, aux;

    for (i = 0; i < (numeroElementos-1); i++) {
        min = i;

        for (j = i+1; j < numeroElementos; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }

        if (vetor[i] != vetor[min]) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

/**
* @author Daniel Nogueira
 * Computao tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @return Tempo gasto para ordenar o vetor
 */
double selectionSortTime(int *vetor, int numeroElementos) {
    clock_t inicio, fim;
    double tempoGasto;
    inicio = clock();
    selectionSort(vetor, numeroElementos);
    fim = clock();
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}