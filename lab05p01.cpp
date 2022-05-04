#include <iostream>
#include <ctime>

using namespace std;

class Random
{
public:
    Random()
    {
        srand(time(NULL));
    }
    int nextInt()
    {
        return rand();
    }
    int nextInt(int b)
    {
        return rand() % b;
    }
    int nextInt(int a, int b)
    {
        return rand() % (b - a) + a;
    }
    double nextDouble()
    {
        int x = rand() % 1000;
        return (double)x / 1000;
    }
    bool nextMoneta()
    {
        int x = rand() % 2;
        if (x == 1)
            return true;
        else
            return false;
    }

    string nextMoneta2()
    {
        int x = rand() % 2;
        if (x == 1)
            return "orzel";
        else
            return "reszka";
    }
    int nextKostka()
    {
        return nextInt(6) + 1;
    }
};

int main()
{
    Random *random = new Random;

    for (int i = 0; i < 10; i++)
    {
        cout << random->nextInt() << " ";
        cout << random->nextInt(50) << " ";
        cout << random->nextInt(-100, 100) << " ";
        cout << random->nextDouble()<<" "; // 0-0.999999
        cout << random->nextKostka() << " ";
        cout << random->nextMoneta2() << endl;
    }
    return 0;
}