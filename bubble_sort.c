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
void bubbleSort(int *vetor, int numeroElementos) {
    int i, fim, aux;
    for (fim = numeroElementos-1; fim > 0; fim--) {
        for (i = 0; i < fim; i++) {
            if (vetor[i] > vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}