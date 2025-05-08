#ifndef GAUSS_H
#define GAUSS_H

#include "funkcja.h"

#include <iostream>
#include <cmath>
using namespace std;

class Gauss : public Funkcja
{
private:
	double srednia;
	double odchylenie;

public:
	Gauss(double srednia = 0.0, double odchylenie = 1.0) :
		srednia{ srednia }, odchylenie{ odchylenie } { }
	double ObliczWartosc(double x) override;
	friend ostream& operator<<(ostream& o, const Gauss& g);
};
#endif
