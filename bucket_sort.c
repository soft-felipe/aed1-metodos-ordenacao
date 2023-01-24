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
#include "string.h"

#define QUANTIDADE_BUCKETS 10

/**
 * Tipo abstrato de dado para representar um elemento de um bucket
 */
struct elemento {
    int valor;
    struct elemento *proximo;
};

/**
 * Tipo abstrato de dado para representar um bucket
 */
struct bucket {
    int tamanho;
    struct elemento *primeiroElemento;
};

/**
 * @author Daniel Nogueira
 * Fornece o valor armazenado em um elemento
 * @param elemento Elemento a ser consultado
 * @return valor armazenado no elemento
 */
int getValorElemento(struct elemento *elemento) {
    return elemento->valor;
}

/**
 * @author Daniel Nogueira
 * Fornece o próximo elemento de um elemento
 * @param elemento Elemento a ser consultado
 * @return próximo elemento
 */
struct elemento *getProximoElemento(struct elemento *elemento) {
    return elemento->proximo;
}

/**
 * @author Daniel Nogueira
 * Fornece o primeiro elemento de um bucket
 * @param bucket Bucket a ser consultado
 * @return primeiro elemento do bucket
 */
struct elemento *getPrimeiroElemento(struct bucket *bucket) {
    return bucket->primeiroElemento;
}

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
 * Posiciona um elemento na frente de outro elemento
 * @param elemento Elemento
 * @param elementoProximo Elemento a ser posicionado na frente do elemento
 */
void setElementoProximo(struct elemento *elemento, struct elemento *elementoProximo) {
    elemento->proximo = elementoProximo;
}

/**
 * @author Daniel Nogueira
 * Posiciona um elemento como primeiro elemento de um bucket
 * @param bucket Bucket a ser consultado
 * @param elemento Elemento a ser posicionado como primeiro do bucket
 */
void setPrimeiroElemento(struct bucket *bucket, struct elemento *elemento) {
    bucket->primeiroElemento = elemento;
}

/**
 * @author Daniel Nogueira
 * Coloca um elemento no final da lista de um bucket
 * @param bucket Bucket a ser modificado
 * @param elemento Elemento que sera colocado no final do Bucket
 */
void setUltimoElemento(struct bucket *bucket, struct elemento *elemento) {
    struct elemento *ultimoElemento = getPrimeiroElemento(bucket);
    while (getProximoElemento(ultimoElemento) != NULL) {
        ultimoElemento = getProximoElemento(ultimoElemento);
    }
    setElementoProximo(ultimoElemento, elemento);
    elemento->proximo = NULL;
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
 * Define o valor de um elemento
 * @param elemento Elemento a ter o valor definido
 * @param valor Valor a ser definido no elemento
 */
void setValorElemento(struct elemento *elemento, int valor) {
    elemento->valor = valor;
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
 * Desaloca memória alocada para um lista de elementos
 * @param elemento Primeiro elemento de uma lista a ser desalocada
 */
void liberaMemororiaElementos(struct elemento *elemento) {
    Elemento *elemenoTmp;
    while (elemento != NULL) {
        elemenoTmp = elemento;
        elemento = getProximoElemento(elemento);
        free(elemenoTmp);
    }
}

/**
 * @author Daniel Nogueira
 * Dealoca memória de um bucket, incluindo sua lista de elementos
 * @param bucket Bucket a ter sua memória desalocada, incluindo a lista de elementos
 */
void liberaMemoriaBucket(struct bucket *bucket) {
    liberaMemororiaElementos(getPrimeiroElemento(bucket));
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
 * @param vetor Vetor que recebera a copia dos valores
 * @param elemento Primeiro elemento da lista de elementos a ser copiada
 * @param posicao Posicao do vetor a partir da qual os valores serao copiados
 */
void copiaValoresDeUmaListaDeElementosParaUmVetor(int *vetor, Elemento *elemento, int posicao) {
    while (elemento != NULL) {
        memcpy(&vetor[posicao], &elemento->valor, sizeof(int));
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

/**
 * @author Daniel Nogueira
 * Remove um elemento de uma lista de elementos
 * @param elemento Elemento a ser removido
 * @param elementoAnterior Elemento anterior ao elemento a ser removido
 */
void removeElementoLista(Elemento *elemento, Elemento *elementoAnterior) {
    elementoAnterior->proximo = elemento->proximo;
}

/**
 * @author Daniel Nogueira
 * Adiciona um elemento em uma lista de elementos
 * @param elemento Elemento a ser adicionado
 * @param elementoAnterior Elemento anterior ao elemento a ser adicionado
 */
void adicionaElementoLista(Elemento *elemento, Elemento *elementoAnterior) {
    elemento->proximo = elementoAnterior->proximo;
    elementoAnterior->proximo = elemento;
}

/**
 * @author Daniel Nogueira
 * Método de ordenação Insertion Sort adaptado para as estruturas de dados utilizadas no Bucket Sort
 * @param bucket Bucket a ser ordenado
 */
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