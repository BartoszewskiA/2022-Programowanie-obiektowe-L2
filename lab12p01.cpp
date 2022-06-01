#include <iostream>

using namespace std;

class Ze
{
protected:
    double a;
    double b;

public:
    Ze(double A = 0, double B = 0) : a(A), b(B) {}
    Ze operator+(Ze liczba_2)
    {
        double a = this->a + liczba_2.a;
        double b = this->b + liczba_2.b;
        return Ze(a, b);
    }
    Ze operator-()
    {
        double a = - this->a;
        double b = - this->b;
        return Ze(a, b);
    }

    Ze operator-(Ze liczba)
    {
        double a = - liczba.a;
        double b = - liczba.b;
        return Ze(a,b);
    }

    Ze operator*(double s) // z*s
    {
        double a = this->a * s;
        double b = this->b * s;
        return Ze(a, b);
    }

    friend ostream &operator<<(ostream &s, Ze liczba);
    // friend Ze operator-(Ze liczba);
    // friend Ze operator+(Ze liczba_1, Ze liczba_2);
    // friend Ze operator*(Ze liczba_1, double s);
    friend Ze operator*(double s, Ze liczba_1);
};

ostream &operator<<(ostream &s, Ze liczba)
{
    if (liczba.a == 0 && liczba.b == 0)
        s << 0;
    else
    {
        if (liczba.a != 0)
        {
            s << liczba.a;
            if (liczba.b >= 0)
                s << "+";
        }
        if (liczba.b != 0)
            s << liczba.b << "i";
    }
    return s;
}

// Ze operator+(Ze liczba_1, Ze liczba_2)
// {
//     double a = liczba_1.a + liczba_2.a;
//     double b = liczba_1.b + liczba_2.b;
//     return Ze(a,b);
// }

// Ze operator-(Ze liczba)
// {
//     double a = - liczba.a;
//     double b = - liczba.b;
//     return Ze(a,b);
// }

// Ze operator*(Ze liczba_1, double s)  // z*s
// {
//     double a = liczba_1.a * s;
//     double b = liczba_1.b * s;
//     return Ze(a,b);
// }

Ze operator*(double s, Ze liczba_1) // s*z
{
    double a = liczba_1.a * s;
    double b = liczba_1.b * s;
    return Ze(a, b);
}

int main()
{
    Ze l1(0, 0);
    cout << l1;
    return 0;
}