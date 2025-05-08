#include "funkcja.h"
#include "parabola.h"
#include "gauss.h"
#include "wielomian.h"

#include <iostream>
using namespace std;

double calka(Funkcja* funkcja, double a, double b, int n=100)
{
	double h = (b - a) / n;
	double c = 0.0;

	for (int i = 0; i < n; i++)
	{
		c += funkcja->ObliczWartosc(a + i*h);
	}
	return c * h;
}

int main()
{
    int n;

	cout << "Ile wezlow calkowania? " ;
	cin >> n;

	double srednia = 3, odchylenie = 5;
	Gauss g(srednia, odchylenie);
	cout << "Funkcja: " << g << endl;

	double a = srednia, b = 3.0 * odchylenie;

	double wynik = calka(&g, a, b, n);

	cout << "Przedzial calkowania: [" << a << ", " << b << "]" << endl; 
	cout << "Wynik calkowania = " << wynik << endl;

	Parabola p(1, 0, 0);
	cout << "\nFunkcja: " << p << endl;

	a = 0.0, b = 1.0;
	wynik = calka(&p, a, b, n);
	
	cout << "Przedzial calkowania: [" << a << ", " << b << "]" << endl; 
	cout << "Wynik calkowania = " << wynik << endl;
	return 0;
}
