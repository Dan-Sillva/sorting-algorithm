/*  TENTATIVAS REGISTRADAS - Ana Karen Soares Fonseca
*  Insertion sort 
*    Vetor 10:
* 1 tentativa: 1,19s
* 2 tentativa: 0,28s
* 3 tentativa: 0,28s
* 4 tentativa: 0,24s
* 5 tentativa: 0,23s
*
*   Vetor 100:
* 1 tentativa: 0,23s
* 2 tentativa: 0,24s
* 3 tentativa: 0,23s
* 4 tentativa: 0,24s
* 5 tentativa: 0,23s
*
*   Vetor 1000:
* 1 tentativa: 0,24s
* 2 tentativa: 0,23s
* 3 tentativa: 0,23s
* 4 tentativa: 0,25s
* 5 tentativa: 0,28s
*
*   Vetor 10000:
* 1 tentativa: 0,23s
* 2 tentativa: 0,24s
* 3 tentativa: 0,23s
* 4 tentativa: 0,24s
* 5 tentativa: 0,25s
*
*   Vetor 100000
* 1 tentativa: 0,24s
* 2 tentativa: 0,24s
* 3 tentativa: 0,27s
* 4 tentativa: 0,28s
* 5 tentativa: 0,25s
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100 // Definicao manual do número de vetores

void fInsertion_Sort(int *pontVetor);

int main()
{
    int vetor[TAM];
    int aux;

    srand(time(NULL));
    
    for (aux=0; aux < TAM; aux++)
    {
        vetor[aux] = (rand() % 90) + 10;
        printf(" %d,",vetor[aux]);
    }

    fInsertion_Sort(vetor); 

    printf("\n\n");
    
    for (aux=0; aux < TAM; aux++)
    {
        printf(" %d,",vetor[aux]);
    }

    printf("\n\n ");
    system("pause");
}

void fInsertion_Sort(int *pontVetor)
{
    int aux;
    int temp;
    int aux2;

    for (aux=1; aux < TAM; aux++) 
    {
        temp = aux;

        while (pontVetor[temp] < pontVetor[temp-1])
        { 
            aux2          = pontVetor[temp];
            pontVetor[temp]   = pontVetor[temp-1];
            pontVetor[temp-1] = aux2;
            temp--; 

            if (temp == 0)
                break;
        }

    }
}
