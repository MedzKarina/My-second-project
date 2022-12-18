#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iterator>
#include <chrono>
#include <random>
#include <list>
#include <exception>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::sort;
using std::ofstream;
using std::stringstream;
using std::distance;
using std::istream_iterator;
using std::ifstream;
using std::ws;
using std::runtime_error;
using std::to_string;
using std::list;
using std::remove_if;

class Zmogus
{
protected:
    string vardas;
    string pavarde;
public:
    Zmogus() {}
    virtual ~Zmogus() = 0;

    inline string getVardas() const
    {
        return vardas;
    }
    inline string getPavarde() const
    {
        return pavarde;
    }

    inline void setVardas(string vardas)
    {
        Zmogus::vardas = vardas;
    }
    inline void setPavarde(string pavarde)
    {
        Zmogus::pavarde = pavarde;
    }
};

inline Zmogus::~Zmogus() {}

class Studentas : public Zmogus
{
private:
    vector <int> pazymiai;
    int egzaminas;
public:
    Studentas() : egzaminas(0)
    {
        Zmogus::vardas = "", Zmogus::pavarde = "";
    }

    Studentas(string vardas, string pavarde, vector<int> paz, int egz) : egzaminas(0)
    {
        vardas = vardas;
        pavarde = pavarde;
    };

    Studentas(const Studentas& a) : egzaminas(a.getEgzaminas())
    {

        vardas = a.getVardas();
        pavarde = a.getPavarde();
        pazymiai.reserve(a.getPazymiai().size());
        for (int i : a.getPazymiai())
        {
            pazymiai.push_back(i);
        }
    }

    Studentas& operator=(const Studentas& a)
    {
        if (&a == this) return *this;

        vardas = a.getVardas();
        pavarde = a.getPavarde();
        egzaminas = a.getEgzaminas();
        pazymiai.clear();
        pazymiai.shrink_to_fit();
        pazymiai.reserve(a.getPazymiai().size());
        for (int i : a.getPazymiai())
        {
            pazymiai.push_back(i);
        }
        return *this;
    }
    ~Studentas()
    {
        pazymiai.clear();
    }

    inline vector<int> getPazymiai() const
    {
        return pazymiai;
    }
    inline int getEgzaminas() const
    {
        return egzaminas;
    }
    inline void setPazymiai(vector<int> pazymiai)
    {
        Studentas::pazymiai = pazymiai;
    }
    inline void setEgz(int egz)
    {
        Studentas::egzaminas = egz;
    }
};

#endif // MYLIB_H_INCLUDED
