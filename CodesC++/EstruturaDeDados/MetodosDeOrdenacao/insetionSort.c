#include <stdio.h>
#include <stdlib.h>

void insertionSort(int vetor[], int tam) {
	int i, j, aux;

	for (i = 1; i < tam; i++) {
		aux = vetor[i];
		j = i - 1;

		while ((j >= 0) && (aux < vetor[j])) {
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}

		vetor[j + 1] = aux;
	}

}