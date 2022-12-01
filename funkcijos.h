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
        cout << vardas << " " << pavarde << " " << nd[0] << " " << nd[1] << " " ;
        cout << nd[2] << " " << nd[3] << " " << nd[4] << " | " << egz << " " << rez << endl;
    }

};

void dalijimas_struct(list<studentas> studentai);
void dalijimas_class(list<StudentasClass> studentai);
void testuoti(int kiek);
