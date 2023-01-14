/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "metodos.h"

#define NUMERO_VETORES 50
#define QUANTIDADE_ALGORITMOS 8

/**
 * @author Daniel Nogueira
 * Gera vetores de inteiros aleatórios de acordo com o tamanho desejado
 * @param tamanho Tamanho do vetor a ser gerado
 * @return Vetor gerado
 */
int *gerarVetor(int tamanho) {
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }
    return vetor;
}

/**
 * @author Felipe Moreira
 * Metodo que retorna o tempo de ordenaçao em SEGUNDOS, com a funçao clock da biblioteca 'time.h'
 * @param vetor Vetor que sera ordenado
 * @param tamanhoVetor Tamanho do vetor
 * @param algoritmo Codigo que identifica qual sera o algoritmo de ordenaçao
 * @return Tempo de execuçao em segundos
 */
double calculaTempoExecucao(int *vetor, int tamanhoVetor, int algoritmo) {
    /* Codigo por algoritmo:
     * 1 - Insertion Sort
     * 2 - Selection Sort
     * 3 - Bubble Sort
     * 4 - Merge Sort
     * 5 - Quick Sort
     * 6 - Couting Sort
     * 7 - Radix Sort
     * 8 - Bucket Sort
     */

    clock_t t_ini, t_fim;
    switch (algoritmo) {
        case 1:
            t_ini = clock();
            insertionSort(vetor, tamanhoVetor);
            t_fim = clock();
            return (double) (t_fim - t_ini) / CLOCKS_PER_SEC * 1000;

        case 2:
            t_ini = clock();
            selectionSort(vetor, tamanhoVetor);
            t_fim = clock();
            return (double) (t_fim - t_ini) / CLOCKS_PER_SEC * 1000;

        case 3:
            t_ini = clock();
            bubbleSort(vetor, tamanhoVetor);
            t_fim = clock();
            return (double) (t_fim - t_ini) / CLOCKS_PER_SEC * 1000;

        case 4:
            t_ini = clock();
            mergeSort(vetor, 0, tamanhoVetor - 1);
            t_fim = clock();
            return (double) (t_fim - t_ini) / CLOCKS_PER_SEC * 1000;

        case 5:
            t_ini = clock();
            quickSort(vetor, 0, tamanhoVetor - 1);
            t_fim = clock();
            return (double) (t_fim - t_ini) / CLOCKS_PER_SEC * 1000;

        case 6:
            t_ini = clock();
            countingSort(vetor, tamanhoVetor);
            t_fim = clock();
            return (double) (t_fim - t_ini) / CLOCKS_PER_SEC * 1000;

        case 7:
            t_ini = clock();
            radixSort(vetor, tamanhoVetor);
            t_fim = clock();
            return (double) (t_fim - t_ini) / CLOCKS_PER_SEC * 1000;

        case 8:
            t_ini = clock();
            bucketSort(vetor, tamanhoVetor);
            t_fim = clock();
            return (double) (t_fim - t_ini) / CLOCKS_PER_SEC * 1000;
    }
}

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
    int i;

    printf("+-----------------------------------------------------------------------+\n"); // 71 -
    printf("|                           TAMANHO DOS VETORES = %d                    |", tamanho);
    printf("+-----------------------------------------------------------------------+\n"); // 71 -
    printf("|      ALGORITMO      |    NUMERO DE VETORES    |      TEMPO MÉDIO (ms)       |\n");
    printf("|    INSERTION SORT   |           %6.d          |           %f                |\n", NUMERO_VETORES,
               tempos[1]);
    printf("|    SELECTION SORT   |           %6.d          |           %f                |\n", NUMERO_VETORES,
               tempos[2]);
    printf("|    BUBBLE SORT      |           %6.d          |           %f                |\n", NUMERO_VETORES,
               tempos[3]);
    printf("|    MERGE SORT       |           %6.d          |           %f                |\n", NUMERO_VETORES,
               tempos[4]);
    printf("|    QUICK SORT       |           %6.d          |           %f                |\n", NUMERO_VETORES,
               tempos[5]);
    printf("|    COUNTING SORT    |           %6.d          |           %f                |\n", NUMERO_VETORES,
               tempos[6]);
    printf("|    RADIX SORT       |           %6.d          |           %f                |\n", NUMERO_VETORES,
               tempos[7]);
    printf("|    BUCKET SORT      |           %6.d          |           %f                |\n", NUMERO_VETORES,
               tempos[8]);
    printf("+-----------------------------------------------------------------------+\n"); // 71 -
}

/**
 * @author Felipe Moreira
 * @author Daniel Nogueira
 * Efetiva a produção do relatório de tempo de execução de cada algoritmo
 */
void geraResultados() {
    int escolheTamanho, escolheAlgoritmo;
    int casosTeste = 6;
    long int tamanhosPossiveis[] = {1000, 1000, 1000, 1000, 1000, 1000};

    double guardaTemposPorAlgoritmo[QUANTIDADE_ALGORITMOS + 1] = {0.0};

    for (escolheTamanho = 0; escolheTamanho < casosTeste; escolheTamanho++) {
        /* Tamanhos possiveis por codigo:
                * 0 - 100
                * 1 - 1000
                * 2 - 5000
                * 3 - 10000
                * 4 - 20000
                * 5 - 50000
                * 6 - 75000
                * 7 - 100000
                * 8 - 200000
            */
        for (int i = 0; i < NUMERO_VETORES; i++) {
            /* Montando os 50 vetores com valores aleatorios*/
            int *vetor = gerarVetor(tamanhosPossiveis[escolheTamanho]);
            for (int indice = 1; indice <= QUANTIDADE_ALGORITMOS; indice++) {
                /* Executando os 8 algoritmos de ordenacao*/
                /* Codigo por algoritmo:
                    * 1 - Insertion Sort
                    * 2 - Selection Sort
                    * 3 - Bubble Sort
                    * 4 - Merge Sort
                    * 5 - Quick Sort
                    * 6 - Couting Sort
                    * 7 - Radix Sort
                    * 8 - Bucket Sort
                */
                guardaTemposPorAlgoritmo[indice] += calculaTempoExecucao(vetor, tamanhosPossiveis[escolheTamanho], indice);
            }
        }
        imprimeResultadoPorTamanhoVetor(tamanhosPossiveis[escolheTamanho], guardaTemposPorAlgoritmo);
        for (escolheAlgoritmo = 1; escolheAlgoritmo <= QUANTIDADE_ALGORITMOS; escolheAlgoritmo++) {
            guardaTemposPorAlgoritmo[escolheAlgoritmo] = 0.0;
        }
    }
}

int main() {
    // Utilizando para teste local
    geraResultados();

    int *vetor = gerarVetor(10);
    printf("Vetor desordenado: ");
    for (int indice = 0; indice < 10; indice++) {
        printf("%d ", vetor[indice]);
    }
    printf("\n");
    selectionSort(vetor, 10);
    printf("Vetor ordenado: ");
    for (int indice = 0; indice < 10; indice++) {
        printf("%d ", vetor[indice]);
    }
    return 0;
}

