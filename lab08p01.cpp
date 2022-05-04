#include <iostream>

using namespace std;

string wydzialy[] = {"Produkcja", "IT", "Spedycja"};
int liczba_wydzialow = 3;

class osoba
{
private:
    static int ile;
    int Id;
    string imie;
    string nazwisko;

public:
    osoba() : imie("NN"), nazwisko("NN") { Id = ++ile; }
    osoba(string im, string nazw) : imie(im), nazwisko(nazw) { Id = ++ile; }
    void setImie(string imie) { this->imie = imie; }
    void setNazwisko(string nazwisko) { this->nazwisko = nazwisko; }
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getId() { return Id; }
};

int osoba::ile = 0;

class pracownik : public osoba
{
private:
    string wydzial;

public:
    pracownik() : osoba() { wydzial = wydzialy[0]; }
    pracownik(string im, string nazw, string w) : osoba(im, nazw)
    {
        bool prawodlowy = false;
        for (int i = 0; i < liczba_wydzialow; i++)
            if (wydzialy[i] == w)
                prawodlowy = true;
        if (prawodlowy)
            wydzial = w;
        else
            wydzial = wydzialy[0];
    }
    void setWydzial(string wydzial) 
    {
        bool prawodlowy = false;
        for (int i = 0; i < liczba_wydzialow; i++)
            if (wydzialy[i] == wydzial)
                prawodlowy = true;
        if (prawodlowy)
            this->wydzial = wydzial;
        else
            this->wydzial = wydzialy[0];
    }
    
    string getWydzial() { return wydzial; }
};

int main()
{
    //pracownik firma[100];
    pracownik * firma[100];
    firma[0] = new pracownik("aaa","AAAA","IT");
    return 0;
}