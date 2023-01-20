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


void countingSortToRadix(int arr[], int n, int pos)
{
    int result[n + 1];
    int count[10] = {0};

    // count howmany numbers are present with digit 0-9 at given position
    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;

    // now do prefix sum of the count array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        result[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}

void radixSort(int arr[], int n) {

    int max_element = maiorElemento(arr, n);

    // counting sort from the least significant digit to the most significant digit
    for (int pos = 1; max_element / pos > 0; pos *= 10)
        countingSortToRadix(arr, n, pos);
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