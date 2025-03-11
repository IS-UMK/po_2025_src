#include "beben.h"
#include <iostream>
#include <cstdlib>

Beben::Beben(int n)
{
    opis = "Beben stworzony";
    rozmiar = n;
    kule = new int[n];
 }

Beben& Beben::Wypelnij()
{
    for (int i = 0; i < rozmiar; i++) kule[i] = i+1;
    opis = "Beben wypelniony";
    return *this;
}

Beben& Beben::Mieszaj()
{
    for (int i = 0; i < this->rozmiar; i++)
    {
        int k = rand() % rozmiar;
        int tmp = kule[i];
        kule[i] = kule[k];
        kule[k] = tmp;
    }

    opis = "Beben wymieszany";
    return *this;
}

void Beben::Wypisz(int n)
{
    int i;

    cout << "Opis: " << opis << endl ;
    cout << "Rozmiar: " << rozmiar << endl;
    for (i = 0; i < n; i++) cout << kule[i] << " ";
    cout << endl;
}

Beben::~Beben()
{
  //  cout << "Dziala destruktor" << endl;
    if (kule != nullptr)
    {
        delete[] this->kule;
        kule = nullptr;
    }
    rozmiar = 0;
}