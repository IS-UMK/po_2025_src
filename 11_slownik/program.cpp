#include "wyraz.h"
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Program tworzy slownik wyrazow pochodzących z pliku tekstowego. */


/* Funkcja porownujaca dwa elementy slownika ze wzgledu na liczbe znakow wyrazu */
bool porownaj_dlugosc(pair<Wyraz, int> a, pair<Wyraz, int> b)
{
	return a.first.Dlugosc() < b.first.Dlugosc();
}


/* Funkcja porownujaca dwa wyrazy wzgledem liczby wystapien*/
bool porownaj_liczbe(pair<Wyraz,int> a, pair<Wyraz,int> b )
{
	return a.second > b.second;
}

// Obiekt funkcyjny, ktory posiada operator(a,b) porownujacy dwa elementy slownika wzgledem liczby znakow
class PorownywatorDlugosci
{
	public:
		bool operator()(pair<Wyraz,int> a, pair<Wyraz,int> b)
		{
			return a.first.Dlugosc() < b.first.Dlugosc();
		}
};

void wypiszElement(pair<Wyraz, int> x)
{
	cout << x.second << " : " << x.first << endl;
}

int main()
{
	Wyraz wyraz;
	map<Wyraz,int> slownik;

	string nazwa_pliku;
   	cout << "Podaj nazwe pliku: " ;
   	getline(cin, nazwa_pliku);

	ifstream plik(nazwa_pliku);
   	if(plik.is_open()) 
   	{
		// Wypelniamy slownik wyrazami z pliku
		while (plik >> wyraz)
		{
			slownik[wyraz]++;
			cout << wyraz << endl;
		}
		plik.close();
	}else
	{
	   	cerr << "Blad! Nie moge odczytac pliku: " << nazwa_pliku << endl;
	   	return 1;
   	}

	//Wyswietlamy slownik
	for(auto element: slownik)
    {
		cout << element.first << " " <<  element.second << endl;
    }

/*  
	std::stringstream ss;      
 
	ss << "!@&#&*(Ala_ma++kota" << endl;
 
	Wyraz w;
	while(!ss.eof())
	{
		ss >> w;
		cout << w << endl;
	}

*/


	// 1. Wypisz 3 najczesciej wystepujace wyrazy.
	// Wykorzystaj w tym celu algorytm sort() oraz funkcje porownujaca dwa elementy slownika ze wzgledu na liczbe wystapien
    
	cout << "\nSortowanie wzgledem liczby wystapien" << endl;

	// kopia elementow slownika do wektora, w ktorym odbedzie sie sortowanie
	vector<pair<Wyraz, int>> v(slownik.begin(), slownik.end()); 
	sort(v.begin(), v.end(), porownaj_liczbe);
	
	for(auto x: v) 
	{
		cout << x.second << " : " << x.first << endl;
	}

	cout << "\nTrzy najczesciej wystepujace wyrazy" << endl;

	for_each(v.begin(), v.begin()+3, wypiszElement);

	// 2. Wypisz najdluzszy wyraz ze slowanika. Wykorzystaj w tym celu algorytm max_element oraz 
	// obiekt funkcyjny sluzacy do porownania dwoch wyrazow ze wzgledu na dlugosc

	auto iter = max_element(slownik.begin(), slownik.end(), PorownywatorDlugosci());
	cout << "\nNajdluzszy wyraz to: " << (*iter).first << ", liczba znakow: " << (*iter).first.Dlugosc() << ", liczba wystapien: " << (*iter).second <<  endl;

	// 2. Wypisz w osobnych grupach wyrazy o liczbie znakow n=1, 2, 3, 4, ... az do najdluzszego wyrazu. 
	// Wykorzystaj w tym celu funkcje find_if oraz funkcje lambda sprawdzajaca warunek, czy wyraz posiada dlugosc n

	int max_dl = (*iter).first.Dlugosc() ;

	cout << "\nWyrazy o liczbie znakow n=1, 2, 3, ... az do najdluzszego wyrazu" << endl;
	cout << "dlugosc : liczba wystapien : lista wyrazow" << endl;
	for (int i = 1; i <= max_dl; i++)
	{
		// liczba unikatpwych wyrazow o dlugosci i w slowniku
		auto n = count_if(slownik.begin(), slownik.end(), [i](pair<Wyraz, int> x){return x.first.Dlugosc() == i;});

		if(n == 0 ) continue; // brak wyrazow o dlugosci i

		cout << i << " : " << n << " : "; 

		auto fit = slownik.begin();

		while(fit != slownik.end())
		{
			// szukamy pierwszego wystapienia wyrazu o dlugosci i
			fit = find_if(fit, slownik.end(), [i](pair<Wyraz,int> x){return x.first.Dlugosc() == i;});
			if(fit != slownik.end())
			{
				cout << (*fit).first << ", ";
				fit++;
			}
		}
		
		cout << endl;
	}

	return 0;
}
