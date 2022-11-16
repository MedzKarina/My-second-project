#include "calculations.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
#include <iterator>
using std::vector;
using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    vector<int> paz;
    int egz;
    float galutinis;
    int mediana;
};

bool lyginimas(studentas i1, studentas i2);
string ToString(int value);
void Timer(clock_t begin, clock_t end);
void Isvedimas(vector<studentas> studentai, string fileName);
bool Grupavimas(vector<studentas> studentai);
void Grupavimas(list<studentas> studentai);
studentas Gen(int cnd, int studentoId);
vector<studentas> ReadFromFile (string fileName);
list<studentas> ReadFromFileList (string fileName);
void Gen2(int gstud);

#endif
