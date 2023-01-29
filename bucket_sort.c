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
#include "bucket_sort.h"
#include "string.h"

#define QUANTIDADE_BUCKETS 10

/**
 * Tipo abstrato de dado para representar um bucket
 */
struct bucket {
    int tamanho;
    int *array;
};

/**
 * @author Daniel Nogueira
 * Fornece o tamanho de um bucket
 * @param bucket Bucket a ser consultado
 * @return tamanho do bucket
 */
int getTamanhoBucket(struct bucket *bucket) {
    return bucket->tamanho;
}

/**
 * @author Daniel Nogueira
 * Define o tamanho de um bucket
 * @param bucket Bucket a ter o tamanho definido
 * @param tamanho Tamanho a ser inserido no bucket
 */
void setTamanhoBucket(struct bucket *bucket, int tamanho) {
    bucket->tamanho = tamanho;
}

/**
 * @author Daniel Nogueira
 * Incrementa o tamanho de um bucket
 * @param bucket Bucket a ter o tamanho incrementado
 */
void incrementaTamanhoBucket(struct bucket *bucket) {
    bucket->tamanho++;
}

/**
 * @author Daniel Nogueira
 * Dealoca memória de um bucket, incluindo sua lista de elementos
 * @param bucket Bucket a ter sua memória desalocada, incluindo a lista de elementos
 */
void liberaMemoriaBucket(struct bucket *bucket) {
    free(bucket->array);
    free(bucket);
}

/**
 * @author Daniel Nogueira
 * Desaloca memória de um vetor de buckets, incluindo suas listas de elementos
 * @param buckets Vetor de buckets a ter sua memória desalocada, incluindo as listas de elementos
 * @param quantidadeBuckets Quantidade de buckets no vetor
 */
void liberaMemoriaBuckets(struct bucket **buckets, int quantidadeBuckets) {
    for (int i = 0; i < quantidadeBuckets; i++) {
        liberaMemoriaBucket(buckets[i]);
    }
    free(buckets);
}

/**
 * @author Daniel Nogueira
 * @referencia
 * Inicia um bucket
 *@return bucket
 */
Bucket *iniciaBucket() {
    Bucket *bucket = (Bucket *) malloc(sizeof(Bucket));
    bucket->tamanho = 0;
    bucket->array = NULL;

    return bucket;
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
  * Copia o array de um bucket para uma posicao em um vetor
  * @param vetor Vetor que recebe a copia do array do bucket a partir de uma determinada
  * posicao
  * @param bucket Bucket que tem o array copiado
  * @param posicao Posicao do vetor que começara a ser copiado o array
  */
 void copiaValoresDoArrayParaVetor(int *vetor, Bucket *bucket, int posicao) {
     memcpy(&vetor[posicao], bucket->array, bucket->tamanho * sizeof(int));
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
        //Os elementos são adicionados nos buckets pelo tamanho deles em
        //relação ao maior elemento do vetor
        //Os buckets são divididos em faixas de 10% do maior elemento
        //Ex: se o maior elemento do vetor for 1000 e o elemento atual for 500,
        //ele será adicionado no bucket 5
        double porcentagemEmRelacaoMaior =  vetor[indice] * 1.0 / maior;

        //Se o elemento for do tamanho do maior elemento é necessário diminuir
        //sua porcetagem por questão dos calculos que são ultilizados para
        //determinar em qual bucket o elemento será adicionado
        if (porcentagemEmRelacaoMaior == 1) {
            porcentagemEmRelacaoMaior = 0.99;
        }

        //indiceBucket referencia qual bucket o elemento será adicionado
        int indiceBucket = (porcentagemEmRelacaoMaior * QUANTIDADE_BUCKETS);

        buckets[indiceBucket]->array = (int *) realloc(buckets[indiceBucket]->array,
                                                       (buckets[indiceBucket]->tamanho + 1) * sizeof (int));
        buckets[indiceBucket]->array[buckets[indiceBucket]->tamanho] = vetor[indice];
        incrementaTamanhoBucket(buckets[indiceBucket]);
    }

    int indiceVetor = 0;
    for (int indiceBucket = 0; indiceBucket < QUANTIDADE_BUCKETS; indiceBucket++) {
        //Só ordena os buckets se eles tiverem mais de um elemento
        if (buckets[indiceBucket]->tamanho > 1) {
            //Método de ordenação utilizado para ordenar os elementos de um bucket
            countingSort(buckets[indiceBucket]->array, buckets[indiceBucket]->tamanho);
        }

        //Copia os valores dos elementos dos buckets ordenados para o vetor de inteiros
        //de acordo com a posicao do vetor que o elemento deve ser adicionado
        //ou seja, aglutina os buckets ordenados no vetor
        copiaValoresDoArrayParaVetor(vetor, buckets[indiceBucket], indiceVetor);
        indiceVetor +=buckets[indiceBucket]->tamanho;
    }

    //Libera a memoria alocada para os buckets e seus respectivos elementos
    liberaMemoriaBuckets(buckets, QUANTIDADE_BUCKETS);
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