#include "data.h"
#include "osoba.h"
#include "baza.h"

#include <iostream>
using namespace std;

enum class Opcje { Dodaj = 1, Wyswietl, Sortuj, Zamknij, Nieznana};

Opcje menu()
{
	cout << "\n1. Dodaj\n"
		"2. Wyswietl\n"
		"3. Sortuj\n"
		"4. Zamknij\n\n"
		"Co wybierasz? ";
	int wybor;
	cin >> wybor;
	return (Opcje)wybor;
}

int main()
{
	Baza baza;
	Opcje wybor = Opcje::Nieznana;

	baza.Wczytaj();

	do {
		wybor = menu();
		switch(wybor)
		{
			case Opcje::Dodaj:
				baza.Dodaj(Osoba::WczytajOsobe());
				break;
			case Opcje::Wyswietl:
				cout << baza;
				break;
			case Opcje::Sortuj:
				cout << "Brakuje implementacji sortowania\n";
				break;
			case Opcje::Zamknij:
				cout << "Do widzenia." << endl;
				break;
			default:
				cout << "Nieznana opcja. Sprobuj ponownie.\n";
				break;
		}
	} while (wybor != Opcje::Zamknij);

	baza.Zapisz();
}