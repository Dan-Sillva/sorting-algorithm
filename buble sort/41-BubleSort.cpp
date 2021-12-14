#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

void bubble_sort(int y[], int x) {
	int aux, troca=0;
	
	for (int i=1; i <= x-1; i++) {
		for (int j=0; j < x-1; j++) {
			if (y[j] > y[j+1]) {
				aux = y[j+1];
				y[j+1] = y[j];
				y[j] = aux;	
				troca++;
			}
		}
	}
}

void preencheVetor(int y[], int x) {
	srand(time(NULL));
	for (int i=0; i<x; i++) {
		y[i] = rand() % 100 + 1;
	}
}

void printVector(int y[], int x) {
	for (int i=0; i<x; i++) {
		printf("%3d |", y[i]);
	}
	printf("\n\n");
}


int main() {

	int vetor[TAM];
	preencheVetor(vetor, TAM);
	printVector(vetor, TAM);
	
	bubble_sort(vetor, TAM);
	printVector(vetor, TAM);

}

/*
							TESTES 

Quantidade = 10         Tempo = 0,31s; 0,05s; 0,03s; 0,03s; 0,03s;
Quantidade = 100        Tempo = 0,23s; 0,05s; 0,05s; 0,04s; 0,05s;
Quantidade = 1000       Tempo = 0,31s; 0,34s; 0,34s; 0,28s; 0,35s; 
Quantidade = 10000      Tempo = 2,27s; 2,13s; 2,08s; 2,08s; 2,05s;
Quantidade = 100000     Tempo = 122,2s; 122,2s; 69,38s; 63,16s; 68,1s

*/
