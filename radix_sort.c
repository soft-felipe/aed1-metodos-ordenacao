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
 * Ordena um vetor de inteiros utilizando o método de ordenação Radix Sort
 * que implementa o Counting Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void radixSort(int *vetor, int numeroElementos) {
    int maior = vetor[0];
    for (int i = 1; i < numeroElementos; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        countingSortToRadix(vetor, numeroElementos, exp);
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
     int *vetorOrdenado = vetor;
     int vetorAuxiliar[10] = {0};
     for (int indice = 0; indice < numeroElementos; indice++) {
         vetorAuxiliar[(vetor[indice] / casaDecimal) % 10]++;
     }

     for (int indice = 1; indice < 10; indice++) {
         vetorAuxiliar[indice] += vetorAuxiliar[indice - 1];
     }

     for (int indice = numeroElementos - 1; indice >= 0; indice--) {
         vetorOrdenado[vetorAuxiliar[(vetor[indice] / casaDecimal) % 10] - 1] = vetor[indice];
         vetorAuxiliar[(vetor[indice] / casaDecimal) % 10]--;
     }

     for(int indice = 0; indice < numeroElementos; indice++) {
         vetor[indice] = vetorOrdenado[indice];
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


