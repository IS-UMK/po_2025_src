#include "beben.h"
#include <stdio.h>


int main()
{
    struct beben *b;
    int k, n;

    printf("k="); scanf("%d", &k);
    printf("n="); scanf("%d", &n);
    
    b = utworz(n);
    wypisz(b, n);
    
    b = wypelnij(b);
    wypisz(b, n);

    b = mieszaj(b);
    wypisz(b, n);

    wypisz(b, k);

    wypisz(mieszaj(wypelnij(b)), k);

    zwolnij(b);

    return 0;
}