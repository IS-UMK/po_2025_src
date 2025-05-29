#ifndef _WYJATKI_H
#define _WYJATKI_H

#include<string>
#include<iostream>

using namespace std;

class Wyjatek
{
protected:
	string tekst;
public:
	Wyjatek(const string& tekst="Wystapila sytuacja wyjatkowa."):tekst{tekst} { };
	virtual string Komunikat(){return "Komunikat: " + tekst + "\n";}
	virtual ~Wyjatek(){};
};

class ZlyIndeksWektora: public Wyjatek
{
public:
	int indeks;
	ZlyIndeksWektora(int i=-1): Wyjatek("Zly indeks wektora."),indeks(i){};
	string Komunikat() override {
		return "Komunikat: " + tekst + " Indeks=" + to_string(indeks) + "\n";
	}
};

class BrakPamieci: public Wyjatek
{
public:
	BrakPamieci():Wyjatek("Ups. Zabraklo pamieci"){};
};

#endif
