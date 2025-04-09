#include "osoba.h"

ostream& operator<<(ostream& o, Plec plec)
{
    switch (plec)   
    {
    case Plec::Kobieta:
        o << "Kobieta";
        break;
    case Plec::Mezczyzna:
        o << "Mezczyzna";
        break;
    case Plec::Nieznana:
        o << "Nieznana";
        break;
    default:
        break;
    }
    return o;
}

ostream& operator<<(ostream& o, const Osoba& osoba)
{
    o << osoba.imie << " " << osoba.nazwisko << ", " <<
        osoba.data_urodzenia << ", " << osoba.plec;
    return o;
}

Plec str_na_plec(const string& tekst)
{
    if(tekst.find("Kobieta")) return Plec::Kobieta;
    if(tekst.find("Mezczyzna")) return Plec::Mezczyzna;
    return Plec::Nieznana;
}

Osoba Osoba::WczytajOsobe()
{
    string imie, nazwisko;
    int dzien, miesiac, rok;
    int plec;
    cout << "Imie: ";
    cin >> imie;
    cout << "Nazwisko: ";
    cin >> nazwisko;
    cout << "Data urodzenia (dzien miesiac rok): ";
    cin >> dzien >> miesiac >> rok;
    cout << "Plec (0 - Kobieta, 1 - Mezczyzna): ";
    cin >> plec;
    return Osoba(nazwisko, imie, {dzien, miesiac, rok}, (Plec)plec);
}
