#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data
{
	private:
		int dzien;
		int miesiac;
		int rok;

	public:
		Data(int dzien = 1, int miesiac = 1, int rok = 1960) :
			dzien{ dzien }, miesiac{ miesiac }, rok{ rok } { }
		friend ostream& operator<<(ostream& o, const Data& data);
};

#endif
