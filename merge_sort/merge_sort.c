/*
* José Antonio de Andrade Siqueira - 2010072
*
 * Ordenacao de vet[10] = 0.0000001 segundos
 *
 * Ordenacao de vet[100] = 0.0032000 segundos
 * 
 * Ordenacao de vet[1000] = 0.03440000 segundos
 * 
 * Ordenacao de vet[10000] = 0.4200000 segundos
 * 
 * Ordenacao de vet[100000] = 3.2861000 segundos
*/


#include<stdio.h>
#include<stdlib.h>
#include <time.h>


/* PROTÓTIPOS */

// Função para fundir os arrays E e D em A
// esqCount = número de elementos de E
// dirCount = número de elementos em D
void Merge(int *A, int *E, int esqCount, int *D, int dirCount);

// Função recursiva para ordenar um array de inteiros
void MergeSort(int *A, int numero_elementos);

void preencher_vetor(int tamanho_vetor, int *A);

/* ONDE A MÁGICA ACONTECE */

int tamanho_vetor = 100000; 


int main() {

	int A[tamanho_vetor]; 
	int i, numero_elementos;

	clock_t tempo_execucao = clock();

	numero_elementos = sizeof(A)/sizeof(A[0]); 

	preencher_vetor(tamanho_vetor, A);
	MergeSort(A, numero_elementos);

   // mostrando os elementos após ordenação
	for(i = 0; i < numero_elementos; i++){
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


void MergeSort(int *A, int numero_elementos) {
	int meio, *E, *D, i;
	if(numero_elementos < 2) return; // Se o array tiver menos de dois elementos, não acontece nada

	meio = numero_elementos/2;
	

   // cria arrays da esquerda e direita
   // elementos do index 0 até meio-1 farão parte do array da esquerda
   // e elementos do meio até n-1 farão parte do array da direita
	E = (int*)malloc(meio*sizeof(int)); 
	D = (int*)malloc((numero_elementos - meio)*sizeof(int)); 
	

	for(i = 0; i < meio; i++) E[i] = A[i]; // cria o subarray da esquerda
	for(i = meio; i < numero_elementos; i++) D[i-meio] = A[i]; // cria o subarray da esquerda


	MergeSort(E, meio);  // ordenando subarray da esquerda
	MergeSort(D, numero_elementos -meio);  // ordenando subarray da direita
	Merge(A, E, meio, D, numero_elementos - meio);  // Fazendo o Merge de E e D em A, como uma lista ordenada
        free(E);
        free(D);
}

void preencher_vetor(int tamanho_vetor, int *A)
{
	int valor_final = tamanho_vetor + 1;

    srand(time(NULL));
    for (int i = 0; i < tamanho_vetor; i++)
    {
        A[i] = rand() % valor_final;
    }
};