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
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
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
        s << "A(" << A.getX() << ";" << A.getY()
          << ") B(" << B.getX() << ";" << B.getY() << ")";
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