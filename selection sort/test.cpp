#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Danilo Araujo Silva
*/

using namespace std;

void selection_sort(int tamanho_vetor, int point, int *vet);
void fill_vector(int final, int tamanho_vetor, int *vet);

void print_vector(int tamanho_vetor, int vet[])
{
    for (int i = 0; i < tamanho_vetor; i++)
        printf("[%d]", vet[i]);
};

int main()
{
    clock_t time = clock();

    int tamanho_vetor = 10;
    int vet[tamanho_vetor];

    fill_vector(10, tamanho_vetor, vet);
    selection_sort(tamanho_vetor, 0, vet);

    print_vector(tamanho_vetor, vet);

    time = clock() - time;

    printf("\n\n-Ordenacao de vetor de %d posicoes;\n", tamanho_vetor);
    printf("-Tempo de execucao : %.7f segundos", ((double)time) / ((CLOCKS_PER_SEC)));
}

void fill_vector(int final, int tamanho_vetor, int *vet)
{
    srand(time(NULL));
    for (int i = 0; i < tamanho_vetor; i++)
    {
        vet[i] = rand() % final + 1;
    }
};

void selection_sort(int tamanho_vetor, int point, int *vet)
{
    if (point != tamanho_vetor)
    {
        for (int i = point; i < tamanho_vetor; i++)
        {
            if (vet[point] >= vet[i])
            {
                int aux;
                aux = vet[point];
                vet[point] = vet[i];
                vet[i] = aux;
            }
        }
        selection_sort(tamanho_vetor, point + 1, vet);
    }
};