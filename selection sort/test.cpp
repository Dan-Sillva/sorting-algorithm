#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Danilo Araujo Silva
 *
 * Ordenação de vet[10] = 0.001 segundos
 *
 * Ordenação de vet[100] = 0.005 segundos
 * 
 * Ordenação de vet[1000] = 0.041 segundos
 * 
 * Ordenação de vet[10000] = 0.600 segundos
 * 
 * Ordenação de vet[100000] = 10.071 segundos
 * 
 * OBS : na ordenação de vet[100000], ordenei dois vetores de 40000 e um de 20000,
 * totalizando 100000, pois, o programa não executava com um vetor apenas,
 * de 100000 posições;
*/

int TAM = 40000; //variavel de controle do tamanho do vetor

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

    int tamanho_vetor = TAM;
    int vet[tamanho_vetor];

    fill_vector(TAM, tamanho_vetor, vet);
    selection_sort(tamanho_vetor, 0, vet);

    fill_vector(TAM, tamanho_vetor, vet);
    selection_sort(tamanho_vetor, 0, vet);

    fill_vector(20000, 20000, vet);
    selection_sort(tamanho_vetor, 0, vet);

    // print_vector(tamanho_vetor, vet);

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
