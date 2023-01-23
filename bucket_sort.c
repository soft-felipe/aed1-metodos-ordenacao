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
    struct elemento *anterior;
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

struct elemento *getAnteriorElemento(struct elemento *elemento) {
    return elemento->anterior;
}

struct elemento *getPrimeiroElemento(struct bucket *bucket) {
    return bucket->primeiroElemento;
}

int getTamanhoBucket(struct bucket *bucket) {
    return bucket->tamanho;
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
    elemento->anterior = NULL;

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
    elemento->anterior = elementoAnterior;
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
         return;
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
        double porcentagemEmRelacaoMaior =  vetor[indice] * 1.0 / maior;

        if (porcentagemEmRelacaoMaior == 1) {
            porcentagemEmRelacaoMaior = 0.99;
        }

        int indiceBucket = (porcentagemEmRelacaoMaior * QUANTIDADE_BUCKETS);
        Elemento *elemento = iniciaElemento(vetor[indice]);
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

    free(buckets);
}


void trocarElementoComPrimeiroElementoDeUmBucket(Bucket *bucket, Elemento *elemento) {
    if(elemento->anterior == bucket->primeiroElemento) {
        Elemento *inicialmenteProximoDeElemento = elemento->proximo;
        Elemento *inicialmentePrimeiroElemento = bucket->primeiroElemento;

        inicialmenteProximoDeElemento->anterior = inicialmentePrimeiroElemento;

        elemento->anterior = NULL;
        elemento->proximo = inicialmentePrimeiroElemento;

        inicialmentePrimeiroElemento->anterior = elemento;
        inicialmentePrimeiroElemento->proximo = inicialmenteProximoDeElemento;

        bucket->primeiroElemento = elemento;

        return;
    }

    Elemento *inicialmenteAnteriorDeElemento = elemento->anterior;
    Elemento *inicialmenteProximoDeElemento = elemento->proximo;
    Elemento *inicialmentePrimeiroElemento = bucket->primeiroElemento;
    Elemento *inicialmenteProximoDoPrimeiroElemento = bucket->primeiroElemento->proximo;

    inicialmenteProximoDoPrimeiroElemento->anterior = elemento;

    inicialmenteAnteriorDeElemento->proximo = inicialmentePrimeiroElemento;
    inicialmenteProximoDeElemento->anterior = inicialmentePrimeiroElemento;

    elemento->anterior = NULL;
    elemento->proximo = inicialmenteProximoDoPrimeiroElemento;

    inicialmentePrimeiroElemento->anterior = inicialmenteAnteriorDeElemento;
    inicialmentePrimeiroElemento->proximo = inicialmenteProximoDeElemento;

    bucket->primeiroElemento = elemento;
}

/**
 * @author Daniel Nogueira
 * @referencia
 * Troca dos elementos de lugar em uma lista de elementos
 * @param elemento1 Elemento 1
 * @param elemento2 Elemento 2
 * @param bucket Bucket que contem os elementos
 * @return true se os elementos foram trocados, false caso contrario
 */
bool trocarElementosDePosicao(Bucket *bucket, Elemento *elemento1, Elemento *elemento2) {
    if (bucketVazio(bucket)) {
        return false;
    }

    if (elemento1->anterior == NULL) {
           trocarElementoComPrimeiroElementoDeUmBucket(bucket, elemento2);
            return true;
    }

    if (elemento2->anterior == NULL) {
           trocarElementoComPrimeiroElementoDeUmBucket(bucket, elemento1);
            return true;
    }

    Elemento *inicialmenteProximoDeElemento1 = elemento1->proximo;
    Elemento *inicialmenteProximoDeElemento2 = elemento2->proximo;
    Elemento *inicialmenteAnteriorDeElemento1 = elemento1->anterior;
    Elemento *inicialmenteAnteriorDeElemento2 = elemento2->anterior;

    inicialmenteProximoDeElemento1->anterior = elemento2;
    inicialmenteAnteriorDeElemento1->proximo = elemento2;

    inicialmenteProximoDeElemento2->anterior = elemento1;
    inicialmenteAnteriorDeElemento2->proximo = elemento1;

    elemento1->anterior = inicialmenteAnteriorDeElemento2;
    elemento1->proximo = inicialmenteProximoDeElemento2;

    elemento2->anterior = inicialmenteAnteriorDeElemento1;
    elemento2->proximo = inicialmenteProximoDeElemento1;

    return true;
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


void insertionSortToBucket(Bucket *bucket) {
    Elemento *primeiroElemento = bucket->primeiroElemento;
    Elemento *elementoCorrente = primeiroElemento->proximo;

    while (elementoCorrente != NULL) {
        Elemento *elementoAnterior = elementoCorrente->anterior;
        while ((elementoAnterior != NULL) && (elementoAnterior->valor > elementoCorrente->valor)) {
            trocarElementosDePosicao(bucket, elementoAnterior, elementoCorrente);
            elementoAnterior = elementoCorrente->anterior;
        }
        elementoCorrente = elementoCorrente->proximo;
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