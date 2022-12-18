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

class Studentas
{
private:
    string vardas;
    string pavarde;
    vector <int> pazymiai;
    int egzaminas;
public:
    Studentas() : egzaminas(0) {}

    //get
    inline string getVardas() const
    {
        return vardas;
    }
    inline string getPavarde() const
    {
        return pavarde;
    }
    inline vector<int> getPazymiai() const
    {
        return pazymiai;
    }
    inline int getEgzaminas() const
    {
        return egzaminas;
    }

    //set
    inline void setVardas(string vardas)
    {
        Studentas::vardas = vardas;
    }
    inline void setPavarde(string pavarde)
    {
        Studentas::pavarde = pavarde;
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
