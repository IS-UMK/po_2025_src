#include "parabola.h"
#include<iostream>

using namespace std;

int main()
{

	double a = 1.0, b = -1e6, c = 1;

	// double a = 1.0, b = -1, c = -2; 


	Parabola p1(a, b, c);
	cout << "Parabola p1 " << p1 << endl;
	cout << "Extremum p1 x=" <<  p1.Ekstremum() << endl;

	double x1, x2;
	int k;

	k = p1.Pierwiastki(&x1, &x2);


	cout << "Ile miejsc zerowych: " << k << endl;

	if(k > 0) 
	{
		cout << std::fixed << std::setprecision(15) ;
		cout << "x1=" << x1 << endl;
		cout << "x2=" << x2 << endl;
		cout << "f(x1)=" << p1.ObliczWartosc(x1) << endl;
		cout << "f(x2)=" << p1.ObliczWartosc(x2) << endl;
	}

	Parabola2 p2(a, b, c);

	cout << "Parabola2 p2 " << p2 << endl;
	cout << "Extremum p2 x=" <<  p2.Ekstremum() << endl;

	k = p2.Pierwiastki(&x1, &x2);
	
	cout << "Ile miejsc zerowych: " << k << endl;
	
	if(k > 0) 
	{
		cout << std::fixed << std::setprecision(15) ;
		cout << "x1=" << x1 << endl;
		cout << "x2=" << x2 << endl;
		cout << "f(x1)=" << p2.ObliczWartosc(x1) << endl;
		cout << "f(x2)=" << p2.ObliczWartosc(x2) << endl;
	}
}
