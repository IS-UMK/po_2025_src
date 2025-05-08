#include "gauss.h"

#define PI 3.1415926535

double Gauss::ObliczWartosc(double x)
{
	return exp(-(x-srednia) * (x-srednia)/(2.0 * odchylenie * odchylenie))/(sqrt(2.0*PI) * odchylenie);
}

ostream& operator<<(ostream &o, const Gauss &g)
{
	o << "Gauss (srednia=" << g.srednia << ", odchylenie=" << g.odchylenie << ")";
	return o;
}



