#include "wektor.h"
#include "wyjatki.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	Wektor<int> liczby;
	cout << "Tworze pusty wektor" << endl;

	for(int i=1;i<=49;i++) liczby.Dodaj(i);
	cout << "Zawartosc komory losujacej\n";
	
	// test uzycia iteratorow
	Wektor<int>::iterator it;
	for(it=liczby.begin(); it!=liczby.end(); it++) cout << *it << " ";
	cout << endl;

	srand(time(NULL));

	cout << "Random shuffle (losowanie numerow lotto)\n";
	random_shuffle(liczby.begin(), liczby.end());
	for(it=liczby.begin(); it!=liczby.begin()+6; it++) cout << *it << " ";
	cout << endl;

	// sortowanie
	sort(liczby.begin(), liczby.end());

	cout << "Po posortowaniu: " << endl;

	// petla for zakresowa
	for(auto x: liczby)
	{
		cout << x << ", ";
	}
	cout << endl;

	cout << "Rotacja kolekcji : " << endl;
	
	rotate(liczby.begin(), liczby.begin()+liczby.IleElementow() /2 , liczby.end() );

	for(auto x: liczby) cout << x << " ";
	cout << endl;


	/* TEST SYTUACJI WYJATKOWYCH  */

	try
	{
		// uzycie niepopranego indeksu

		liczby[-1] = 42;

		cout << "ten komunikat nie zostanie wypisany" << endl;
	}	
	catch(ZlyIndeksWektora &w)
	{
		cout << "Zlapalem wyjatek typu: ZlyIndeksWektora" << endl;
		cout << w.Komunikat();
	}

	try
	{
		// uzycie niepopranego indeksu
		int max_id = liczby.IleElementow();

		liczby[max_id] = 42;

	}	
	catch(Wyjatek &w)
	{
		cerr << "Zlapalem wyjatek typu: Wyjatek" << endl;
		cerr << w.Komunikat();
	}

	try
	{
		// proba wywolania przepelnienia pamieci	
			
		while(true)
		{
			Wektor<double> *wec = new(std::nothrow) Wektor<double>(0x7fffffff);
			wec->Dodaj(1);
		}
	}
	catch(BrakPamieci &w)
	{
		cerr << "Zlapalem wyjatek typu: BrakPamieci" << endl;
		cerr << w.Komunikat();
	}
	catch(const std::exception& e)
	{
		cerr << "Zlapalem wyjatek typu: exception" << endl;
		cerr << e.what() << '\n';
	}
	catch(...)
	{
		cerr << "Zlapalem nieznany wyjatek" << endl;
	}
}
