/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */
#include "metodos.h"

/**
 * @author Daniel Nogueira
 * Ordena um vetor de inteiros utilizando o método de ordenação Bucket Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void bucketSort(int vetor[], int numeroElementos) {
    int maior = vetor[0];
    for (int i = 1; i < numeroElementos; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    int bucket[maior + 1];

    for (int i = 0; i < maior + 1; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < numeroElementos; i++) {
        bucket[vetor[i]]++;
    }

    int indice = 0;
    for (int i = 0; i<= maior; i++) {
        while (bucket[i] > 0) {
            vetor[indice++] = i;
            bucket[i]--;
        }
    }
}