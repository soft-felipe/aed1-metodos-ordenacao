#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include "stdbool.h"
#include "metodos.h"

typedef struct bucket Bucket;

typedef struct elemento Elemento;

struct bucket *iniciaBucket();

struct elemento *iniciaElemento(int valor);

void adicionaElemento(struct bucket *bucket, struct elemento *elementoAnterior, struct elemento *elemento);

bool bucketVazio(struct bucket *bucket);

void adicionaElementoNaPrimeiraPosicaoBucket(struct bucket *bucket, struct elemento *elemento);

void adicionaElementoNaUltimaPosicaoBucket(struct bucket *bucket, struct elemento *elemento);

void adicionaElementoBucket(struct bucket *bucket, struct elemento *elemento);

struct bucket **alocaMemoriaBuckets(int quantidadeBuckets);

struct bucket **iniciaBuckets(int quantidadeBuckets);

void copiaValoresDeUmaListaDeElementosParaUmVetor(int *vetor, struct elemento *elemento, int posicao);

int getValorElemento(struct elemento *elemento);

struct elemento *getProximoElemento(struct elemento *elemento);

struct elemento *getAnteriorElemento(struct elemento *elemento);

struct elemento *getPrimeiroElemento(struct bucket *bucket);

int getTamanhoBucket(struct bucket *bucket);


#endif //BUCKET_SORT_H