#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class wektor
{
private:
    int Xp;
    int Yp;
    int Xk;
    int Yk;

public:
    void setPoczatek(int x, int y)
    {
        Xp = x;
        Yp = y;
    }

    void setKoniec(int x, int y)
    {
        Xk = x;
        Yk = y;
    }

    int getXpoczatku() { return Xp; }
    int getYpoczatku() { return Yp; }
    int getXkonca() { return Xk; }
    int getYkonca() { return Yk; }

    double getDlugosc();
    void losuj();
};

double wektor::getDlugosc()
{
    return sqrt((Xk - Xp) * (Xk - Xp) + (Yk - Yp) * (Yk - Yp));
}

void wektor::losuj()
{
    setPoczatek(rand() % 201 - 100, rand() % 201 - 100);
    setKoniec(rand() % 201 - 100, rand() % 201 - 100);
}

wektor tab[10]; // obiekty stsatyczne tworzone są w tym miejscu

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        tab[i].losuj();
 
    for (int i = 0; i < 10; i++)
    {
        if (i % 3 == 0)
            cout << endl;
        cout << "[("
             << tab[i].getXpoczatku()
             << ","
             << tab[i].getYpoczatku()
             << ")("
             << tab[i].getXkonca()
             << ","
             << tab[i].getYkonca()
             << ")]\t";
    }
    // szukamy maksimum
    double max = 0;

    for (int i = 0; i < 10; i++)
        if (tab[i].getDlugosc() > max)
            max = tab[i].getDlugosc();
    cout << endl
         << "Maksimum= "
         << max;

    return 0;
}
