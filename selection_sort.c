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
void selectionSort(int *vetor, int numeroElementos) {
    int i, j, min, aux;

    for (i = 0; i < (numeroElementos-1); i++) {
        min = i;

        for (j = i+1; j < numeroElementos; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }

        if (vetor[i] != vetor[min]) {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}