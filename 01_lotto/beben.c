#include "beben.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct beben *utworz(int n)
{
    struct beben *b = (struct beben*)malloc(sizeof(struct beben));
    if(!b) return NULL;

    b->opis = "Beben stworzony";
    b->kule = (int*)malloc(n * sizeof(n));
    if(b->kule) b->rozmiar = n;
    else b->rozmiar = 0;
    
    srand(time(NULL));
    
    return b;
}

struct beben *wypelnij(struct beben *b)
{
    int i;
    for ( i = 0; i < b->rozmiar; i++) b->kule[i] = i+1;
    b->opis = "Beben wypelniony";
    return b;
}

struct beben *mieszaj(struct beben *b)
{
    int i, k;
    int tmp;
    for ( i = 0; i < b->rozmiar; i++)
    {
        k = rand() % b->rozmiar;
        tmp = b->kule[i];
        b->kule[i] = b->kule[k];
        b->kule[k] = tmp;
    }

    b->opis = "Beben wymieszany";

    return b;
}

void wypisz(struct beben *b, int n)
{
    int i;
    printf("%s\nn=%d\n", b->opis, b->rozmiar);
    for ( i = 0; i < n; i++) printf("%d ", b->kule[i]);
    printf("\n");
}

void zwolnij(struct beben *b)
{
    free(b->kule);
    free(b);
}