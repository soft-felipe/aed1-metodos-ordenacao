/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include "utilitarios.h"
#include "metodos.h"
#include <time.h>
/**
 * @author Daniel Nogueira
 * Ordena um vetor de inteiros utilizando o método de ordenação Bucket Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void bucketSort(int *vetor, int numeroElementos) {
    int maior = maiorElemento(vetor, numeroElementos);

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

/**
* @author Daniel Nogueira
 * Computao tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @return Tempo gasto para ordenar o vetor
 */
double bucketSortTime(int *vetor, int numeroElementos) {
    clock_t inicio, fim;
    double tempoGasto;
    inicio = clock();
    bucketSort(vetor, numeroElementos);
    fim = clock();
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}