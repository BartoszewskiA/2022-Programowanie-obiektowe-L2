#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct znak
{
    char zn;
    int wyst;
};
znak *tab[256];

void przygotuj_tablice();
void dodaj_znak(char x);
void wypisz();
void usun();

int main()
{
    przygotuj_tablice();
    fstream plik;
    plik.open("dane.txt", ios::in);
    string s;
    while (!plik.eof())
    {
        getline(plik,s);
        for (int i=0; i< s.length(); i++)
            dodaj_znak(s[i]);
    }
    plik.close();

    // dodaj_znak('a');
    // dodaj_znak('b');
    // dodaj_znak('c');
    // dodaj_znak('a');
    // dodaj_znak('a');
    wypisz();
    usun();
    return 0;
}

void przygotuj_tablice()
{
    for (int i = 0; i < 256; i++)
        tab[i] = NULL;
}

void dodaj_znak(char x)
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        if (tab[poz]->zn == x)
        {
            tab[poz]->wyst = tab[poz]->wyst + 1;
            break;
        }
        else
            poz++;
    }

    if (tab[poz] == NULL) // dodajemy nowy rekord
    {
        tab[poz] = new znak;
        tab[poz]->zn = x;
        tab[poz]->wyst = 1;
    }
}

void wypisz()
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        cout << "(" << tab[poz]->zn << ") "
             << tab[poz]->wyst << "   ";
        poz++;
    }
}

void usun()
{
    int poz = 0;
    while (tab[poz] != NULL)
    {
        delete tab[poz];
        poz++;
    }
}