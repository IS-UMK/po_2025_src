#include "parabola.h"
#include <cmath>

Parabola::Parabola(double a, double b, double c):Wielomian(2)
{
	wsp[0]=c;
	wsp[1]=b;
	wsp[2]=a;
	delta= b*b-4.0*a*c;
}

double Parabola::Ekstremum() const
{
	return -wsp[1]/(2.0*wsp[2]);
}

Parabola::Parabola(const Parabola &p):Parabola(p.wsp[2], p.wsp[1],p.wsp[0]) {}

int Parabola::Pierwiastki(double* x1, double* x2) const
{
	if (delta < 0 || (wsp[2] == 0.0 && wsp[1] == 0.0)) return 0;

	if (delta == 0) 
	{
		*x1 = *x2 = Ekstremum();
		return 1;
	}
	
	if(wsp[2]==0.0)  // gdy a=0.0 to miejsce zerowe wynosi -c/b
	{
		*x1 = *x2 = -wsp[0]/wsp[1];
		return 1;
	}

	*x1=-(wsp[1]-sqrt(delta))/(2*wsp[2]);
	*x2=-(wsp[1]+sqrt(delta))/(2*wsp[2]);

	return 2;
}

int Parabola2::Pierwiastki(double *x1, double *x2) const
{
    int k = Parabola::Pierwiastki(x1, x2);

    if(wsp[1] < 0.0) *x2 = wsp[0]/wsp[2]/ *x1;
    else  *x1 = wsp[0] / wsp[2] / *x2;

    return k;
}