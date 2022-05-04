#include <iostream>
#include <ctime>

using namespace std;
class pudelko
{
private:
    int kot; //-1 martwy, 0 stan nieustalony, 1 zywy
public:
    pudelko()
    {
        int los = rand() % 2;
        if (los == 0)
            kot = -1;
        else
            kot = 1;
    }
    string otworz()
    {
        if (kot == -1)
            return "martwy ";
        else
            return "zywy ";
    }
};

int main()
{

    string s;
    for (int i = 0; i < 10; i++)
    {
        srand(time(NULL));
        pudelko p1;
        for (int j = 0; j < 6; j++)
            cout << p1.otworz();
        cout << endl;
        // cout << "nastepne? ";
        // cin >> s;
    }

    return 0;
}