#pragma once
#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>
#include <random>
#include <list>
using namespace std;
struct studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float rez;
};

double vidurkis(vector<int> nd);

class StudentasClass
{
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float rez;
public:
    StudentasClass(string vardas, string pavarde, vector<int> nd, int egz)
    {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->nd = nd;
        this->egz = egz;
        this->rez = vidurkis(nd) * 0.4 + 0.6 * egz;
    }

    // 1.copy constructor
    StudentasClass(const StudentasClass& kitas)
    {
        this->vardas = kitas.vardas;
        this->pavarde = kitas.pavarde;
        this->nd = kitas.nd;
        this->egz = kitas.egz;
        this->rez = kitas.rez;
    }
    // 2.copy assignment constructor
    StudentasClass& operator =(const StudentasClass& kitas)
    {
        this->vardas = kitas.vardas;
        this->pavarde = kitas.pavarde;
        this->nd = kitas.nd;
        this->egz = kitas.egz;
        this->rez = kitas.rez;
        return *this;
    }
    // 3. Destructor
    ~StudentasClass()
    {

    }
    float galutinis() const
    {
        return rez;
    }
    void spausdinti()
    {
        cout << vardas << " " << pavarde << " " << rez << endl;
    }

    void spausdinti_pilnai()
    {
        cout << vardas << " " << pavarde << " " << nd[0] << " " << nd[1] << " " << nd[2] << " " << nd[3];
        cout << " " << nd[4] << " | " << egz << " " << rez << endl;
    }

};

void dalijimas_struct(list<studentas> studentai);
void dalijimas_class(list<StudentasClass> studentai);
void testuoti(int kiek);
