#include "bucket_sort.h"
#include "stdio.h"
#include "stdlib.h"
#include "utilitarios.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void testIniciaBucket() {
    Bucket *bucket = iniciaBucket();
    if (getTamanhoBucket(bucket) == 0 && getPrimeiroElemento(bucket) == NULL) {
        printf(ANSI_COLOR_GREEN "testIniciaBucket(): SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testIniciaBucket(): FAIL" ANSI_DEFAULT "\n");
    }

    free(bucket);
}

void testIniciaElemento() {
    Elemento *elemento = iniciaElemento(1);
    if (getValorElemento(elemento) == 1 && getProximoElemento(elemento) == NULL && getAnteriorElemento(elemento) == NULL) {
        printf(ANSI_COLOR_GREEN "testIniciaElemento(): SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testIniciaElemento(): FAIL" ANSI_DEFAULT "\n");
    }

    free(elemento);
}

void testBucketVazioTrue() {
    Bucket *bucket = iniciaBucket();
    if (bucketVazio(bucket)) {
        printf(ANSI_COLOR_GREEN "testBucketVazioTrue(): SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testBucketVazioTrue(): FAIL" ANSI_DEFAULT "\n");
    }

    free(bucket);
}

void testBucketVazioFalse() {
    Bucket *bucket = iniciaBucket();
    Elemento *elemento = iniciaElemento(1);
    setPrimeiroElemento(bucket, elemento);
    if (!bucketVazio(bucket)) {
        printf(ANSI_COLOR_GREEN "testBucketVazio()False: SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testBucketVazio()False: FAIL" ANSI_DEFAULT "\n");
    }
    free(elemento);
    free(bucket);
}

void testAdicionaElementoNaUltimaPosicaoBucketTrueTamanhoEPosicao() {
    Bucket *bucket = iniciaBucket();
    setPrimeiroElemento(bucket, iniciaElemento(0));
    Elemento *elemento = iniciaElemento(1);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento);
    if (getProximoElemento(getPrimeiroElemento(bucket)) == elemento && getTamanhoBucket(bucket) == 2) {
        printf(ANSI_COLOR_GREEN "testAdicionaElementoNaUltimaPosicaoBucketTrueTamanhoEPosicao(): SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testAdicionaElementoNaUltimaPosicaoBucketTrueTamanhoEPosicao(): FAIL" ANSI_DEFAULT "\n");
    }
    free(elemento);
    free(bucket);
}

void testAdicionaElementoNaUltimaPosicaoBucketTrueAnterior() {
    Bucket *bucket = iniciaBucket();
    setPrimeiroElemento(bucket, iniciaElemento(0));
    Elemento *elemento = iniciaElemento(1);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento);
    if (getAnteriorElemento(getProximoElemento(getPrimeiroElemento(bucket))) == getPrimeiroElemento(bucket)) {
        printf(ANSI_COLOR_GREEN "testAdicionaElementoNaUltimaPosicaoBucketTrueAnterior(): SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testAdicionaElementoNaUltimaPosicaoBucketTrueAnterior(): FAIL" ANSI_DEFAULT "\n");
    }
    free(elemento);
    free(bucket);
}

void testAlocaMemoriaBucketsTrue() {
    Bucket **buckets = alocaMemoriaBuckets(10);

    int tamanhoDeMemoria = 0;
    for (int indice = 0; indice < 10; indice++) {
        tamanhoDeMemoria += sizeof(buckets[indice]);
    }

    if (tamanhoDeMemoria == sizeof(Bucket *) * 10) {
        printf(ANSI_COLOR_GREEN "testAlocaMemoriaBucketsTrue(): SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testAlocaMemoriaBucketsTrue(): FAIL" ANSI_DEFAULT "\n");
    }

    free(buckets);
}

void testAlocaMemoriaBucketsFalse() {
    Bucket **buckets = alocaMemoriaBuckets(10);

    int tamanhoDeMemoria = 0;
    for (int indice = 0; indice < 10; indice++) {
        tamanhoDeMemoria += sizeof(buckets[indice]);
    }

    if (!(tamanhoDeMemoria == sizeof(Bucket *) * 5)) {
        printf(ANSI_COLOR_GREEN "testAlocaMemoriaBuckets()False: SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testAlocaMemoriaBucketsFalse(): FAIL" ANSI_DEFAULT "\n");
    }

    free(buckets);
}

void testIniciaBuckets() {
    Bucket **buckets = iniciaBuckets(3);
    setPrimeiroElemento(buckets[0], iniciaElemento(0));
    setPrimeiroElemento(buckets[1], iniciaElemento(1));
    setPrimeiroElemento(buckets[2], iniciaElemento(2));

    if (getValorElemento(getPrimeiroElemento(buckets[0])) == 0 && getValorElemento(getPrimeiroElemento(buckets[1])) == 1 && getValorElemento(getPrimeiroElemento(buckets[2])) == 2) {
        printf(ANSI_COLOR_GREEN "testIniciaBuckets(): SUCCESS" ANSI_DEFAULT "\n");
    } else {
        printf(ANSI_COLOR_RED "testIniciaBuckets(): FAIL" ANSI_DEFAULT "\n");
    }

    free(buckets);

}

void testCopiarValoresDeUmaListaDeElementosParaUmVetorOrdenado() {
    Bucket *bucket = iniciaBucket();

    Elemento *elemento0 = iniciaElemento(0);
    Elemento *elemento1 = iniciaElemento(1);
    Elemento *elemento2 = iniciaElemento(2);
    Elemento *elemento3 = iniciaElemento(3);
    Elemento *elemento4 = iniciaElemento(4);

    setPrimeiroElemento(bucket, elemento0);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento1);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento2);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento3);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento4);

    int *vetor = alocaMemoriaVetorInteiros(5);
    copiaValoresDeUmaListaDeElementosParaUmVetor(vetor, getPrimeiroElemento(bucket), 0);

    for (int indice = 0; indice < 5; indice++) {
        if (vetor[indice] != indice) {
            printf(ANSI_COLOR_RED "testCopiaValoresDeUmaListaDeElementosParaUmVetorOrdenado(): FAIL" ANSI_DEFAULT "\n");
            return;
        }
    }

    printf(ANSI_COLOR_GREEN "testCopiaValoresDeUmaListaDeElementosParaUmVetorOrdenado(): SUCCESS" ANSI_DEFAULT "\n");

    free(vetor);
    free(bucket);
    free(elemento0);
    free(elemento1);
    free(elemento2);
    free(elemento3);
    free(elemento4);
}

void testCopiarValoresDeUmaListaDeElementosParaUmVetorSemiOrdenado() {
    Bucket *bucket = iniciaBucket();

    Elemento *elemento0 = iniciaElemento(0);
    Elemento *elemento1 = iniciaElemento(1);
    Elemento *elemento2 = iniciaElemento(2);
    Elemento *elemento3 = iniciaElemento(3);
    Elemento *elemento4 = iniciaElemento(10);

    setPrimeiroElemento(bucket, elemento0);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento1);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento2);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento3);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento4);

    int *vetor = alocaMemoriaVetorInteiros(5);
    copiaValoresDeUmaListaDeElementosParaUmVetor(vetor, getPrimeiroElemento(bucket), 0);

    for (int indice = 0; indice < 4; indice++) {
        if (vetor[indice] != indice) {
            printf(ANSI_COLOR_RED "testCopiaValoresDeUmaListaDeElementosParaUmVetorSemiOrdenado(): FAIL" ANSI_DEFAULT "\n");
            return;
        }
    }
    if (vetor[4] != 10) {
        printf(ANSI_COLOR_RED "testCopiaValoresDeUmaListaDeElementosParaUmVetorSemiOrdenado(): FAIL" ANSI_DEFAULT "\n");
        return;
    }

    printf(ANSI_COLOR_GREEN "testCopiaValoresDeUmaListaDeElementosParaUmVetorSemiOrdenado(): SUCCESS" ANSI_DEFAULT "\n");

    free(vetor);
    free(bucket);
    free(elemento0);
    free(elemento1);
    free(elemento2);
    free(elemento3);
    free(elemento4);
}

void testTrocaElementoComPrimeiroElementoBucketElementosSeguidos() {
    Bucket *bucket = iniciaBucket();
    Elemento *elemento0 = iniciaElemento(10);
    Elemento *elemento1 = iniciaElemento(15);
    Elemento *elemento2 = iniciaElemento(20);

    setPrimeiroElemento(bucket, elemento0);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento1);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento2);

    trocaElementoComPrimeiroElementoBucket(bucket, elemento1);

    int *vetor = alocaMemoriaVetorInteiros(3);
    copiaValoresDeUmaListaDeElementosParaUmVetor(vetor, getPrimeiroElemento(bucket), 0);


    int vetorEsperado[3] = {15, 10, 20};

    for (int indice = 0; indice < 3; indice++) {
        if (vetor[indice] != vetorEsperado[indice]) {
            printf(ANSI_COLOR_RED "testTrocaElementoComPrimeiroElementoBucketSeguidos(): FAIL" ANSI_DEFAULT "\n");
            return;
        }
    }

    printf(ANSI_COLOR_GREEN "testTrocaElementoComPrimeiroElementoBucketSeguidos(): SUCCESS" ANSI_DEFAULT "\n");
    free(vetor);
    free(bucket);
    free(elemento0);
    free(elemento1);
    free(elemento2);
}

void testTrocaElementoComPrimeiroElementoBucketElementosDistantes(){
    Bucket *bucket = iniciaBucket();
    Elemento *elemento0 = iniciaElemento(10);
    Elemento *elemento1 = iniciaElemento(15);
    Elemento *elemento2 = iniciaElemento(20);

    setPrimeiroElemento(bucket, elemento0);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento1);
    adicionaElementoNaUltimaPosicaoBucket(bucket, elemento2);

    trocaElementoComPrimeiroElementoBucket(bucket, elemento2);

    int *vetor = alocaMemoriaVetorInteiros(3);
    copiaValoresDeUmaListaDeElementosParaUmVetor(vetor, getPrimeiroElemento(bucket), 0);


    int vetorEsperado[3] = {20, 15, 10};

    for (int indice = 0; indice < 3; indice++) {
        if (vetor[indice] != vetorEsperado[indice]) {
            printf(ANSI_COLOR_RED "testTrocaElementoComPrimeiroElementoBucketSeguidos(): FAIL" ANSI_DEFAULT "\n");
            return;
        }
    }

    printf(ANSI_COLOR_GREEN "testTrocaElementoComPrimeiroElementoBucketSeguidos(): SUCCESS" ANSI_DEFAULT "\n");
    free(vetor);
    free(bucket);
    free(elemento0);
    free(elemento1);
    free(elemento2);
}

void imprimeResultadoTestBucket() {
    testIniciaBucket();
    testIniciaElemento();
    printf("\n");
    testBucketVazioTrue();
    testBucketVazioFalse();
    printf("\n");
    testAdicionaElementoNaUltimaPosicaoBucketTrueTamanhoEPosicao();
    testAdicionaElementoNaUltimaPosicaoBucketTrueAnterior();
    printf("\n");
    testAlocaMemoriaBucketsTrue();
    testAlocaMemoriaBucketsFalse();
    printf("\n");
    testIniciaBuckets();
    printf("\n");
    testCopiarValoresDeUmaListaDeElementosParaUmVetorOrdenado();
    testCopiarValoresDeUmaListaDeElementosParaUmVetorSemiOrdenado();
    printf("\n");
    testTrocaElementoComPrimeiroElementoBucketElementosSeguidos();
    testTrocaElementoComPrimeiroElementoBucketElementosDistantes();
}