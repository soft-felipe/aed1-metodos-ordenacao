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
#define QUANTIDADE_ALGORITMOS 6

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
        vetor[i] = rand() % 1000;
    }
    return vetor;
}

/**
 * @author Felipe Moreira
 * Metodo que retorna o tempo de ordenaçao em MILISSEGUNDOS, com a funçao clock da biblioteca 'time.h'
 * @param vetor Vetor que sera ordenado
 * @param tamanhoVetor Tamanho do vetor
 * @param algoritmo Codigo que identifica qual sera o algoritmo de ordenaçao
 * @return Tempo de execuçao em milissegundos
 */
double calculaTempoExecucao(int *vetor, int tamanhoVetor, int algoritmo) {
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
            mergeSort(vetor, tamanhoVetor);
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
    printf("+-----------------------------------------------------------------------+\n");
    printf("|                           TAMANHO DOS VETORES = %d                    |\n", tamanho);
    printf("+-----------------------------------------------------------------------+\n");
    printf("|      ALGORITMO      |    NUMERO DE VETORES    |    TEMPO MEDIO (ms)   |\n");
    printf("|    INSERTION SORT   |         %5.d           |         %.4f        |\n", NUMERO_VETORES,
               tempos[1]);
    printf("|    SELECTION SORT   |         %5.d           |         %.4f        |\n", NUMERO_VETORES,
               tempos[2]);
    printf("|    BUBBLE SORT      |         %5.d           |         %.4f        |\n", NUMERO_VETORES,
               tempos[3]);
    printf("|    MERGE SORT       |         %5.d           |         %.4f        |\n", NUMERO_VETORES,
               tempos[4]);
    printf("|    QUICK SORT       |         %5.d           |         %.4f        |\n", NUMERO_VETORES,
               tempos[5]);
    printf("|    COUNTING SORT    |         %5.d           |         %.4f        |\n", NUMERO_VETORES,
               tempos[6]);
    printf("|    RADIX SORT       |         %5.d           |         %.4f        |\n", NUMERO_VETORES,
               tempos[7]);
    printf("|    BUCKET SORT      |         %5.d           |         %.4f        |\n", NUMERO_VETORES,
               tempos[8]);
    printf("+-----------------------------------------------------------------------+\n");
}

/**
 * @author Felipe Moreira
 * @author Daniel Nogueira
 * Efetiva a produção do relatório de tempo de execução de cada algoritmo
 */
void geraResultados() {
    int escolheTamanho, escolheAlgoritmo;
    int casosTeste = 9;
    long int tamanhosPossiveis[] = {100, 1000, 5000, 10000, 20000, 50000, 75000, 100000, 200000};

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
            /* Montando os 50 vetores com valores aleatorios */
            int *vetor = gerarVetor(tamanhosPossiveis[escolheTamanho]);

            for (int indice = 1; indice <= QUANTIDADE_ALGORITMOS; indice++) {

                /* Copiando o vetor original (desornado) para um auxiliar,
                 * para garantir que sempre sera ordenado o mesmo vetor */
                int vetorAux[tamanhosPossiveis[escolheTamanho]];
                for (int j = 0; j < tamanhosPossiveis[escolheTamanho]; j++) {
                    vetorAux[j] = vetor[j];
                }

                /* Executando os 8 algoritmos de ordenacao */
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
                guardaTemposPorAlgoritmo[indice] += calculaTempoExecucao(vetorAux, tamanhosPossiveis[escolheTamanho], indice);
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
    mergeSort(vetor, 10);
    printf("Vetor ordenado: ");
    for (int indice = 0; indice < 10; indice++) {
        printf("%d ", vetor[indice]);
    }

    return 0;
}

