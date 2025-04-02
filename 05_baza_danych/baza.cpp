#include "baza.h"

Baza& Baza::Dodaj(const Osoba& osoba)
{
	if (rozmiar == ile_elementow)
	{
		rozmiar = rozmiar * 2;
		Osoba* nowa = new Osoba[rozmiar];
		for (int i = 0; i < ile_elementow; i++)
		{
			nowa[i] = osoby[i];
		}
		delete[] osoby;
		osoby = nowa;
	}

	osoby[ile_elementow] = osoba;
	ile_elementow++;
	return *this;
}

Baza::~Baza()
{
	if (!osoby)
	{
		delete [] osoby;
		osoby = nullptr;
	}
	rozmiar = 0;
	ile_elementow = 0;
}

ostream& operator<<(ostream& o, const Baza& b)
{
	o << "Rozmiar: " << b.ile_elementow <<  endl;
	o << "Ile elementow: " << b.ile_elementow << endl;
	
	for (int i = 0; i < b.ile_elementow; i++)
	{
		o << i + 1 << " : " << b.osoby[i] << endl;
	}
	
	return o;
}
