#include "funkcijos.hpp"

int main() {
    studentas asmuo1;
    list<studentas> stud;
    int n, m;
    string c1, c2, c3, c4;
    cout << "Generuoti failus? (T/N): " << endl;
    cin >> c4;
    while (c4 != "T" && c4 != "t" && c4 != "N" && c4 != "n") {
        cout << "Ivestas simbolis turi buti T arba N! Pabandykite is naujo: " << endl;
        cin >> c4;
    }
    if (c4 == "T" || c4 == "t") {
        int a;
        cout << "Kiek studentu duomenu generuoti?"  << endl;
        cin >> a;
        gen(a);
        list<studentas> v = nusk(a);
        isv(v, "1");
        cout << endl;
        exit(0);
    }
    cout << "Duomenis nuskaityti is failo? (T/N):"  << endl;
    cin >> c3;
    while (c3 != "T" && c3 != "t" && c3 != "N" && c3 != "n") {
        cout << "Ivestas simbolis turi buti T arba N! Pabandykite is naujo: "  << endl;
        cin >> c3;
    }
    if (c3 == "T" || c3 == "t") { nuskaitymas(); }
    else {
        cout << "Iveskite studentu skaiciu:"  << endl;
        cin >> n;
        cout << "Pazymius generuoti atsitiktinai? (T/N):"  << endl;
        cin >> c1;
        while (c1 != "T" && c1 != "t" && c1 != "N" && c1 != "n") {
            cout << "Ivestas simbolis turi buti T arba N! Pabandykite is naujo: "  << endl;
            cin >> c1;
        }
        if (c1 == "N" || c1 == "n") {
            for (int i = 0; i < n; i++) { stud.push_back(ivedimas(m)); }
        } else {
            for (int i = 0; i < n; i++) { stud.push_back(generavimas(m)); }
        }
    }
    cout << "Galutini bala skaiciuoti pagal vidurki ar mediana? (V/M):"  << endl;
    cin >> c2;
    while (c2 != "V" && c2 != "v" && c2 != "M" && c2 != "m") {
        cout << "Ivestas simbolis turi buti V arba M! Pabandykite is naujo: "  << endl;
        cin >> c2;
    }
    if (c2 == "V" || c2 == "v") {
        cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) <<
             "Galutinis(vid.)" << endl;
        for (studentas a : stud) {
            Vidurkis(a, m);
        }
    } else {
        cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) <<
             "Galutinis(med.)" << endl;
        for (studentas a : stud) {
            Mediana(a, m);
        }
    }
}
