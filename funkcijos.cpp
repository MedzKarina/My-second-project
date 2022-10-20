#include "funkcijos.hpp"

string PazymioGeneravimas() {
    vector<string> paz;
    for (int i = 0; i < 5; i++) {
        paz.push_back(std::to_string(rand() % 10 + 1) + " ");
    }
    string p = std::accumulate(paz.begin(), paz.end(), std::string(""));
    return p;
};

void gen(int x) { //generuojamas sarasas
    Timer t;
    string name = "studentai" + std::to_string(x) + ".txt";
    ofstream failas(name);
    failas << "\tVardas" << "\tPavarde" << "\t Pazymiai" << endl;
    for (int i = 1; i < x + 1; i++) {
        failas << "\tVardas" << i << "\tPavarde" << i << " " << PazymioGeneravimas() << endl;
    }
    cout << "Failo is " << x << " irasu sukurimo laikas:" << t.elapsed() << endl;
};

vector<studentas> Failo(int x) {
    Timer t;
    string name = "studentai" + std::to_string(x) + string(".txt");
    std::ifstream failas(name);
    vector<studentas> stud;
    if (failas.is_open()) {
        string eil;
        vector<int> paz;
        int p;
        int n = 4;
        std::stringstream s(eil);
        while (getline(failas, eil)) {
            studentas asmuo;
            failas >> asmuo.vardas;
            failas >> asmuo.pavarde;
            for (int i = 0; i < n; i++) {
                failas >> p;
                paz.push_back(p);
            }
            failas >> asmuo.egzaminas;
            double vid = double(accumulate(paz.begin(), paz.end(), 0)) / 4;
            asmuo.galutinis = vid * 0.4 + asmuo.egzaminas * 0.6;
            stud.push_back(asmuo);
            paz.clear();
        }
        failas.close();
        cout << "Failo is " << x << " irasu nuskaitymo laikas:" << t.elapsed() << endl;
    } else cout << "Klaida atidarant faila";
    return stud;

};

void isv(vector<studentas> v, string x) {
    studentas asmuo;
    Timer t;
    vector<studentas> m;
    vector<studentas> n;
    for (int i = 0; i < v.size() - 1; i++) {
        asmuo = v[i];
        if (asmuo.galutinis >= 5.0) {
            m.push_back(asmuo);
        } else n.push_back(asmuo);
    }
    cout << "Studentu isskirstymas i 2 grupes uztruko:" << t.elapsed() << endl;
    t.reset();
    ofstream f1("kietiakiai" + x);
    ofstream f2("nuskriaustukai" + x);
    for (int i = 0; i < m.size(); i++) {
        asmuo = m[i];
        f1 << left << setw(15) << asmuo.vardas
           << left << setw(15) << asmuo.pavarde << left << setw(15) << asmuo.galutinis << endl;
    }
    for (int i = 0; i < n.size(); i++) {
        asmuo = n[i];
        f2 << left << setw(15) << asmuo.vardas
           << left << setw(15) << asmuo.pavarde << left << setw(15) << asmuo.galutinis << endl;
    }
    cout << "Studentu isskirstymas i 2 failus uztruko:" << t.elapsed() << endl;
};

studentas ivedimas(int &n) {
    vector<int> paz;
    int p;
    int sum = 0;
    studentas asmuo;
    cout << "Iveskite varda:";
    cin >> asmuo.vardas;
    cout << "Iveskite pavarde:";
    cin >> asmuo.pavarde;
    cout << "Iveskite egzamino pazymi:";
    cin >> asmuo.egzaminas;
    string command = "N";
    while (command != "T" && command != "t") {
        cout << "Iveskite  pazymi:";
        cin >> p;
        paz.push_back(p);
        cout << "Baigti pazymiu ivedima?(T/N)";
        cin >> command;
        cout << endl;
    }
    sum = std::accumulate(paz.begin(), paz.end(), 0);
    sort(paz.begin(), paz.end());
    if ((paz.size() - 1) % 2 == 0) {
        asmuo.mediana = double(paz[(paz.size() - 1) / 2] + paz[(paz.size() - 1) / 2 + 1]) / 2;
    } else asmuo.mediana = paz[(paz.size() - 1) / 2];
    asmuo.vidurkis = (double) sum / (double) (paz.size());
    return asmuo;
    paz.clear();
}

studentas generavimas(int &n) {
    vector<int> paz;
    int sum, s;
    studentas asmuo;
    cout << "Iveskite varda:";
    cin >> asmuo.vardas;
    cout << "Iveskite pavarde:";
    cin >> asmuo.pavarde;
    cout << "Iveskite egzamino pazymi:";
    cin >> asmuo.egzaminas;
    cout << "Iveskite namu darbu pazymiu skaiciu:";
    cin >> s;
    for (int i = 0; i < s; i++) {
        paz.push_back(rand() % 10 + 1);
        cout << "Sugeneruotas pazymys:" << paz.back() << endl;
    }
    sum = accumulate(paz.begin(), paz.end(), 0);
    sort(paz.begin(), paz.end());
    if ((s - 1) % 2 == 0) { asmuo.mediana = double(paz[(s - 1) / 2] + paz[(s - 1) / 2 + 1]) / 2; }
    else asmuo.mediana = paz[(s - 1) / 2];
    asmuo.vidurkis = (double) sum / (double) s;
    return asmuo;
    paz.clear();
}

studentas Nuskaitymas() {
    vector<studentas> stud;
    std::ifstream failas;
    string pav;
    failas.open("kursiokai10000.txt");
    if (failas.is_open()) {
        string eil;
        vector<int> paz;
        int p;
        int n = 0;
        getline(failas, eil);
        std::stringstream s(eil);
        string z;
        while (s >> z){
            n += 1;
        }
        n -= 3;
        while (getline(failas, eil)) {
            studentas asmuo;
            failas >> asmuo.vardas;
            failas >> asmuo.pavarde;
            for (int i = 0; i < n; i++) {
                failas >> p;
                paz.push_back(p);
            }
            failas >> asmuo.egzaminas;
            asmuo.vidurkis = double(accumulate(paz.begin(), paz.end(), 0)) / n;
            asmuo.mediana = paz[4 / 2];
            stud.push_back(asmuo);
            paz.clear();
        }
        sort(stud.begin(), stud.end(), [](const studentas &a, const studentas &b) {
            return a.vardas < b.vardas;
        });

        cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) <<
             "Galutinis (vid.)" << left << setw(20) << "Galutinis (med.)" << endl;
        for (auto &i: stud) {
            cout << left << setw(15) << i.vardas
                 << left << setw(15) << i.pavarde
                 << left << setw(20) << setprecision(3) << (i.vidurkis * 0.4 + i.egzaminas * 0.6)
                 << left << setw(20) << setprecision(3) << (i.mediana * 0.4 + i.egzaminas * 0.6) << endl;
        }
        failas.close();
    } else { cout << "Failas nera atidarytas!" << endl; }
}

void Vidurkis(studentas temp, int n) {
    cout << left << setw(15) << temp.vardas
         << left << setw(15) << temp.pavarde
         << left << setw(20) << setprecision(3) << (temp.vidurkis * 0.4 + temp.egzaminas * 0.6) << endl;
}

void Mediana(studentas temp, int n) {
    cout << left << setw(15) << temp.vardas
         << left << setw(15) << temp.pavarde
         << left << setw(20) << setprecision(3) << (temp.mediana * 0.4 + temp.egzaminas * 0.6) << endl;
}
