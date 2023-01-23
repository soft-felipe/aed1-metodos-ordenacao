#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include "stdbool.h"

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

void setElementoProximo(struct elemento *elemento, struct elemento *proximoElemento);

void setElementoAnterior(struct elemento *elemento, struct elemento *elementoAnterior);

void setPrimeiroElemento(struct bucket *bucket, struct elemento *elemento);

void setTamanhoBucket(struct bucket *bucket, int tamanho);

void trocaElementoComPrimeiroElementoBucket(struct bucket *bucket, struct elemento *elemento);

bool trocaElementosDePosicao(struct bucket *bucket, struct elemento *elemento, struct elemento *proximoElemento);


#endif //BUCKET_SORT_H