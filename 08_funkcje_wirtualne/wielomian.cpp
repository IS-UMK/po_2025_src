#include "wielomian.h"
#include <iostream>
#include <iomanip>

using namespace std;

Wielomian::Wielomian(int st) : st{ st }, wsp{new double[st+1]}
{
}

Wielomian::Wielomian(): Wielomian(0)
{
	wsp[0] = 0;
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

Wielomian Wielomian::Pochodna(int st) const
{
   if(st==1)
   {
      Wielomian w;
      if(this->st>0)
      {
         w.st=this->st-1;
         delete [] w.wsp;
         w.wsp = new double [w.st+1];

         for(int i=0; i<=w.st; i++)   w.wsp[i]=this->wsp[i+1]*(i+1);
      }
      return w;
   }
   return Pochodna().Pochodna(st-1);
}

void Wielomian::Wypisz()
{
	cout << *this;
}

Wielomian& Wielomian::operator=(const Wielomian& w)
{
	if (this == &w) return* this;

	if (w.st != st)
	{
		delete[] wsp;
		st = w.st;
		wsp = new double[st+1];
	}

	for (int i = 0; i < st+1; i++)
	{
		wsp[i] = w.wsp[i];
	}
	return *this;
}

double Wielomian::ObliczWartosc(double x)
{
	double y = wsp[st];
	for (int i = st-1; i >= 0; i--)
		y = x * y + wsp[i];

	return y;
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
	return w1 + w2;
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

ostream& operator<<(ostream& o, const Wielomian& w)
{
	o << "f(x) = ";

	for (int i = w.st; i > 0; i--)
	{
		o << showpos << fixed << setprecision(2)  << w.wsp[i] << noshowpos;
		if (i == 1) o << " x ";
		else o << " x^" << i << " ";
	}
	o << showpos << w.wsp[0] << noshowpos << defaultfloat;
	return o;
}