/*
 * Alunos:
 *  Felipe Moreira - 202105027
 *  Daniel Nogueira - 202105024
 *  Norton Almeida - 202203526
 */

/**
 * @author Felipe Moreira
 * @param vetor Vetor a ser procurado o pivo
 * @param inicio Primeira posiçao do vetor
 * @param fim Ultima posiçao do vetor
 * @return Pivo
 */
int particiona(int *vetor, int inicio, int fim);

/**
 * @author Felipe Moreira
 * @param vetor Vetor a ser ordenado
 * @param inicio Primeira posiçao do vetor
 * @param fim Ultima posiçao do vetor
 */
void quick_sort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int q = particiona(vetor, inicio, fim);
        quick_sort(vetor, inicio, q - 1);
        quick_sort(vetor, q + 1, fim);
    }
}

int particiona(int *vetor, int inicio, int fim) {
    int esq = inicio, dir = fim, pivo = vetor[inicio], aux;

    while (esq < dir) {

        while (vetor[esq] <= pivo) {
            esq++;
        }

        while (vetor[dir] > pivo) {
            dir--;
        }

        if (esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }

    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}