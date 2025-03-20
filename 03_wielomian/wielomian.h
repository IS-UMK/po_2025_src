class Wielomian
{
private:
    int st;
    double* wsp;
    Wielomian(int st);

public:

    friend Wielomian Dodaj(const Wielomian& w1, const Wielomian& w2);

    Wielomian();
    Wielomian(int st, double* wsp);
    Wielomian(const Wielomian&);
    Wielomian Pochodna(int ktora = 1);
    void Wypisz();
    ~Wielomian();
};

Wielomian Dodaj(const Wielomian& w1, const Wielomian& w2);




