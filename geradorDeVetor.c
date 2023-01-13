/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_VETORES 50

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

    // ESTUDAR COMO FAZER ISSO
    // Pra isso aqui acontecer de maneira mais simples com os codigos separados, acho que
    // devemos criar um novo .h do tipo implementacoes.h que contenham as assinaturas de
    // todos os metodos, e que se definam pelos arquivos .c que ja temos

    clock_t t_ini, t_fim;
    switch (algoritmo) {
        case 1:
            t_ini = clock();
            // chama algoritmo passando vetor e tamanho
//            insertion_sort(vetor, tamanhoVetor);
            t_fim = clock();
            return (double)(t_fim -  t_ini);
        case 2:
            t_ini = clock();
            t_fim = clock();
            return (double)(t_fim -  t_ini);
        case 3:
            t_ini = clock();
            t_fim = clock();
            return (double)(t_fim -  t_ini);
        case 4:
            t_ini = clock();
            t_fim = clock();
            return (double)(t_fim -  t_ini);
        case 5:
            t_ini = clock();
            t_fim = clock();
            return (double)(t_fim -  t_ini);
        case 6:
            t_ini = clock();
            // chama algoritmo passando vetor e tamanho
//            insertion_sort(vetor, tamanhoVetor);
            t_fim = clock();
            return (double)(t_fim -  t_ini);
    }
}

void imprimeResultadoPorAlgoritmo(int algoritmo, long int *tamanhos, long int *tempos, int casosTeste) {
    int i;

    printf("+-----------------------------------------------------------------------+\n"); // 71 -
    if (algoritmo == 1) {
        printf("|                             INSERTION SORT                            |\n");
    } else if (algoritmo == 2) {
        printf("|                             SELECTION SORT                            |\n");
    } else if (algoritmo == 3) {
        printf("|                               BUBBLE SORT                             |\n");
    } else if (algoritmo == 4) {
        printf("|                               MERGE SORT                              |\n");
    } else if (algoritmo == 5) {
        printf("|                               QUICK SORT                              |\n");
    } else if (algoritmo == 6) {
        printf("|                              COUNTING SORT                            |\n");
    } else if (algoritmo == 7) {
        printf("|                               RADIX SORT                              |\n");
    } else if (algoritmo == 8) {
        printf("|                               BUCKET SORT                             |\n");
    }
    printf("+-----------------------------------------------------------------------+\n"); // 71 -

    printf("|  Numero de vetores   |    Tamanho  |      Tempo aproximado (ms)       |\n");
    for (i = 0; i < casosTeste; i++) {
        printf("|         %d           |   %6d    |           %11.6f            |\n", 50, tamanhos[i], tempos[i] / ((double)NUMERO_VETORES * 1.0)); // arrumar tempo pra ms
    }
    printf("+-----------------------------------------------------------------------+\n"); // 71 -
}

/**
 * @author Felipe Moreira
 * Metodo principal que sera chamado por mostrar a tabela do PDF.
 */
void geraResultados() {
    int i, incrementaTamanho, escolheAlgoritmo;

    long int tamanhosPossiveis[6] = {100, 1000, 10000, 100000, 1000000, 10000000};
    int casosTeste = 6;

    long acumuloTempoExecucao = 0.0;
    long guardaTemposPorTamanho[casosTeste];

    for (escolheAlgoritmo = 1; escolheAlgoritmo <= 8; escolheAlgoritmo++) {
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
        for (incrementaTamanho = 0; incrementaTamanho < casosTeste; incrementaTamanho++) {
            /* Tamanhos possiveis por codigo:
                * 0 - 100
                * 1 - 1000
                * 2 - 10000
                * 3 - 100000
                * 4 - 1000000
                * 5 - 10000000 (Acho que aqui quebra por tamanho)
                * 6 - aqui entao... (testar)
            */
            for (i = 0; i < NUMERO_VETORES; i++) {
                /* Montando os 50 vetores com valores aleatorios e ordenando */
                int *vetor = gerarVetor(tamanhosPossiveis[incrementaTamanho]);
                long int tempo = calculaTempoExecucao(vetor, tamanhosPossiveis[incrementaTamanho],
                                                    escolheAlgoritmo);
                acumuloTempoExecucao += tempo;
            }
            // Armazenar a soma dos tempos por tamanho
            guardaTemposPorTamanho[incrementaTamanho] = acumuloTempoExecucao;
            acumuloTempoExecucao = 0.0;
        }
        imprimeResultadoPorAlgoritmo(escolheAlgoritmo, tamanhosPossiveis, guardaTemposPorTamanho, casosTeste);
        // acho que nao precisa zerar o vetor 'guardaTemposPorTamanho'
    }
}

int main() {
    // Utilizando para teste local
    int *vetor = gerarVetor(10);
    for (int indice = 0; indice < 10; indice++) {
        printf("%d  ", vetor[indice]);
    }

    return 0;
}

