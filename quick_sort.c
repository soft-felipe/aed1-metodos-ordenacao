/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <time.h>
#include "metodos.h"

/**
 * @author Felipe Moreira
 * @referencia PARCIALMENTE COPIADO:
 *             Slides dos algoritmos de distribuiçao apresentados em sala
 *             Programaçao Descomplicada: Aula 52 - Quick Sort
 *             Link video aula: https://www.youtube.com/watch?v=spywQ2ix_Co&ab_channel=Programa%C3%A7%C3%A3oDescomplicada
 * Ordena um vetor de inteiros utilizando o método de ordenação Quick Sort
 * @param vetor Vetor a ser ordenado
 * @param inicio Primeira posiçao do vetor
 * @param fim Ultima posiçao do vetor
 */
void quickSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int q = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, q - 1);
        quickSort(vetor, q + 1, fim);
    }
}
/**
 * @author Felipe Moreira
 * @referencia PARCIALMENTE COPIADO:
 *             Slides dos algoritmos de distribuiçao apresentados em sala
 *             Programaçao Descomplicada: Aula 52 - Quick Sort
 *             Link video aula: https://www.youtube.com/watch?v=spywQ2ix_Co&ab_channel=Programa%C3%A7%C3%A3oDescomplicada
 * Divide um vetor em duas partes, uma com elementos menores que o pivo e outra com elementos maiores que o pivo
 * @param vetor Vetor a ser ordenado
 * @param inicio Primeira posiçao do vetor
 * @param fim Ultima posiçao do vetor
 */
int particiona(int *vetor, int inicio, int fim) {
    int esq = inicio;
    int dir = fim;
    int pivo = vetor[inicio];
    int aux;

    while (esq < dir) {

        while (vetor[esq] <= pivo) {
            esq++;
        }

        while (vetor[dir] > pivo) {
            dir--;
        }

        if (esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }

    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

/**
* @author Daniel Nogueira
 * Computa o tempo gasto pelo método de ordenação para ordenar um vetor de inteiros
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 * @return Tempo gasto para ordenar o vetor
 */
double quickSortTime(int *vetor, int numeroElementos) {
    clock_t startClock, endClock;
    double tempoGasto;
    startClock = clock();
    quickSort(vetor, 0,numeroElementos);
    endClock = clock();
    tempoGasto = ((double) (endClock - startClock)) / CLOCKS_PER_SEC * 1000;
    return tempoGasto;
}