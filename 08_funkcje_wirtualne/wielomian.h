#ifndef WIELOMIAN_H
#define WIELOMIAN_H

#include "funkcja.h"

#include<iostream>
using namespace std;

class Wielomian : public Funkcja
{
protected:
    int st;
    double* wsp;
    Wielomian(int st);

public:
    Wielomian();
    Wielomian(int st, double* wsp);
    Wielomian(const Wielomian&);
    
    Wielomian Pochodna(int ktora = 1) const;
    void Wypisz();
    Wielomian& operator=(const Wielomian& w);

    double ObliczWartosc(double x) override;

    ~Wielomian();

    friend Wielomian Dodaj(const Wielomian& w1, const Wielomian& w2);
    friend Wielomian operator+(const Wielomian& w1, const Wielomian& w2);
    friend ostream& operator<<(ostream& o, const Wielomian& w);
};

Wielomian Dodaj(const Wielomian& w1, const Wielomian& w2);
Wielomian operator+(const Wielomian& w1, const Wielomian& w2);
ostream& operator<<(ostream& o, const Wielomian& w);

#endif



