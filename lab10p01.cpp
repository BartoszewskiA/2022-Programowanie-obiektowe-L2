#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

class pracownik
{
protected:
    string imie;
    string nazwisko;
    string stanowisko;
    string wydzial;
    string *historia_zatrudnienia;
    string data() // dd.mm.rrrr
    {
        time_t czas_systemowy = time(NULL);
        tm *czas = localtime(&czas_systemowy);
        stringstream wynik;
        wynik << czas->tm_mday << "." << (1 + czas->tm_mon) << "." << (1900 + czas->tm_year);
        return wynik.str();
    }
    void dopisz_do_pliku()
    {
        fstream plik;
        plik.open("lista_pracownikow.txt", ios::app);
        plik << nazwisko << " " << imie << " Wydzial: "
             << wydzial << " stanowisko: "
             << stanowisko << " " << data() << endl;
        ;
        plik.close();
    }

public:
    pracownik(string im, string nazw, string w, string s) : imie(im), nazwisko(nazw), wydzial(w), stanowisko(s)
    {
        historia_zatrudnienia = new string;
        *historia_zatrudnienia = "Zatrudniony: " + data();
        // dopisz_do_pliku();
    }
    pracownik(const pracownik &wzor, string im = "", string nazw = "")
    {
        imie = im;
        nazwisko = nazw;
        wydzial = wzor.wydzial;
        stanowisko = wzor.stanowisko;
        historia_zatrudnienia = new string;
        *historia_zatrudnienia = "Zatrudniony: " + data();
        dopisz_do_pliku();
    }

    void wpis(string w)
    {
        string s = *historia_zatrudnienia + "\n" + w;
        *historia_zatrudnienia = s;
    }
    string toString()
    {
        stringstream temp;
        temp << nazwisko << " " << imie << " Wydzial: " << wydzial << " stanowisko: " << stanowisko
             << endl
             << "Historia zatrudnienia: " << *historia_zatrudnienia;
        return temp.str();
    }
    ~pracownik() { delete historia_zatrudnienia; }
};

pracownik tab[] = {
    pracownik("", "", "IT", "Administrator"),
    pracownik("", "", "IT", "Mlodszy specjalista"),
    pracownik("", "", "Produkcja", "Kierwnik zmiany"),
    pracownik("", "", "Produkcja", "Pracownik")};

int main()
{

    pracownik p1 = pracownik(tab[1], "Jan", "Kowalski");

    cout << p1.toString();
    return 0;
}