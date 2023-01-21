#include "test.h"
#include "utilitarios.h"
#include <stdio.h>
#include <stdlib.h>


#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void testMaiorElementoDesordenado() {
    int vetorDesordenado[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int maior = maiorElemento(vetorDesordenado, 10);
    if (maior != 9) {
        printf(ANSI_COLOR_RED "testMaiorElementoDesordenado(): FAIL\n\n" ANSI_DEFAULT, maior);
    } else {
        printf(ANSI_COLOR_GREEN "testMaiorElementoDesordenado: SUCCESS\n\n" ANSI_DEFAULT, maior);
    }
}

void testMaiorElementoOrdenado() {
    int vetorOrdenado[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int maior = maiorElemento(vetorOrdenado, 10);
    if (maior != 9) {
        printf(ANSI_COLOR_RED "testMaiorElementoOrdenado(): FAIL\n\n" ANSI_DEFAULT, maior);
    } else {
        printf(ANSI_COLOR_GREEN "testMaiorElementoOrdenado(): SUCCESS\n\n" ANSI_DEFAULT, maior);
    }
}



void showVetorAleatorioTest() {
    int *vetor = geraVetorAleatorio(10);
    printf("Vetor aleatorio de tamanho %d:\n", 10);
    printVetor(vetor, 10);
    free(vetor);
}


void imprimeResultadoTestUtilitarios() {
    testMaiorElementoDesordenado();
    testMaiorElementoOrdenado();
    showVetorAleatorioTest();
}