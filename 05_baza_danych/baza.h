#ifndef BAZA_H
#define BAZA_H

#include "osoba.h"
#include <iostream>

using namespace std;

class Baza 
{

	private:
		Osoba* osoby;
		int rozmiar;
		int ile_elementow;

	public:
		static const int ROZMIAR_DOMYSLNY = 100;

		Baza(int rozmiar = Baza::ROZMIAR_DOMYSLNY) :ile_elementow{ 0 },
			rozmiar{ rozmiar }, osoby{ new Osoba[rozmiar] } 
		{  }

		Baza& Dodaj(const Osoba& osoba);
		friend ostream& operator<<(ostream& o, const Baza& b);
		
		~Baza();
};

#endif

