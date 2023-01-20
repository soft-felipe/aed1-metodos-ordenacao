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
 * Ordena um vetor de inteiros utilizando o método de ordenação Radix Sort
 * que implementa o Counting Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void radixSort(int *vetor, int numeroElementos) {
    int maior = maiorElemento(vetor, numeroElementos);

    for (int casaDecimal = 1; maior / casaDecimal > 0; casaDecimal *= 10) {
        countingSortToRadix(vetor, numeroElementos, casaDecimal);
    }
}

/**
 * @author Daniel Nogueira
 * Counting Sort modificado para suportar uma ordenação de Radix Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @param casaDecimal Marca a casa decimal que está sendo ordenada
 */
 void countingSortToRadix(int *vetor, int numeroElementos, int casaDecimal) {
    int vetorOrdenado[numeroElementos - 1];
    int maior = (vetor[0] / casaDecimal) % 10;

    for (int i = 1; i < numeroElementos; i++) {
        if (((vetor[i] / casaDecimal) % 10) > maior) {
            maior = vetor[i];
        }
    }
    int count[10] = {0};

    for (int i = 0; i < maior; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < numeroElementos; i++) {
        count[(vetor[i] / casaDecimal) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = numeroElementos - 1; i >= 0; i--) {
        vetorOrdenado[count[(vetor[i] / casaDecimal) % 10] - 1] = vetor[i];
        count[(vetor[i] / casaDecimal) % 10]--;
    }

    for (int i = 0; i < numeroElementos; i++) {
        vetor[i] = vetorOrdenado[i];
    }

}

/**
* @author Daniel Nogueira
* Computao tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
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