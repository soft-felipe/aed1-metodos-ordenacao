#ifndef UTILITARIOS_H
#define UTILITARIOS_H

void printVetor(int *vetor, int numeroElementos);

int *geraVetorAleatorio(int numeroElementos);

int *alocaMemoriaVetorInteiros(int tamanho);

void liberaMemoria(int *vetor);

int maiorElemento(int *vetor, int tamanho);

double tempoDeExecucao(int *vetor, int numeroElementos, int indice);

void zeraArrayDouble(double *array, int tamanho);
#endif //UTILITARIOS_H