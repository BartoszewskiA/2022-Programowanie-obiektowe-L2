#include <iostream>
#include <sstream>

using namespace std;
class punkt
{
protected:
    int x;
    int y;

public:
    punkt(int px, int py) : x(px), y(py) { cout << " punkt "; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
    string toString()
    {
        stringstream temp;
        temp << "Punkt (" << x << ";" << y << ") ";
        return temp.str();
    }
};

class okrag : public punkt
{
protected:
    int r;

public:
    okrag(int px, int py, int pr) : punkt(px, py), r(pr) { cout << " okrag "; }
    void setR(int r) { this->r = r; }
    int getR() { return r; }
    double getObwod()
    {
        return 2 * 3.14 * r;
    }
    string toString()
    {
        stringstream temp;
        temp << "Okrag;  (" << x << ";" << y << ") r=" << r << " obwod=" << getObwod();
        return temp.str();
    }
};

class kolo : public okrag
{
public:
    kolo(int px, int py, int pr) : okrag(px, py, pr) { cout << " kolo "; }
    double getPole()
    {
        return 3.14 * r * r;
    }

    string toString()
    {
        stringstream temp;
        temp << "Kolo;  (" << x << ";" << y << ") r=" << r
             << " obwod=" << getObwod()
             << " Pole=" << getPole();
        return temp.str();
    }
};

int main()
{

    kolo p1(10, 20,100);
    cout << p1.toString();
    return 0;
}