/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilitarios.h"
#define NUMERO_VETORES 40
#define QUANTIDADE_ALGORITMOS 8


/**
 * @author Felipe Moreira
 * @author Daniel Nogueira
 * Imprime na linha de comandos o relatório de tempo de execução de cada algoritmo
 * @param tamanho Tamanho do vetor que foi ordenado
 * @param tempos Vetor que armazena os tempos de ordenação de todos os algoritmos
 * de acordo com o tamanho do vetor
 * @param algoritmo Identificador do algoritmo
 */
void imprimeResultadoPorTamanhoVetor(int tamanho, double *tempos) {
    printf("+-------------------------------------------------------------------------------------+\n");
    printf("|                             TAMANHO DOS VETORES  = %6d                           |\n", tamanho);
    printf("+-------------------------------------------------------------------------------------+\n");
    printf("|      ALGORITMO      |    N  DE VETORES    |   TEMPO TOTAL (ms)  |  TEMPO MEDIO (ms) |\n");
    printf("|    INSERTION SORT   |      %5.d          |   %15.6f   |     %12.6f  |\n", NUMERO_VETORES,
           tempos[0], (tempos[0] / (NUMERO_VETORES * 1.0)));
    printf("|    SELECTION SORT   |      %5.d          |   %15.6f   |     %12.6f  |\n", NUMERO_VETORES,
           tempos[1], (tempos[1] / (NUMERO_VETORES * 1.0)));
    printf("|    BUBBLE SORT      |      %5.d          |   %15.6f   |     %12.6f  |\n", NUMERO_VETORES,
           tempos[2], (tempos[2] / (NUMERO_VETORES * 1.0)));
    printf("|    MERGE SORT       |      %5.d          |   %15.6f   |     %12.6f  |\n", NUMERO_VETORES,
           tempos[3], (tempos[3] / (NUMERO_VETORES * 1.0)));
    printf("|    QUICK SORT       |      %5.d          |   %15.6f   |     %12.6f  |\n", NUMERO_VETORES,
           tempos[4], (tempos[4] / (NUMERO_VETORES * 1.0)));
    printf("|    COUNTING SORT    |      %5.d          |   %15.6f   |     %12.6f  |\n", NUMERO_VETORES,
           tempos[5], (tempos[5] / (NUMERO_VETORES * 1.0)));
    printf("|    RADIX SORT       |      %5.d          |   %15.6f   |     %12.6f  |\n", NUMERO_VETORES,
           tempos[6], (tempos[6] / (NUMERO_VETORES * 1.0)));
    printf("|    BUCKET SORT      |      %5.d          |   %15.6f   |     %12.6f  |\n", NUMERO_VETORES,
           tempos[7], (tempos[7] / (NUMERO_VETORES * 1.0)));
    printf("+-------------------------------------------------------------------------------------+\n\n");
}

/**
 * @author Felipe Moreira
 * @author Daniel Nogueira
 * Efetiva a produção do relatório de tempo de execução de cada algoritmo
 */
void geraResultados() {
    int escolheTamanho;
    int casosTeste = 8;
    long int tamanhosPossiveis[] = {100,  1000, 10000, 15000, 30000, 50000, 75000, 100000};

    double guardaTemposPorAlgoritmo[QUANTIDADE_ALGORITMOS] = {0.0};

    for (escolheTamanho = 0; escolheTamanho < casosTeste; escolheTamanho++) {

        /* Montando os 50 vetores com valores aleatorios */
        for (int i = 0; i < NUMERO_VETORES; i++) {
            int *vetor = geraVetorAleatorio(tamanhosPossiveis[escolheTamanho]);

            /* Executando os 8 algoritmos de ordenacao */
            for (int indice = 0; indice < QUANTIDADE_ALGORITMOS; indice++) {

                /* Copiando o vetor original (desornado) para um auxiliar,
                 * para garantir que sempre sera ordenado o mesmo vetor */
                int *vetorAux = alocaMemoriaVetorInteiros(tamanhosPossiveis[escolheTamanho]);

                memcpy(vetorAux, vetor, tamanhosPossiveis[escolheTamanho] * sizeof(int));
                /* Codigo por algoritmo:
                    * 0 - Insertion Sort
                    * 1 - Selection Sort
                    * 2 - Bubble Sort
                    * 3 - Merge Sort
                    * 4 - Quick Sort
                    * 5 - Counting Sort
                    * 6 - Radix Sort
                    * 7 - Bucket Sort
                */
                guardaTemposPorAlgoritmo[indice] += tempoDeExecucao(vetorAux, tamanhosPossiveis[escolheTamanho], indice);
                free(vetorAux);
            }
            free(vetor);
        }

        imprimeResultadoPorTamanhoVetor(tamanhosPossiveis[escolheTamanho], guardaTemposPorAlgoritmo);
        zeraArrayDouble(guardaTemposPorAlgoritmo, QUANTIDADE_ALGORITMOS);
    }
}

int main() {
    geraResultados();
    return 0;
}

