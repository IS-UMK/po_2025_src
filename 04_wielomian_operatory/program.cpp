#include "wielomian.h"
#include <iostream>
using namespace std;

int main()
{
	Wielomian w1;
	cout << "Wielomian w1 domyslny: " << w1 << endl;

	double wsp[] = { 1, 2.1234 , -3.1, 4 };
	Wielomian w2(3, wsp);
	cout << "Wielomian w2 stopnia 3: " << w2 << endl;

	Wielomian w3(w2);
	
	cout << "Wielomian w3 (kopia w2):  " << w3 << endl;

	Wielomian w4=w3;
	cout << "Wielomian w4 (kopia w3):  " << w4 << endl;

	Wielomian w5(2, wsp);
	cout << "Wielomian w5 stopnia 2: " << w5 << endl;
	
	Wielomian w6 = Dodaj(w4, w5);
	cout << "Suma wielomianow w4 + w5 :  " << w4 + w5 << endl;

	w1 = w6;
	cout << "Wielomian w1 po wykonaniu w1=w6 : "  << w1 << endl;

	cout << "Suma w1+w5 : " << w1 + w5 << endl;
}