#include<stdio.h>
#include<stdlib.h>
#include <time.h>


/* PROTÓTIPOS */

// Função para fundir os arrays E e D em A
// esqCount = número de elementos de E
// dirCount = número de elementos em D
void Merge(int *A, int *E, int esqCount, int *D, int dirCount);

// Função recursiva para ordenar um array de inteiros
void MergeSort(int *A, int numeroElementos);


/* ONDE A MÁGICA ACONTECE */

int main() {

	int tamanho_vetor = 100; 
	int A[tamanho_vetor]; 
	int i, numeroElementos;

	clock_t tempo_execucao = clock();

	numeroElementos = sizeof(A)/sizeof(A[0]); 

	MergeSort(A, numeroElementos);

   // mostrando os elementos após ordenação
	for(i = 0; i < numeroElementos; i++){
		printf("%d ", A[i]);
	}

	// calculando tempo necessário para a execução do algoritmo
	tempo_execucao = clock() - tempo_execucao;

    printf("\n\nOrdenacao de vetor de %d posicoes;\n", tamanho_vetor);
	printf("\n\nTempo de execucao : %.7f segundos", ((double)tempo_execucao) / ((CLOCKS_PER_SEC)));

	return 0;
}


/* DECLARAÇÃO DAS FUNÇÕES */


void Merge(int *A, int *E, int esqCount, int *D, int dirCount) {
	int index_esq, index_dir, index_a;

   // index_esq - para marcar o index do subarray da esquerda (E)
   // index_dir - para marcar o index do subarray da direita (D)
   // index_a - para marcar o index do array de junção (A)

	index_esq = 0; index_dir = 0; index_a =0;

	while(index_esq < esqCount && index_dir < dirCount) {
		if(E[index_esq]  < D[index_dir]) A[index_a++] = E[index_esq++];
		else A[index_a++] = D[index_dir++];
	}

	while(index_esq < esqCount) A[index_a++] = E[index_esq++];
	while(index_dir < dirCount) A[index_a++] = D[index_dir++];
}


void MergeSort(int *A, int numeroElementos) {
	int meio, *E, *D, i;
	if(numeroElementos < 2) return; // Se o array tiver menos de dois elementos, não acontece nada

	meio = numeroElementos/2;
	

   // cria arrays da esquerda e direita
   // elementos do index 0 até meio-1 farão parte do array da esquerda
   // e elementos do meio até n-1 farão parte do array da direita
	E = (int*)malloc(meio*sizeof(int)); 
	D = (int*)malloc((numeroElementos - meio)*sizeof(int)); 
	

	for(i = 0; i < meio; i++) E[i] = A[i]; // cria o subarray da esquerda
	for(i = meio; i < numeroElementos; i++) D[i-meio] = A[i]; // cria o subarray da esquerda


	MergeSort(E, meio);  // ordenando subarray da esquerda
	MergeSort(D, numeroElementos -meio);  // ordenando subarray da direita
	Merge(A, E, meio, D, numeroElementos - meio);  // Fazendo o Merge de E e D em A, como uma lista ordenada
        free(E);
        free(D);
}