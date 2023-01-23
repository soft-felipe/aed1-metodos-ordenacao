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
#include <stdbool.h>
#include <string.h>
#include "bucket_sort.h"

#define QUANTIDADE_BUCKETS 10

struct elemento {
    int valor;
    struct elemento *proximo;
};

struct bucket {
    int tamanho;
    struct elemento *primeiroElemento;
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
Elemento *iniciaElemento(int valor) {
    Elemento *elemento = (Elemento *) malloc(sizeof(Elemento));
    elemento->valor = 0;
    elemento->proximo = NULL;

    return elemento;
}

/**
 * @author Daniel Nogueira
 * @referencia
 * Adiciona um elemento como proximo de outro elemento
 * @param elemenetoAnterior Elemento anterior
 * @param elemento Elemento a ser adicionado
 */
void adicionaElemento(Bucket *bucket, Elemento *elementoAnterior, Elemento *elemento) {
    elementoAnterior->proximo = elemento;
    bucket->tamanho++;
}

/**
 * @author Daniel Nogueira
 * @referencia
 * Verifica se um bucket esta vazio
 * @param bucket Bucket a ser verificado
 * @return true se o bucket estiver vazio, false caso contrario
 */
bool bucketVazio(Bucket *bucket) {
    return bucket->tamanho == 0 && bucket->primeiroElemento == NULL;
}

/**
 * @author Daniel Nogueira
 * @referencia
 * Adiciona um elemento na primeira posicao de um bucket
 * @param bucket Bucket a ser adicionado o elemento
 * @param elemento Elemento a ser adicionado
 */

void adicionaElementoNaPrimeiraPosicaoBucket(Bucket *bucket, Elemento *elemento) {
    bucket->primeiroElemento = elemento;
    bucket->tamanho++;
}

/**
 * @author Daniel Nogueira
 * @referencia
 * Adiciona um elemento na última posição de um bucket
 * @param bucket Bucket a ser adicionado o elemento
 * @param elemento Elemento a ser adicionado
 */
 void adicionaElementoNaUltimaPosicaoBucket(Bucket *bucket, Elemento *elemento) {
     if (bucketVazio(bucket)) {
         adicionaElementoNaPrimeiraPosicaoBucket(bucket, elemento);
     } else {
         Elemento *elementoCorrente = bucket->primeiroElemento;
         while (elementoCorrente->proximo != NULL) {
             elementoCorrente = elementoCorrente->proximo;
         }
            adicionaElemento(bucket,elementoCorrente, elemento);
     }
 }

/**
 * @author Daniel Nogueira
 * @referencia
 * Adiciona um elemento ao bucket
 * @param bucket Bucket a ser adicionado o elemento
 * @param elemento Elemento a ser adicionado
 */
 void adicionaElementoBucket(Bucket *bucket, Elemento *elemento) {
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento);
 }

 /**
  * @author Daniel Nogueira
  * @referencia
  * Aloca memória dinamicamente para um vetor de buckets
  * @param quantidadeBuckets Quantidade de buckets a ser alocado
  * @return vetor de buckets
  */
 Bucket **alocaMemoriaBuckets(int quantidadeBuckets) {
     Bucket **buckets = (Bucket **) malloc(quantidadeBuckets * sizeof (Bucket *));

     return buckets;
 }
/**
 * @author Daniel Nogueira
 * @referencia
 * Instacia buckets em um vetor de buckets
 * @param quantidadeBuckets quantidade de buckets a ser alocada e instanciada
 * @return buckets vetor de buckets já instaciado
 */
 Bucket **iniciaBuckets(int quantidadeBuckets) {
     Bucket **buckets = alocaMemoriaBuckets(quantidadeBuckets);
     for (int i = 0; i < quantidadeBuckets; i++) {
         buckets[i] = iniciaBucket();
     }
     return buckets;
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
    if (maior == 0) {
        return;
    }

    Bucket **buckets = iniciaBuckets(QUANTIDADE_BUCKETS);

    for (int indice = 0; indice < numeroElementos; indice++) {
        double porcentagemEmRelacaoMaior =  vetor[indice] / maior;

        if (porcentagemEmRelacaoMaior == 1) {
            porcentagemEmRelacaoMaior = 0.99;
        }

        int indiceBucket = (porcentagemEmRelacaoMaior * QUANTIDADE_BUCKETS);
        Elemento *elemento = iniciaElemento(vetor[indice]);
        adicionaElementoBucket(buckets[indiceBucket], elemento);
    }

    int indiceVetor = 0;
    int indiceElemento;
    for (int indice = 0; indice < QUANTIDADE_BUCKETS; indice++) {
        insertionSortToBucket(buckets[indice]->primeiroElemento, buckets[indice]->tamanho);
        for (indiceElemento = 0; indiceElemento < buckets[indice]->tamanho; indiceElemento++) {
            vetor[indiceVetor] = buckets[indice]->primeiroElemento->valor;
        }
        indiceVetor +=indiceElemento;
    }


    free(buckets);
}

void insertionSortToBucket(Elemento *elemento, int tamanho) {
    int i, j, aux;
    i = 0;
    j = 1;

    while (j < tamanho) {
        i = j - 1;
        aux = elemento[j].valor;
        while ((i >= 0) && (elemento[i].valor > aux)) {
            elemento[i + 1].valor = elemento[i].valor;
            i--;
        }
        elemento[i + 1].valor = aux;
        j++;
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