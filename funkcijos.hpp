#include "mylib.hpp"

struct studentas {
    string vardas;
    string pavarde;
    double vid;
    double med;
    int egz;
    double gal;
};

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}

    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};

studentas ivedimas(int &n);
studentas generavimas(int &n);
studentas nuskaitymas();
void Vidurkis(studentas temp, int n);
void Mediana(studentas temp, int n);
void gen(int x);
list<studentas> nusk(int x);
string pazGeneravimas();
void isv(list<studentas> l, string x);
