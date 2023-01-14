
#ifndef AED1_METODOS_ORDENACAO_METODOS_H
#define AED1_METODOS_ORDENACAO_METODOS_H

void insertionSort(int *vetor, int numeroElementos);

void selectionSort(int *vetor, int numeroElementos);

void bubbleSort(int *vetor, int numeroElementos);

void mergeSort(int *vetor, int tamanhoVetor);

void merge(int *vetor, int *esquerda, int *direita, int tamanhoEsquerda, int tamanhoDireita);

void quickSort(int *vetor, int inicio, int fim);

int particiona(int *vetor, int inicio, int fim);

void countingSort(int *vetor, int numeroElementos);

void countingSort(int *vetor, int numeroElementos);

void radixSort(int *vetor, int numeroElementos);

void countingSortToRadix(int *vetor, int numeroElementos, int exp);

void bucketSort(int *vetor, int numeroElementos);

#endif //AED1_METODOS_ORDENACAO_METODOS_H