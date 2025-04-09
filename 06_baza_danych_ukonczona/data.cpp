#include "data.h"

ostream& operator<<(ostream& o, const Data& data)
{
    o << data.dzien << "-" << data.miesiac << "-" << data.rok;
    return o;
}

Data::Data(const string& napis)
{
    int poz1 = napis.find("-");
    int poz2 = napis.rfind("-");

    dzien = stoi(napis.substr(0, poz1));
    miesiac = stoi(napis.substr(poz1 + 1, poz2 - poz1));
    rok = stoi(napis.substr(poz2 + 1));
}
