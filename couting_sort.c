/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

/**
 * @author Felipe Moreira
 * @param vetor Vetor a ser ordenado
 * @param numeroElementos Tamanho do vetor
 */
void couting_sort(int *vetor, int numeroElementos) {
    int i, j, k, max = 0;

    for (i = 0; i < numeroElementos; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }

    int aux[max + 1];
    for (i = 0; i <= max; i++) {
        aux[i] = 0;
    }

    for (i = 0; i < numeroElementos; i++) {
        aux[vetor[i]]++;
    }

    for (i = 0, j = 0; j <= max; j++) {
        for (k = aux[j]; k > 0; k--) {
            vetor[i] = j;
            i++;
        }
    }
}