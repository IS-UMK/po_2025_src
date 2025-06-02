#include "wyraz.h"

ostream& operator<<(ostream& o, const Wyraz& w)
{
    for (auto znak : w.wyraz) o.put(znak);
    return o;
}

istream& operator>>(istream& s, Wyraz& w)
{
    w.wyraz.clear();

    char znak;

    while (s.good() && s.get(znak) && !isalpha(znak)) { };
    
    if (!s.good()) return s;
    w.wyraz.push_back(znak);

    while (s.good() && s.get(znak) && isalpha(znak)) 
    {
        w.wyraz.push_back(znak);
    }
    return s;
}

Wyraz::Wyraz(const Wyraz &w)
{
	wyraz.clear();
	for (auto znak : w.wyraz) wyraz.push_back(znak);
}

bool Wyraz::operator<(const Wyraz& w) const
{
    int min_dl = Dlugosc() < w.Dlugosc() ? Dlugosc() : w.Dlugosc();
    for (int i = 0; i < min_dl; i++)
    {
        if (tolower(wyraz[i]) != tolower(w.wyraz[i]))
            return tolower(wyraz[i]) < tolower(w.wyraz[i]);
    }
    return Dlugosc() < w.Dlugosc();
}
