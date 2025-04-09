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

void Baza::Zapisz(const char* nazwa) const
{
	ofstream plik(nazwa);

	if (plik.is_open())
	{
		plik << *this;
		plik.close();
		cout << "Baza danych zapisana do pliku: " << nazwa << endl;
	}
	else
		cerr << "Blad zapisu pliku: " << nazwa << endl;
}

Baza& Baza::Wczytaj(const char* nazwa)
{
	ifstream plik(nazwa);

	if (plik.is_open())
	{
		string linia;

		// pierwsza linia pliku zawiera rozmiar bazy
		getline(plik, linia, ':');
		getline(plik, linia);
		this->rozmiar = stoi(linia);

		// druga linia pliku zawiera liczbe elementow w bazie
		getline(plik, linia, ':');
		getline(plik, linia);
		this->ile_elementow = stoi(linia);

		for (int i = 0; i < ile_elementow; i++)
		{
			getline(plik, linia, ':');

			// odczytujemy nazwisko i imie
			getline(plik, linia, ',');
		
			int poz = linia.rfind(" ");  // szukamy ostatniej spacji w linii, która oddziela imie od nazwiska
			string nazwisko = linia.substr(poz+1);  // nazwisko jest na pozycji od poz+1 do konca linii
			string imie = linia.substr(1, poz-1);  // na poczatku linii jest spacja, wiec imie zaczyna się od pozycji 1 i ma dlugosc poz-1 znakow

			// odczytujemy date urodzenia
			getline(plik, linia, ',');
			Data data(linia);

			// odczytujemy plec
			getline(plik, linia);
			Plec plec = str_na_plec(linia);
			osoby[i] = Osoba(nazwisko, imie, data, plec);
		}
		plik.close();
		cout << "Baza danych wczytana z pliku: " << nazwa << endl;
	}
	else
		cerr << "Blad odczytu zawartosci pliku: " << nazwa << endl;

	return* this;
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
	o << "Rozmiar: " << b.rozmiar <<  endl;
	o << "Liczba elementow: " << b.ile_elementow << endl;
	
	for (int i = 0; i < b.ile_elementow; i++)
	{
		o << i + 1 << ": " << b.osoby[i] << endl;
	}
	
	return o;
}

Baza::Baza(const Baza &baza):Baza(baza.rozmiar)
{
    ile_elementow = baza.ile_elementow;
    for (int i = 0; i < ile_elementow; i++) osoby[i] = baza.osoby[i];
}

Baza &Baza::operator=(const Baza &baza)
{
    if(rozmiar < baza.ile_elementow)
    {
        delete [] osoby;
        rozmiar = baza.rozmiar;
        osoby = new Osoba[rozmiar];
    }
    ile_elementow = baza.ile_elementow;
    for (int i = 0; i < ile_elementow; i++) osoby[i] = baza.osoby[i];
    return *this;
}
