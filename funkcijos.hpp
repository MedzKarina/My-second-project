#include "mylib.hpp"

struct studentas {
    string vardas;
    string pavarde;
    double vidurkis;
    double mediana;
    int egzaminas;
    double galutinis;
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
studentas Nuskaitymas();
void Vidurkis(studentas temp, int n);
void Mediana(studentas temp, int n);
void gen(int x);
vector<studentas> Failo(int x);
string PazymioGeneravimas();
void isv(vector<studentas> v, string x);
