#include<stdio.h>
#include<stdlib.h>

/* PROTÓTIPOS */

// Função para fundir os arrays E e D em A
// esqCount = número de elementos de E
// dirCount = número de elementos em D
void Merge(int *A, int *E, int esqCount, int *D, int dirCount);

// Função recursiva para ordenar um array de inteiros
void MergeSort(int *A, int n);


/* ONDE A MÁGICA ACONTECE */

int main() {

	int A[] = {7,3,4,2,10,11,16,14,13,18}; // criando um array com inteiros
	int i, numeroElementos;

   // encontrando o numero de elementos - tamanho do array inteiro em bytes dividido pelo tamanho de um elemento inteiro em bytes
	numeroElementos = sizeof(A)/sizeof(A[0]); 

	MergeSort(A, numeroElementos);

   // mostrando os elementos após ordenação
	for(i = 0; i < numeroElementos; i++) printf("%d ", A[i]);
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


void MergeSort(int *A, int n) {
	int meio, *E, *D;
	if(n < 2) return; // Se o array tiver menos de dois elementos, não acontece nada

	meio = n/2;  // encontrar o index do meio
	
   // cria arrays da esquerda e direita
   // elementos do index 0 até meio-1 farão parte do array da esquerda
   // e elementos do meio até n-1 farão parte do array da direita

	E = (int*)malloc(meio*sizeof(int)); 
	D = (int*)malloc((n- meio)*sizeof(int)); 
	
	for(int i = 0; i < meio; i++) E[i] = A[i]; // cria o subarray da esquerda
	for(int i = meio; i < n; i++) D[i-meio] = A[i]; // cria o subarray da esquerda

	MergeSort(E, meio);  // ordenando subarray da esquerda
	MergeSort(D, n-meio);  // ordenando subarray da direita
	Merge(A, E, meio, D, n-meio);  // Fazendo o Merge de E e D em A, como uma lista ordenada
        free(E);
        free(D);
}