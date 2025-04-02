#include "data.h"
#include "osoba.h"
#include "baza.h"

#include <iostream>

using namespace std;

int main()
{
	Data data1;
	cout << "Data domniemana: " << data1 << endl;

	Data data2(1, 4, 2025);
	cout << "Data dzisiejsza: " << data2 << endl;

	Osoba osoba1;
	cout << "Osoba domniemana: " << osoba1 << endl;

	Osoba osoba2("Kowalski", "Jan", data1, Plec::Mezczyzna);
	cout << "Osoba 2: " << osoba2 << endl;

	Osoba osoba3("Nowak", "Anna", {13, 12, 2001}, Plec::Kobieta);
	cout << "Osoba 3: " << osoba3 << endl;

	cout << "Domyslny rozmiar bazy: " <<  Baza::ROZMIAR_DOMYSLNY << endl;

	Baza baza;

    cout << "Baza domyslna:\n" << baza ;

	for (int i = 0; i < 100; i++)
	{
		baza.Dodaj(osoba2);
		baza.Dodaj(osoba3);
	}
	cout << "Baza danych po dodaniu 200 osob\n";
	cout <<  baza;

}