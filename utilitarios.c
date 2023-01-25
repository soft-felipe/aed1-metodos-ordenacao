/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <stdlib.h>
#include <time.h>
#include "utilitarios.h"
#include <stdio.h>
#include "metodos.h"
/*
 * Arquivo utilizado para armazenar métodos úteis para o desenvolvimento da aplicação
 */



/**
 * @author Daniel Nogueira
 * Aloca memória dinâmica oara um vetor de inteiros
 * @param tamanho Tamanho do vetor a ser alocado
 * @return Oendereço de um bloco de memória para inteiros
 */
int *alocaMemoriaVetorInteiros(int tamanho) {
    return (int *) malloc(tamanho * sizeof(int));
}

/**
 * @author Daniel Nogueira
 * Desaloca memória dinâmica de um vetor de inteiros
 * @param vetor Vetor a ser desalocado
 */
void liberaMemoria(int *vetor) {
    free(vetor);
}
/**
 * @author Daniel Nogueira
 * @referencia PARCIALMETE COPIADO: https://stackoverflow.com/questions/13802399/generate-a-random-array-in-c
 * @param tamanho Quantidade de elementos aleatórios a ser gerada
 * @return Um endereço de memória para um vetor de inteiros
 */
int *geraVetorAleatorio(int tamanho) {
    int *vetor = alocaMemoriaVetorInteiros(tamanho);

    /*
     * O método rand() gera números aleatórios a partir de uma seed (semente)
     * A seed é a base para gerar os números aleatórios, já que um computador
     * não gera números de fato aleatórios
     * O método srand() é utilizado para definir a seed
     * Então para os elementos
     *
    */
     srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }
    return vetor;
}

/**
 * @author Daniel Nogueira
 * Imprime um vetor de inteiros
 * @param vetor Vetor a ser imprimido
 * @param numeroElementos Numero de elementos do vetor
 * @return Retorna o número de elementos impressos
 */
int printVetor(int *vetor, int numeroElementos) {
    int count = 0;
    for (int i = 0; i < numeroElementos; i++) {
        printf("%d ", vetor[i]);
        count++;
    }
    printf("\n");

    return count;
}

/**
 * @author Daniel Nogueira
 * Fornece o maior valor de um vetor de inteiros
 * @param vetor Vetor a ser consultado
 * @param tamanho Tamanho do vetor a ser consultado
 * @return Retorna o maior valor do vetor fornecido
 */
int maiorElemento(int *vetor, int tamanho) {
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

/**
 * @author Daniel Nogueira
 * Esse método encapsula e aponta para os métodos que calculam o tempo de execução
 * dos algoritmos de ordenação
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Número de elementos do vetor
 * @param indice Indice do algoritmo a ser executado
 * @return Retorna o tempo em milisegundos da execução do algoritmo com o vetor fornecido
 */
double tempoDeExecucao(int *vetor, int numeroElementos, int indice) {
    double (*metodos[])(int *, int) = { insertionSortTime, selectionSortTime, bubbleSortTime, mergeSortTime, quickSortTime, countingSortTime, radixSortTime, bucketSortTime};
    return metodos[indice](vetor, numeroElementos);
}

void zeraArrayDouble(double *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = 0;
    }
}