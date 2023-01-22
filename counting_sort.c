/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include "metodos.h"
#include <time.h>
#include "utilitarios.h"
#include <stdlib.h>

/**
 * @author Felipe Moreira
 * @referencia Slides dos algoritmos de distribuiçao apresentados em sala
 *             Programaçao Descomplicada: Aula 123 - Counting Sort
 *             Link video aula: https://www.youtube.com/watch?v=En8daEdcpJU&ab_channel=Programa%C3%A7%C3%A3oDescomplicada
 * Ordena um vetor de inteiros utilizando o método de ordenação Counting Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void countingSort(int *vetor, int numeroElementos) {
    int i, j, k;
    int max = maiorElemento(vetor, numeroElementos);

    int *aux = alocaMemoriaVetorInteiros(max + 1);
    for (i = 0; i <= max; i++) {
        aux[i] = 0;
    }

    for (i = 0; i < numeroElementos; i++) {
        aux[vetor[i]]++;
    }

    for (i = 0, j = 0; j <= max; j++) {
        for (k = aux[j]; k > 0; k--) {
            vetor[i] = j;
            i++;
        }
    }

    free(aux);
}

/**
* @author Daniel Nogueira
 * Computa o tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @return Tempo gasto para ordenar o vetor
 */
double countingSortTime(int *vetor, int numeroElementos) {
    clock_t inicio, fim;
    double tempoGasto;
    inicio = clock();
    countingSort(vetor, numeroElementos);
    fim = clock();
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}