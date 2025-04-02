#include "data.h"

ostream& operator<<(ostream& o, const Data& data)
{
    o << data.dzien << "-" << data.miesiac << "-" << data.rok;
    return o;
}
