#ifndef BAZA_H
#define BAZA_H

#include "osoba.h"
#include <iostream>
#include <fstream>

#define DOMYSLNA_NAZWA "baza.txt"

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

		Baza(const Baza& baza);
		Baza& operator=(const Baza& baza);

		Baza& Dodaj(const Osoba& osoba);
		friend ostream& operator<<(ostream& o, const Baza& b);
		
		void Zapisz(const char* nazwa=DOMYSLNA_NAZWA) const;
		Baza& Wczytaj(const char* nazwa = DOMYSLNA_NAZWA);

		~Baza();
};

#endif

