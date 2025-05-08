#ifndef PARABOLA_H
#define PARABOLA_H

#include "wielomian.h"

class Parabola : public Wielomian
{
protected:
	double delta;

public:
	Parabola(double a=0.0, double b=0.0, double c=0.0);
	Parabola(const Parabola &p):Parabola(p.wsp[2],p.wsp[1],p.wsp[0]) { }

	double Ekstremum() const;
	int Pierwiastki(double* x1, double* x2) const;

};

class Parabola2 : public Parabola
{
public:
	Parabola2(double a, double b, double c) :Parabola(a, b, c) {}
	int Pierwiastki(double* x1, double* x2) const;
};

#endif