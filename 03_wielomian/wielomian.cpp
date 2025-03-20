#include "wielomian.h"
#include <iostream>

using namespace std;

Wielomian::Wielomian(int st) : st{ st }, wsp{new double[st+1]}
{
}

Wielomian::Wielomian(): Wielomian(0)
{
	wsp[0] = 0.0;
}

Wielomian::Wielomian(int st, double* wsp):Wielomian(st)
{
	for (int i = 0; i < st+1; i++)
	{
		this->wsp[i] = wsp[i];
	}
}

Wielomian::Wielomian(const Wielomian& w):Wielomian(w.st, w.wsp)
{

}

Wielomian Wielomian::Pochodna(int ktora)
{
	// TODO do zaimplementowania
	return Wielomian();
}

void Wielomian::Wypisz()
{
	cout << "f(x) = ";
	for (int i = st; i >0 ;  i--)
	{
		cout << wsp[i] << " x^" << i << " + ";
	}
	cout << wsp[0];
}

Wielomian::~Wielomian()
{
	if (wsp != nullptr)
	{
		delete[] wsp;
		wsp = nullptr;
	}
}

Wielomian Dodaj(const Wielomian& w1, const Wielomian& w2)
{
	int maxst = w1.st;
	if (maxst < w2.st) maxst = w2.st;

	Wielomian w(maxst);

	for (int i = 0; i < w.st + 1; i++) w.wsp[i] = 0.0;
	for (int i = 0; i < w1.st + 1; i++) w.wsp[i] += w1.wsp[i];
	for (int i = 0; i < w2.st + 1; i++) w.wsp[i] += w2.wsp[i];
	return w;
}
