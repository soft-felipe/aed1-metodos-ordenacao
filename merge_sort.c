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
 * Ordena um vetor de inteiros utilizando o método de ordenação Merge Sort, fragmentando o vetor em sub-vetores
 * @param vetor Vetor a ser ordenado
 * @param tamanhoVetor Tamanho do vetor
 */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/**
 * @author Felipe Moreira
 * Ordena os sub-vetores
 * @param vetor Vetor a ser ordenado
 * @param esquerda Vetor da esquerda
 * @param direita Vetor da direita
 * @param tamanhoEsquerda Tamanho do vetor da esquerda
 * @param tamanhoDireita Tamanho do vetor da direita
 */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/**
* @author Daniel Nogueira
 * Computao tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @return Tempo gasto para ordenar o vetor
 */
double mergeSortTime(int *vetor, int numeroElementos) {
    clock_t inicio, fim;
    double tempoGasto;
    inicio = clock();
    mergeSort(vetor,0, numeroElementos - 1);
    fim = clock();
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}

