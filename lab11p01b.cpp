#include <iostream>
#include <sstream>

using namespace std;

class punkt
{
private:
    int x;
    int y;

public:
    punkt(int px, int py) : x(px), y(py) {}
    friend wektor; //klasa zaprzyjazniona
};

class wektor
{
private:
    punkt A;
    punkt B;

public:
    wektor(punkt a, punkt b) : A(a), B(b) {}
    string toString()
    {
        stringstream s;
        s << "A(" << A.x << ";" << A.y
          << ") B(" << B.x << ";" << B.y << ")";
        return s.str();
    }
};

int main()
{
    // punkt p1(10,5), p2(30,-20);
    // wektor w1(p1,p2);
    wektor w1(punkt(5, -5), punkt(3, 9));

    cout << w1.toString();
    return 0;
}