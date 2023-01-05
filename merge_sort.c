/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

/**
 * @author Felipe Moreira
 * @param vetor Vetor a ser ordenado
 * @param inicio Primeira posiçao do vetor
 * @param meio Posiçao do meio do vetor
 * @param fim  Ultima posiçao do vetor
 */
void merge(int *vetor, int inicio, int meio, int fim);

/**
 * @author Felipe Moreira
 * @param vetor Vetor a ser ordenado
 * @param inicio Primeira posiçao do vetor
 * @param fim Ultima posiçao do vetor
 */
void merge_sort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = inicio, aux[(fim - inicio) + 1];

    while ((i <= meio) && (j <= fim)) {
        if (vetor[i] < vetor[j]) {
            aux[k] = vetor[i];
            i++;
        } else {
            aux[k] = vetor[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        aux[k] = vetor[i];
        i++;
        k++;
    }

    while (j <= fim) {
        aux[k] = vetor[j];
        j++;
        k++;
    }

    for (i = 0; i <= fim; i++) {
        vetor[i] = aux[i];
    }
}
