/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <time.h>
#include "metodos.h"
#include "utilitarios.h"
#include <stdlib.h>

/**
 * @author Felipe Moreira
 * @author Daniel Nogueira
 * Encapsula o metodo mergeSort, recebendo somente o vetor e o seu tamanho
 * @param vetor
 * @param tamanho
 */
void mergeSort(int *vetor, int tamanho) {
    sort(vetor, 0, tamanho - 1);
}


/**
 * @author Felipe Moreira
 * @author Daniel Nogueira
 * @referencia PARCIAMENTE COPIADO: https://www.geeksforgeeks.org/merge-sort/
 * Ordena um vetor de inteiros utilizando o método de ordenação Merge Sort, fragmentando o vetor em sub-vetores
 * @param vetor Vetor a ser ordenado
 * @param tamanhoVetor Tamanho do vetor
 */
void sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        sort(vetor, inicio, meio);
        sort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

/**
 * @author Daniel Nogueira
 * @referencia PARICIAMENTE COPIADO: https://www.geeksforgeeks.org/merge-sort/
 * Ordena os sub-vetores
 * @param vetor Vetor a ser ordenado
 * @param esquerda Vetor da esquerda
 * @param direita Vetor da direita
 * @param tamanhoEsquerda Tamanho do vetor da esquerda
 * @param tamanhoDireita Tamanho do vetor da direita
 */
void merge(int vetor[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esq = alocaMemoriaVetorInteiros(n1);
    int *dir = alocaMemoriaVetorInteiros(n2);

    for (i = 0; i < n1; i++) {
        esq[i] = vetor[inicio + i];
    }

    for (j = 0; j < n2; j++) {
        dir[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            vetor[k] = esq[i];
            i++;
        } else {
            vetor[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esq[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = dir[j];
        j++;
        k++;
    }

    free(esq);
    free(dir);
}

/**
 * @author Daniel Nogueira
 * Computa o tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @return Tempo gasto para ordenar o vetor
 */
double mergeSortTime(int *vetor, int numeroElementos) {
    clock_t inicio, fim;
    double tempoGasto;
    inicio = clock();
    mergeSort(vetor, numeroElementos - 1);
    fim = clock();
    tempoGasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}

