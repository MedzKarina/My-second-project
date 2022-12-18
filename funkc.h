#ifndef FUNKC_H_INCLUDED
#define FUNKC_H_INCLUDED

#include "mylib.h"

bool rusiav(const Studentas& s1, const Studentas& s2);

void nuskaitymas(vector<Studentas>& studentai, int& studsk, string pavadinimas);
void nuskaitymas(list<Studentas>& studentai, int& studsk, string pavadinimas);

void naujasFailas(int studsk);

void remove_if_skirstymas(vector<Studentas>& studentai, vector<Studentas>& minksti);
void remove_if_skirstymas(list<Studentas>& studentai, list<Studentas>& minksti);

void isvedimas_i_2_failus(vector<Studentas> studentai, vector<Studentas> minksti, int stud);
void isvedimas_i_2_failus_list(int studsk, list<Studentas> studentai, list<Studentas> minksti);

double mediana(vector<int> v);
double vidurkis(vector<int> v);
double galutinis(double vid, double egzam);
int random(int low, int high);

#endif // FUNKC_H_INCLUDED
