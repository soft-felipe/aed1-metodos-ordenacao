#include "metodos.h"
#include "stdio.h"
#include "stdlib.h"
#include "test.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

/**
 * @author Daniel Nogueira
 * Classe utilizada para testar os algoritmos de ordenaçao
 * Testes feitos com vetores ordenados, desordenados e aleatorios
 * Testamos todos os 8 algoritmos de ordenaçao com os vetores criados
 * Se ordenar com sucesso imprimos a mensagem 'SUCESS' em verde,
 * caso contrario a mensagem 'FAIL' em vermelho.
 */

/* Realiza o teste com vetor desordenado */
int testDesordenado(int algoritmo) {
    int vetorDesordenado[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        switch (algoritmo) {
            case 1:
                insertionSort(vetorDesordenado, 10);
                break;
            case 2:
                selectionSort(vetorDesordenado, 10);
                break;
            case 3:
                bubbleSort(vetorDesordenado, 10);
                break;
            case 4:
                mergeSort(vetorDesordenado, 0, 10);
                break;
            case 5:
                quickSort(vetorDesordenado, 0, 10);
                break;
            case 6:
                countingSort(vetorDesordenado, 10);
                break;
            case 7:
                radixSort(vetorDesordenado, 10);
                break;
            case 8:
                bucketSort(vetorDesordenado, 10);
                break;
    }

    for (int i = 0; i < 10; i++) {
        if (vetorDesordenado[i] != i) {
            return algoritmo;
        }
    }

    return 0;
}

/* Realiza o teste com vetor ordenado */
int testOrdenado(int algoritmo) {
    int vetor[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        switch (algoritmo) {
            case 1:
                insertionSort(vetor, 10);
                break;
            case 2:
                selectionSort(vetor, 10);
                break;
            case 3:
                bubbleSort(vetor, 10);
                break;
            case 4:
                mergeSort(vetor, 0, 10);
                break;
            case 5:
                quickSort(vetor,0, 10);
                break;
            case 6:
                countingSort(vetor, 10);
                break;
            case 7:
                radixSort(vetor, 10);
                break;
            case 8:
                bucketSort(vetor, 10);
                break;

    }

    for (int i = 0; i < 10; i++) {
        if (vetor[i] != i) {
            return algoritmo;
        }
    }

    return 0;
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

/* Realiza o teste com vetor aleatorio */
int testRandom(int algoritmo) {
    int vetor[10];
    for (int indice = 0; indice < 10; indice++) {
        vetor[indice] = rand() % 10;
    }

    switch (algoritmo) {
        case 1:
            insertionSort(vetor, 10);
            break;
        case 2:
            selectionSort(vetor, 10);
            break;
        case 3:
            bubbleSort(vetor, 10);
            break;
        case 4:
            mergeSort(vetor, 0, 10);
            break;
        case 5:
            quickSort(vetor, 0, 10);
            break;
        case 6:
            countingSort(vetor, 10);
            break;
        case 7:
            radixSort(vetor, 10);
            break;
        case 8:
            bucketSort(vetor, 10);
            break;

    }
    qsort(vetor, 10, sizeof(int), cmpfunc);

    for (int indice = 0; indice < 9; indice++) {
        if (vetor[indice] > vetor[indice + 1]) {
            return algoritmo;
        }
    }

    return 0;
}

void mapeiaAlgoritmos() {
    printf("Codigos por Algoritmo de Ordenaçao:\n");
    printf("0 - INSERTION SORT\n");
    printf("1 - SELECTION SORT\n");
    printf("2 - BUBBLE SORT\n");
    printf("3 - MERGE SORT\n");
    printf("4 - QUICK SORT\n");
    printf("5 - COUNTING SORT\n");
    printf("6 - RADIX SORT\n");
    printf("7 - BUCKET SORT\n\n");
}

/* Imprime os resultados dos testes com os algoritmos */
void imprimeResultadoTestMetodos() {
    int algoritmo = 1;
    int resultado = 0;

    mapeiaAlgoritmos();

    while (algoritmo <= 8) {
        resultado = testDesordenado(algoritmo);
        if (resultado != 0) {
            printf(ANSI_COLOR_RED "testDesordenado() algoritmo %d: FAIL\n" ANSI_DEFAULT, resultado);
        } else {
            printf(ANSI_COLOR_GREEN "testDesordenado() algoritmo %d : SUCCESS\n" ANSI_DEFAULT, algoritmo);
        }

        resultado = testOrdenado(algoritmo);
        if (resultado != 0) {
            printf(ANSI_COLOR_RED "testOrdenado() algoritmo %d: FAIL\n" ANSI_DEFAULT, resultado);
        } else {
            printf(ANSI_COLOR_GREEN "testOrdenado() algoritmo %d: SUCCESS\n" ANSI_DEFAULT, algoritmo);
        }

        resultado = testRandom(algoritmo);
        if (resultado != 0) {
            printf(ANSI_COLOR_RED "testRandom() algoritmo %d: FAIL\n" ANSI_DEFAULT, resultado);
        } else {
            printf(ANSI_COLOR_GREEN "testRandom() algoritmo %d: SUCCESS\n\n" ANSI_DEFAULT, algoritmo);
        }
        algoritmo++;
    }
}
