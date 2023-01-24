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

int getValorElemento(struct elemento *elemento) {
    return elemento->valor;
}

struct elemento *getProximoElemento(struct elemento *elemento) {
    return elemento->proximo;
}

struct elemento *getPrimeiroElemento(struct bucket *bucket) {
    return bucket->primeiroElemento;
}

int getTamanhoBucket(struct bucket *bucket) {
    return bucket->tamanho;
}

void setElementoProximo(struct elemento *elemento, struct elemento *elementoProximo) {
    elemento->proximo = elementoProximo;
}


void setPrimeiroElemento(struct bucket *bucket, struct elemento *elemento) {
    bucket->primeiroElemento = elemento;
}

void setUltimoElemento(struct bucket *bucket, struct elemento *elemento) {
    struct elemento *ultimoElemento = getPrimeiroElemento(bucket);
    while (getProximoElemento(ultimoElemento) != NULL) {
        ultimoElemento = getProximoElemento(ultimoElemento);
    }
    setElementoProximo(ultimoElemento, elemento);
    elemento->proximo = NULL;
}

void setTamanhoBucket(struct bucket *bucket, int tamanho) {
    bucket->tamanho = tamanho;
}

void setValorElemento(struct elemento *elemento, int valor) {
    elemento->valor = valor;
}

void incrementaTamanhoBucket(struct bucket *bucket) {
    bucket->tamanho++;
}

void liberaMemororiaElementos(struct elemento *elemento) {
    Elemento *elemenoTmp;
    while (elemento != NULL) {
        elemenoTmp = elemento;
        elemento = getProximoElemento(elemento);
        free(elemenoTmp);
    }
}

void liberaMemoriaBucket(struct bucket *bucket) {
    liberaMemororiaElementos(getPrimeiroElemento(bucket));
    free(bucket);
}

void liberaMemoriaBuckets(struct bucket **buckets, int quantidadeBuckets) {
    for (int i = 0; i < quantidadeBuckets; i++) {
        liberaMemororiaElementos(getPrimeiroElemento(buckets[i]));
        free(buckets[i]);
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
    elemento->valor = valor;
    elemento->proximo = NULL;

    return elemento;
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
 * Adiciona um elemento na última posição de um bucket
 * @param bucket Bucket a ser adicionado o elemento
 * @param elemento Elemento a ser adicionado
 */
 void adicionaElementoNaUltimaPosicaoBucket(Bucket *bucket, Elemento *elemento) {
     if (bucketVazio(bucket)) {
         setPrimeiroElemento(bucket, elemento);
         bucket->tamanho++;
         return;
     } else {
         Elemento *elementoCorrente = bucket->primeiroElemento;
         while (elementoCorrente->proximo != NULL) {
             elementoCorrente = elementoCorrente->proximo;
         }
         setElementoProximo(elementoCorrente, elemento);
            bucket->tamanho++;
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
 * Copia os valores de uma lista de elementos para um vetor a partir de uma determinada posicao do vetor
 * @param vetor
 * @param elemento
 * @param posicao
 */
void copiaValoresDeUmaListaDeElementosParaUmVetor(int *vetor, Elemento *elemento, int posicao) {
    while (elemento != NULL) {
        vetor[posicao] = elemento->valor;
        elemento = elemento->proximo;
        posicao++;
    }
}


/**
 * @author Daniel Nogueira
 * @referencia
 * Ordena um vetor de inteiros utilizando o método de ordenação Bucket Sort
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void bucketSort(int *vetor, int numeroElementos) {
    Elemento *elemento;
    int maior = maiorElemento(vetor, numeroElementos);
    if (maior == 0) {
        return;
    }

    Bucket **buckets = iniciaBuckets(QUANTIDADE_BUCKETS);

    for (int indice = 0; indice < numeroElementos; indice++) {
        double porcentagemEmRelacaoMaior =  vetor[indice] * 1.0 / maior;

        if (porcentagemEmRelacaoMaior == 1) {
            porcentagemEmRelacaoMaior = 0.99;
        }

        int indiceBucket = (porcentagemEmRelacaoMaior * QUANTIDADE_BUCKETS);
        elemento = iniciaElemento(vetor[indice]);
        adicionaElementoBucket(buckets[indiceBucket], elemento);
    }

    int indiceVetor = 0;
    for (int indiceBucket = 0; indiceBucket < QUANTIDADE_BUCKETS; indiceBucket++) {
        if (buckets[indiceBucket]->tamanho > 1) {
            insertionSortToBucket(buckets[indiceBucket]);
        }

        copiaValoresDeUmaListaDeElementosParaUmVetor(vetor, buckets[indiceBucket]->primeiroElemento, indiceVetor);
        indiceVetor +=buckets[indiceBucket]->tamanho;
    }

    liberaMemoriaBuckets(buckets, QUANTIDADE_BUCKETS);
}

void removeElementoLista(Elemento *elemento, Elemento *elementoAnterior) {
    elementoAnterior->proximo = elemento->proximo;
}

void adicionaElementoLista(Elemento *elemento, Elemento *elementoAnterior) {
    elemento->proximo = elementoAnterior->proximo;
    elementoAnterior->proximo = elemento;
}

void insertionSortToBucket(Bucket *bucket) {
    Elemento *elementoCorrente = bucket->primeiroElemento->proximo;
    Elemento *maior = bucket->primeiroElemento;
    Elemento *elementoCorrenteProximo;
    while (elementoCorrente != NULL) {
        if (maior->valor > elementoCorrente->valor) {
            elementoCorrenteProximo = elementoCorrente->proximo;
            removeElementoLista(elementoCorrente, maior);
            if (elementoCorrente->valor < bucket->primeiroElemento->valor) {
                setElementoProximo(elementoCorrente, bucket->primeiroElemento);
                setPrimeiroElemento(bucket, elementoCorrente);
            } else {
                Elemento *indiceVetorOrdenado = bucket->primeiroElemento;
                while (indiceVetorOrdenado->proximo->valor < elementoCorrente->valor) {
                    indiceVetorOrdenado = indiceVetorOrdenado->proximo;
                }
                adicionaElementoLista(elementoCorrente, indiceVetorOrdenado);
            }
            elementoCorrente = elementoCorrenteProximo;
        }
        else {
            maior = elementoCorrente;
            elementoCorrente = elementoCorrente->proximo;
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