#include <stdio.h>

void selection_sort(int n, int vet[]);

int main()
{
    int vet[3];
    selection_sort(5, vet);
}

void selection_sort(int n, int vet[])
{

    for (int i = 1; i < n; i++)
    {
        n--;
    }
    printf("%d", n);
};