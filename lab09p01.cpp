#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;
class wektor
{
private:
    int x;
    int y;

public:
    wektor(int px = 0, int py = 0) : x(px), y(py) {}
    double getDlugosc()
    {
        return sqrt(x * x + y * y);
    }
    string toString()
    {
        stringstream temp;
        temp << "[" << x << ";" << y << "]";
        return temp.str();
    }
    friend int porownaj(wektor &w1, wektor &w2);
    friend wektor dodaj(wektor &w1, wektor &w2);
    friend wektor *dodaj_v2(wektor &w1, wektor &w2);
    friend wektor *mnozenie(wektor &w1, int mnoznik);
};

int porownaj(wektor &w1, wektor &w2)
{
    if (w1.getDlugosc() > w2.getDlugosc())
        return 1;
    else if (w1.getDlugosc() == w2.getDlugosc())
        return 0;
    else
        return -1;
}

wektor dodaj(wektor &w1, wektor &w2)
{
    int dx = w1.x + w2.x;
    int dy = w1.y + w2.y;
    wektor wynik(dx, dy);
    return wynik;
}

wektor *dodaj_v2(wektor &w1, wektor &w2)
{
    int dx = w1.x + w2.x;
    int dy = w1.y + w2.y;
    wektor *wynik = new wektor(dx, dy);
    return wynik;
}

wektor *mnozenie(wektor &w1, int mnoznik)
{
    int dx = w1.x * mnoznik;
    int dy = w1.y * mnoznik;
    wektor *wynik = new wektor(dx, dy);
    return wynik;
}

using namespace std;

int main()
{
    wektor wektor1(10, 6), wektor2(3, -21);
    // cout<< porownaj(wektor1,wektor2);
    // wektor w = dodaj(wektor1, wektor2);
    wektor *w = dodaj_v2(wektor1, wektor2);
    wektor *w2 = mnozenie(wektor1, 3);
    cout << w->toString();
    delete w;
    delete w2;
    return 0;
}