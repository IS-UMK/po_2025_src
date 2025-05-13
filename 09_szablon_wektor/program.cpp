#include "wektor.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
	
	Wektor<int> w1;
	cout << "Pusty wektor<int>" << endl;
	cout << w1 << endl << endl;
	
	// dodajemy 100 elementow
	for (int i = 0; i < 100; i++)
	{
		w1.Dodaj(i);
	}

	cout << "Po dodaniu 100 elementow:" << endl;
	cout << w1 << endl << endl;

	Wektor<int> w2 = w1;
	cout << "Kopia wektora (konstruktor kopiujacy):" << endl;
	cout << w2 << endl << endl;

	w1[0] = 42;
	cout << "Modyfikacja pierwszego elementu (operator[i]):" << endl;
	cout << w1 << endl << endl;

	w2.Wyczysc();
	cout << "Po wyczyszczeniu w2:" << endl;
	cout << w2 << endl << endl;

	w2 = w1;
	cout << "Po skopiowaniu w2=w1:" << endl;
	cout << w2 << endl << endl;


	string nazwa_pliku;

	cout << "Podaj nazwe pliku: ";
	getline(cin, nazwa_pliku);

	ifstream plik(nazwa_pliku);

	string linia;
	Wektor<string> tekst;

	if (plik.is_open())
	{
		while (getline(plik, linia))
		{
			tekst.Dodaj(linia);
		}
		plik.close();
	}
	else
		cerr << "Blad otworzenia pliku: " << nazwa_pliku << endl;

	cout << "Wczytano " << tekst.IleElementow() << " lini tekstu." << endl;
	cout << "Zawartosc pliku \"" << nazwa_pliku << "\" w odwrotnej kolejnosci" << endl; 

	for (int i = tekst.IleElementow()-1; i >=0; i--)
	{
		cout << tekst[i] << endl;
	}
}