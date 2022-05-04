#include <iostream>

using namespace std;
class punkt
{
protected:
    int x;
    int y;
    double r;

public:
    punkt(int px, int py) : x(px), y(py) {}
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
};

class okrag : public punkt
{
protected:
    int r;

public:
    okrag(int px, int py, int pr) : punkt(px, py), r(pr) {}
    void setR(int r) { this->r = r; }
    int getR() { return r; }
    double getObwod()
    {
        return 2 * 3.14 * r;
    }
};

class kolo : public punkt
{
protected:
    int r;

public:
    kolo(int px, int py, int pr) : punkt(px, py), r(pr) {}
    void setR(int r) { this->r = r; }
    int getR() { return r; }
    double getObwod()
    {
        return 2 * 3.14 * r;
    }
    double getPole()
    {
        return 3.14 * r * r;
    }
};

int main()
{

    return 0;
}