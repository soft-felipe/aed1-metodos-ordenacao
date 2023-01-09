/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

#include <stdlib.h>

/**
 * @author Daniel Nogueira
 * Gera vetores de inteiros aleatórios de acordo com o tamanho desejado
 * @param tamanho Tamanho do vetor a ser gerado
 */

    int *gerarVetor(int tamanho) {
        int *vetor = (int *) malloc(tamanho * sizeof(int));
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = srand(time(NULL));
        }
        return vetor;
    }
