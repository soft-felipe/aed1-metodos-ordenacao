/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#ifndef AED1_METODOS_ORDENACAO_METODOS_H
#define AED1_METODOS_ORDENACAO_METODOS_H

#include "bucket_sort.h"

void insertionSort(int *vetor, int numeroElementos);

void selectionSort(int *vetor, int numeroElementos);

void bubbleSort(int *vetor, int numeroElementos);

void mergeSort(int *vetor, int numeroElementos);

void sort(int *vetor, int inicio, int fim);

void merge(int *vetor, int inicio, int meio, int fim);

void quickSort(int *vetor, int numeroElementos);

void quick(int *vetor, int inicio, int fim);

int particiona(int *vetor, int inicio, int fim);

void countingSort(int *vetor, int numeroElementos);

void radixSort(int *vetor, int numeroElementos);

void countingSortToRadix(int *vetor, int numeroElementos, int exp);

void bucketSort(int *vetor, int numeroElementos);

void insertionSortToBucket(struct bucket *bucket);

double insertionSortTime(int *vetor, int numeroElementos);

double selectionSortTime(int *vetor, int numeroElementos);

double bubbleSortTime(int *vetor, int numeroElementos);

double mergeSortTime(int *vetor, int numeroElementos);

double quickSortTime(int *vetor, int numeroElementos);

double countingSortTime(int *vetor, int numeroElementos);

double radixSortTime(int *vetor, int numeroElementos);

double bucketSortTime(int *vetor, int numeroElementos);

#endif //AED1_METODOS_ORDENACAO_METODOS_H