#include "funkcijos.hpp"

string pazGeneravimas() {
    vector<string> paz;
    for (int i = 0; i < 5; i++) {
        paz.push_back(std::to_string(rand() % 10 + 1) + " ");
    }
    string p = std::accumulate(paz.begin(), paz.end(), std::string(""));
    return p;
};

void gen(int x) { //generuojamas sarasas
    string name = "stud" + std::to_string(x) + ".txt";
    ofstream failas(name);
    failas << "\tVardas" << "\tPavarde" << "\t Pazymiai" << endl;
    for (int i = 1; i < x + 1; i++) {
        string info = "\tVardas" + std::to_string(i) + "\tPavarde" + std::to_string(i) + " " + pazGeneravimas() + "\n";
        failas << info;
    }
};

list<studentas> nusk(int x) {
    Timer t;
    string name = "stud" + std::to_string(x) + ".txt";
    std::ifstream failas(name);
    list<studentas> stud;
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
            failas >> asmuo.egz;
            double vid = double(accumulate(paz.begin(), paz.end(), 0)) / 4;
            asmuo.gal = vid * 0.4 + asmuo.egz * 0.6;
            stud.push_back(asmuo);
            paz.clear();
        }
        failas.close();
        cout << "Failo is " << x << " irasu nuskaitymo laikas:" << t.elapsed() << endl;
    } else cout << "Klaida atidarant faila";
    return stud;

};

void isv(list<studentas> l, string x) {
    studentas asmuo;
    Timer t;
    list<studentas> m;
    list<studentas> n;
    for (studentas a : l) {
        if (a.gal >= 5.0) {
            m.push_back(a);
        } else n.push_back(a);
    }
    cout << "Studentu isskirstymas i 2 grupes uztruko:" << t.elapsed() << endl;
    ofstream f1("kietiakai" + x);
    ofstream f2("nuskriaustukai" + x);
    for (studentas a : l) {
        f1 << left << setw(15) << a.vardas
           << left << setw(15) << a.pavarde << left << setw(15) << a.gal << endl;
    }
    for (studentas a : l) {
        f2 << left << setw(15) << a.vardas
           << left << setw(15) << a.pavarde << left << setw(15) << a.gal << endl;
    }
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
    cin >> asmuo.egz;
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
        asmuo.med = double(paz[(paz.size() - 1) / 2] + paz[(paz.size() - 1) / 2 + 1]) / 2;
    } else asmuo.med = paz[(paz.size() - 1) / 2];
    asmuo.vid = (double) sum / (double) (paz.size());
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
    cin >> asmuo.egz;
    cout << "Iveskite namu darbu pazymiu skaiciu:";
    cin >> s;
    for (int i = 0; i < s; i++) {
        paz.push_back(rand() % 10 + 1);
        cout << "Sugeneruotas pazymys:" << paz.back() << endl;
    }
    sum = accumulate(paz.begin(), paz.end(), 0);
    sort(paz.begin(), paz.end());
    if ((s - 1) % 2 == 0) { asmuo.med = double(paz[(s - 1) / 2] + paz[(s - 1) / 2 + 1]) / 2; }
    else asmuo.med = paz[(s - 1) / 2];
    asmuo.vid = (double) sum / (double) s;
    return asmuo;
    paz.clear();
}

studentas nuskaitymas() {
    vector<studentas> stud;
    std::ifstream failas;
    string pav;
    failas.open("stud10.txt");
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
            failas >> asmuo.egz;
            asmuo.vid = double(accumulate(paz.begin(), paz.end(), 0)) / n;
            asmuo.med = paz[4 / 2];
            stud.push_back(asmuo);
            paz.clear();
        }
        sort(stud.begin(), stud.end(), [](const studentas &a, const studentas &b) {
            return a.vardas < b.vardas;
        });

        cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(20) <<
             "Galutinis(vid.)" << left << setw(20) << "Galutinis(med.)" << endl;
        for (auto &i: stud) {
            cout << left << setw(15) << i.vardas
                 << left << setw(15) << i.pavarde
                 << left << setw(20) << setprecision(3) << (i.vid * 0.4 + i.egz * 0.6)
                 << left << setw(20) << setprecision(3) << (i.med * 0.4 + i.egz * 0.6) << endl;
        }
        failas.close();
    } else { cout << "Klaida atidarant faila" << endl; }
}

void Vidurkis(studentas temp, int n) {
    cout << left << setw(15) << temp.vardas
         << left << setw(15) << temp.pavarde
         << left << setw(20) << setprecision(3) << (temp.vid * 0.4 + temp.egz * 0.6) << endl;
}

void Mediana(studentas temp, int n) {
    cout << left << setw(15) << temp.vardas
         << left << setw(15) << temp.pavarde
         << left << setw(20) << setprecision(3) << (temp.med * 0.4 + temp.egz * 0.6) << endl;
}
