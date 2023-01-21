/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include "utilitarios.h"
#include <time.h>
#include "metodos.h"

/**
 * @author Daniel Nogueira
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @param pos Digito a ser considerado para ordenacao
 */
void countingSortToRadix(int vetor[], int numeroElementos, int pos) {
    int resultado[numeroElementos + 1];
    int count[10] = {0};
    
    for (int i = 0; i < numeroElementos; i++) {
        count[(vetor[i] / pos) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = numeroElementos - 1; i >= 0; i--) {
        resultado[count[(vetor[i] / pos) % 10] - 1] = vetor[i];
        count[(vetor[i] / pos) % 10]--;
    }

    for (int i = 0; i < numeroElementos; i++) {
        vetor[i] = resultado[i];
    }
}

/**
 * @author Daniel Nogueira
 * @referencia
 * Ordena um vetor de inteiros utilizando o método de ordenação Radix Sort
 * que implementa o Counting Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void radixSort(int vetor[], int numeroElementos) {
    int max = maiorElemento(vetor, numeroElementos);
    for (int pos = 1; max / pos > 0; pos *= 10) {
        countingSortToRadix(vetor, numeroElementos, pos);
    }
}

/**
* @author Daniel Nogueira
* Computa o tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
* @param vetor Vetor a ser ordenado
* @param numeroElementos Tamanho do vetor
* @return Tempo gasto para ordenar o vetor
*/
double radixSortTime(int *vetor, int numeroElementos) {
    clock_t inicio, fim;
    double tempoGasto;
    inicio = clock();
    radixSort(vetor, numeroElementos);
    fim = clock();
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}