#include "wielomian.h"

Wielomian::Wielomian(int st) : st{ st }, wsp{new double[st+1]}
{
}


Wielomian::Wielomian():Wielomian(0)
{
	wsp[0] = 0.0;
}

Wielomian::Wielomian(int st, double* wsp): Wielomian(st)
{
	for (int i = 0; i < st+1; i++)
	{
		this->wsp[i] = wsp[i];
	}
}

Wielomian::Wielomian(const Wielomian& w):Wielomian(w.st, w.wsp)
{

}

void Wielomian::Wypisz()
{
	cout << *this;

}


Wielomian Wielomian::Pochodna(int ktora)
{
	if (ktora > st)
	{
		Wielomian w;
		return w;
	}

	if (ktora == 1)
	{
		Wielomian w(st - 1);
		for (int i = 0; i < st; i++)
		{
			w.wsp[i] = this->wsp[i + 1] * (i + 1);
		}
		return w;
	}
	return Pochodna(1).Pochodna(ktora - 1);
}


Wielomian Dodaj(const Wielomian& a, const Wielomian& b)
{
	return a + b;
}

ostream& operator<<(ostream& o, const Wielomian& w)
{
	o << "f(x) = ";
	for (int i = w.st; i > 0; i--)
		if (w.wsp[i] != 0.0)
		{
			if (w.wsp[i] != 1.0) o << showpos << fixed << setprecision(2) 
				<< w.wsp[i] << noshowpos;
			if (i != 1) o << " x^" << i << " ";
			else  o << " x ";
		}

	if (w.wsp[0] != 0 || w.st == 0) o << showpos << w.wsp[0] << noshowpos;
	o << defaultfloat;

	return o;
}


Wielomian& Wielomian::operator=(const Wielomian& w)
{
	if (this == &w) return* this;

	if (st != w.st)
	{
		st = w.st;
		delete[] wsp;
		wsp = new double[st + 1];
	}
	for (int i = 0; i <= st; i++)
	{
		wsp[i] = w.wsp[i];
	}
	return *this;
}


Wielomian operator+(const Wielomian& w1, const Wielomian& w2)
{
	int maxst = w1.st;
	if (maxst < w2.st) maxst = w2.st;

	Wielomian w(maxst);

	for (int i = 0; i < w.st + 1; i++) w.wsp[i] = 0.0;
	for (int i = 0; i < w1.st + 1; i++) w.wsp[i] += w1.wsp[i];
	for (int i = 0; i < w2.st + 1; i++) w.wsp[i] += w2.wsp[i];
	return w;
}

Wielomian::Wielomian(double x) :Wielomian(0)
{
	wsp[0] = x;
}

double Wielomian::ObliczWartosc(double x) const
{
	double y = wsp[st];
	for (int i = st-1; i >= 0; i--)
		y = x * y + wsp[i];

	return y;
}

Wielomian::~Wielomian()
{
	if (!wsp)
	{
		delete[] wsp;
		wsp = nullptr;
	}
}
