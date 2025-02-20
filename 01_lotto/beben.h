struct beben
{
    int rozmiar;
    int *kule; 
    char* opis;
};
 
struct beben *utworz(int n);
struct beben *wypelnij(struct beben *b);
struct beben *mieszaj(struct beben *b);
void wypisz(struct beben *b, int n);
void zwolnij(struct beben *b);