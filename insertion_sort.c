/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include "metodos.h"
/**
 * @author Felipe Moreira
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