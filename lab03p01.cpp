#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;
class r_kwadrat
{
private:
    int a;
    int b;
    int c;
    int delta;
    double x1;
    double x2;

public:
    r_kwadrat(int a, int b, int c);
    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }
    int getDelta() { return delta; }
    int getLiczbaRozwiazan()
    {
        if (delta > 0)
            return 2;
        else if (delta == 0)
            return 1;
        else
            return 0;
    }
    // double getX1() { return x1; }
    // double getX2() { return x2; }
    string getX1(); // zwraca "" gdy rozwiazanie nie istnieje
    string getX2();
    string getOdpowiedz();
};

r_kwadrat::r_kwadrat(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    delta = (b * b) - (4 * a * c);
    if (delta > 0)
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
    }
    else if (delta == 0)
        x1 = x2 = (-b) / (2 * a);
}

string r_kwadrat::getX1()
{
    stringstream wynik;
    if (delta > 0)
        wynik << x1;
    else if (delta == 0)
        wynik << x1;
    else
        wynik << "";
    return wynik.str();
}

string r_kwadrat::getX2()
{
    stringstream wynik;
    if (delta > 0)
        wynik << x2;
    else if (delta == 0)
        wynik << x1; // x1==x2
    else
        wynik << "";
    return wynik.str();
}

string r_kwadrat::getOdpowiedz()
{
    stringstream wynik;
    if (delta > 0)
        wynik << "x1=" << x1 << " x2=" << x2;
    else if (delta == 0)
        wynik << "x0=" << x1;
    else
        wynik << "Brak rozwiaqzan";
    return wynik.str();
}

int main()
{
    r_kwadrat r1(5, 1, 1);
    cout << "a=" << r1.getA() << " b=" << r1.getB() << " c=" << r1.getC() << " Delta=" << r1.getDelta() << endl;
    // cout << "x1=" << r1.getX1() << "  x2=" << r1.getX2();
    cout<<r1.getOdpowiedz();
    return 0;
}