#include "beben.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int k, n;

    cout << "k=";
    cin >> k;
    
    cout << "n=";
    cin >> n;

    Beben b(n);
    b.Wypelnij().Mieszaj().Wypisz(k);
    
    return 0;
}
