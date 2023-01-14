/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */
#include "metodos.h"

/**
 * @author Felipe Moreira
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
 * Divide um vetor em duas partes, uma com elementos menores que o pivo e outra com elementos maiores que o pivo
 * @param vetor Vetor a ser ordenado
 * @param inicio Primeira posiçao do vetor
 * @param fim Ultima posiçao do vetor
 */
int particiona(int *vetor, int inicio, int fim) {
    int esq = inicio, dir = fim, pivo = vetor[inicio], aux;

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