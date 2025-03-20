#include "wielomian.h"
#include <iostream>
using namespace std;

int main()
{
	Wielomian w1;

	cout << "Wielomian domyslny: ";
	w1.Wypisz();
	cout << endl;


	double wsp[] = { 1.0, 2.0, -3.0, 4.0 };
	Wielomian w2(3, wsp);
	cout << "Wielomian w2 stopnia 3: ";
	w2.Wypisz();
	cout << endl;

	Wielomian w3(w2);
	cout << "Wielomian w3 (kopia w2): ";
	w3.Wypisz();
	cout << endl;

	Wielomian w4 = w3;
	cout << "Wielomian w4 (kopia w3): ";
	w4.Wypisz();
	cout << endl;

	Wielomian w5(2, wsp);
	cout << "Wielomian w5 stopnia 2: ";
	w5.Wypisz();
	cout << endl;

	Wielomian w6 = Dodaj(w4, w5);
	cout << "suma wielomianow w4+w5: ";
	w6.Wypisz();
	cout << endl;
}