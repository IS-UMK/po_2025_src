#include<iostream>
using namespace std;

class Wielomian
{
private:
    int st;
    double* wsp;
    Wielomian(int st);

public:

    friend Wielomian Dodaj(const Wielomian& w1, const Wielomian& w2);
    friend Wielomian operator+(const Wielomian& w1, const Wielomian& w2);
    friend ostream& operator<<(ostream& o, const Wielomian& w);

    Wielomian();
    Wielomian(int st, double* wsp);
    Wielomian(const Wielomian&);
    
    Wielomian Pochodna(int ktora = 1);
    void Wypisz();
    Wielomian& operator=(const Wielomian& w);

    ~Wielomian();
};

Wielomian Dodaj(const Wielomian& w1, const Wielomian& w2);
Wielomian operator+(const Wielomian& w1, const Wielomian& w2);
ostream& operator<<(ostream& o, const Wielomian& w);





