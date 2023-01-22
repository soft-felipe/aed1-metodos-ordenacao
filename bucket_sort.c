/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include "utilitarios.h"
#include "metodos.h"
#include <time.h>
#include <stdlib.h>

struct elemento {
    int valor;
    struct elemento *proximo;
};

struct bucket {
    int tamanho;
    int *primeiroElemento;
};

/**
 * @author Daniel Nogueira
 * @referencia
 * Inicia um bucket
 *@return bucket
 */
Bucket *iniciaBucket() {
    Bucket *bucket = (Bucket *) malloc(sizeof(Bucket));
    bucket->tamanho = 0;
    bucket->primeiroElemento = NULL;

    return bucket;
}

/**
 * @author Daniel Nogueira
 * @referencia
 * Inicia um elemento
 * @return elemento
 */
Elemento *iniciaElemento() {
    Elemento *elemento = (Elemento *) malloc(sizeof(Elemento));
    elemento->valor = 0;
    elemento->proximo = NULL;

    return elemento;
}

/**
 * @author Daniel Nogueira
 * @referencia
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
 * Computa o tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
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