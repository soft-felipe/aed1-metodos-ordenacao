/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include "test.h"
#include "utilitarios.h"
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

/**
 * @author Daniel Nogueira
 * Testa o método zeraArrayDouble()
 */
void testZeraArrayDouble() {
    double array[5] = {1, 2, 3, 4, 5};
    zeraArrayDouble(array, 5);
    for (int i = 0; i < 5; i++) {
        if (array[i] != 0) {
            printf(ANSI_COLOR_RED "testZeraArrayDouble(): FAIL\n" ANSI_DEFAULT);
        }
    }
    printf(ANSI_COLOR_GREEN "testZeraArrayDouble(): SUCCESS\n" ANSI_DEFAULT);
}


/**
 * @author Daniel Nogueira
 * Testa o método maiorElemento() com um vetor ordenado
 */
void testMaiorElementoDesordenado() {
    int vetorDesordenado[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int maior = maiorElemento(vetorDesordenado, 10);
    if (maior != 9) {
        printf(ANSI_COLOR_RED "testMaiorElementoDesordenado(): FAIL\n" ANSI_DEFAULT, maior);
    } else {
        printf(ANSI_COLOR_GREEN "testMaiorElementoDesordenado: SUCCESS\n" ANSI_DEFAULT, maior);
    }
}

/**
 * @author Daniel Nogueira
 * Testa o método maiorElemento() com um vetor desordenado
 */
void testMaiorElementoOrdenado() {
    int vetorOrdenado[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int maior = maiorElemento(vetorOrdenado, 10);
    if (maior != 9) {
        printf(ANSI_COLOR_RED "testMaiorElementoOrdenado(): FAIL\n\n" ANSI_DEFAULT, maior);
    } else {
        printf(ANSI_COLOR_GREEN "testMaiorElementoOrdenado(): SUCCESS\n\n" ANSI_DEFAULT, maior);
    }
}


/**
 * @author Daniel Nogueira
 * Método que chama todos os métodos de teste
 */
void imprimeResultadoTestUtilitarios() {
    testZeraArrayDouble();
    testMaiorElementoDesordenado();
    testMaiorElementoOrdenado();
}