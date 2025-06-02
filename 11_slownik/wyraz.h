#include <iostream>
#include <vector>

using namespace std;

#ifndef _WYRAZ_H
#define _WYRAZ_H

class Wyraz
{
private:
	vector<char> wyraz;

public:
	Wyraz(){ }
	Wyraz(const Wyraz &w);

	friend ostream & operator<<(ostream &o, const Wyraz &w);
	friend istream & operator>>(istream &o, Wyraz &w);
	
	bool operator<(const Wyraz &w) const;
	int Dlugosc() const {return wyraz.size();}
};
#endif
