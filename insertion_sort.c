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
 * @referencia Feito em sala, durante a aula com auxilio dos slides
 * Ordena um vetor de inteiros utilizando o método de ordenação Insertion Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void insertionSort(int *vetor, int numeroElementos) {
    int i, j, aux;
    i = 0;
    j = 1;

    while (j < numeroElementos) {
        i = j - 1;
        aux = vetor[j];
        while ((i >= 0) && (vetor[i] > aux)) {
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = aux;
        j++;
    }
}

/**
* @author Daniel Nogueira
 * Computa o tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @return Tempo gasto para ordenar o vetor
 */
double insertionSortTime(int *vetor, int numeroElementos) {
    clock_t inicio, fim;
    double tempoGasto;
    inicio = clock();
    insertionSort(vetor, numeroElementos);
    fim = clock();
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}