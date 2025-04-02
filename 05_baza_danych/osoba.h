#ifndef OSOBA_H
#define OSOBA_H

#include <string>
#include <iostream>
#include "data.h"

using namespace std;

enum class Plec {Kobieta, Mezczyzna, Nieznana};

class Osoba
{
	private:
		string nazwisko;
		string imie;
		Data data_urodzenia;
		Plec plec;

	public:
		Osoba(const char* nazwisko = "", const char* imie = "",
			Data data_urodzenia = Data(), Plec plec = Plec::Nieznana) :
			nazwisko{ nazwisko }, imie{ imie },
			data_urodzenia{ data_urodzenia }, plec{ plec } { }

		friend ostream& operator<<(ostream& o, const Osoba& osoba);
};

#endif