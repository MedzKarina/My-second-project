#include "funkcijos.hpp"

int main() {
    studentas asmuo1;
    vector<studentas> stud;
    int n, m;
    int c1, c2, c3;
    string c4;
    cout << "Irasykite 0, jeigu duomenis generuosime " << endl;
    cout << "Irasykite 1, jeigu vesite 'ranka'0
      arba nuskaitysite is failo." << endl;
    cin >> c1;
    
    while (c1 != 0 && c1 != 1) {
        cout << "Ivestas skaicius turi buti 0 arba 1! Pabandykite is naujo" << endl;
        cin >> c1;
    }
    if (c1 == 0) {
        int a;
        cout << "Kiek studentu duomenu generuoti?" << endl;
        cin >> a;
        gen(a);
        vector<studentas> v = Failo(a);
        isv(v, "1");
        cout << endl;
        exit(0);
    }
    cout << "Irasykite 0, jeigu duomenis nuskaitysime is failo" << endl;
    cout << "Irasykite 1, jeigu vesite 'ranka'." << endl;
    cin >> c2;
    while (c2 != 0 && c2 != 1) {
        cout << "Ivestas skaicius turi buti 0 arba 1! Pabandykite is naujo" << endl;
        cin >> c2;
    }
    if (c2 == 0) { Nuskaitymas(); }
    else {
        cout << "Iveskite studentu skaiciu:";
        cin >> n;
        cout << "Irasykite 0, jeigu pazymius generuosim atsitiktinai ir 1 jeigu vesime 'ranka': ";
        cin >> c3;
        while (c3 != 0 && c3 != 1) {
            cout << "Ivestas skaicius turi buti 0 arba 1! Pabandykite is naujo" << endl;
            cin >> c3;
        }
        if (c3 == 1) {
            for (int i = 0; i < n; i++) { stud.push_back(ivedimas(m)); }
        } else {
            for (int i = 0; i < n; i++) { stud.push_back(generavimas(m)); }
        }
    }
    cout << "Galutini bala skaiciuoti pagal vidurki ar mediana? (V/M):";
    cin >> c4;
    while (c4 != "V" && c4 != "v" && c4 != "M" && c4 != "m") {
        cout << "Negaliojantis pasirinkimas, bandykite dar karta:";
        cin >> c4;
    }
    if (c4 == "V" || c4 == "v") {
        cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) << "Galutinis(vid.)" << endl;
        for (int i = 0; i < n; i++) {
            Vidurkis(stud[i], m);
        }
    } else {
        cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) <<
             "Galutinis(med.)" << endl;
        for (int i = 0; i < n; i++) {
            Mediana(stud[i], m);
        }
    }
}
