#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class testowa
{
public:
    testowa()
    {
        time_t czas = time(NULL);
        tm *czas_lokalny = localtime(&czas);
        fstream plik;
        plik.open("log.txt", ios::app);
        plik << "Start: "
             << czas_lokalny->tm_hour << ":"
             << czas_lokalny->tm_min << ":"
             << czas_lokalny->tm_sec << endl;
        plik.close();
    }
    ~testowa()
    {
        time_t czas = time(NULL);
        tm *czas_lokalny = localtime(&czas);
        fstream plik;
        plik.open("log.txt", ios::app);
        plik << "Stop: "
             << czas_lokalny->tm_hour << ":"
             << czas_lokalny->tm_min << ":"
             << czas_lokalny->tm_sec << endl;
        plik.close();
    }
};

int main()
{
    testowa *t1 = new testowa();
    getchar();
    delete t1;
    return 0;
}