/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */


#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include "stdbool.h"

typedef struct bucket Bucket;

struct bucket *iniciaBucket();

struct bucket **alocaMemoriaBuckets(int quantidadeBuckets);

struct bucket **iniciaBuckets(int quantidadeBuckets);

int getTamanhoBucket(struct bucket *bucket);

void setTamanhoBucket(struct bucket *bucket, int tamanho);

void incrementaTamanhoBucket(struct bucket *bucket);

void liberaMemoriaBuckets(struct bucket **buckets, int quantidadeBuckets);

void liberaMemoriaBucket(struct bucket *bucket);

#endif //BUCKET_SORT_H