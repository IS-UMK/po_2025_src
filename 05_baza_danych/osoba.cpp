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
