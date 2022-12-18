#include "mylib.h"
#include "funkc.h"

void nuskaitymas(vector<Studentas>& studentai, int& studsk, string pavadinimas)
{
    auto start = std::chrono::high_resolution_clock::now();

    ifstream failas;
    string eil, antraste, Vardas, Pavarde;
    vector<int> Paz;
    int ndkiekis, nd, Egz;
    try
    {
        failas.open(pavadinimas);
        if (!failas.is_open()) throw 0;
        getline(failas >> ws, antraste);
        stringstream stream(antraste);
        ndkiekis = (distance(istream_iterator<string>(stream), istream_iterator<string>())) - 3;

        while (getline(failas >> ws, eil))
        {
            Studentas studentas;
            stringstream stream(eil);
            stream >> Vardas >> Pavarde;
            for (int i = 0; i < ndkiekis; i++)
            {
                stream >> nd;
                Paz.push_back(nd);
            }
            stream >> Egz;
            //studentas.setStudentas(Vardas, Pavarde, Paz, Egz);
            studentas.setVardas(Vardas);
            studentas.setPavarde(Pavarde);
            studentas.setPazymiai(Paz);
            Paz.clear();
            studentas.setEgz(Egz);

            studentai.push_back(studentas);
        }
        studentai.shrink_to_fit();
        studsk = studentai.size();
        failas.close();
    }
    catch (int e)
    {
        cout << "Failas nerastas" << endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "CLASS (VEKTORIUS) Failo nuskaitymas uztruko: " << diff.count() << "s\n";
}
void nuskaitymas(list<Studentas>& studentai, int& studsk, string pavadinimas)
{
    auto start = std::chrono::high_resolution_clock::now();

    ifstream failas;
    string eil, antraste, vardas, pavarde;
    vector<int> paz;
    int ndkiekis, nd, egz;
    try
    {
        failas.open(pavadinimas);
        if (!failas.is_open()) throw 0;
        getline(failas >> ws, antraste);
        stringstream stream(antraste);
        ndkiekis = (distance(istream_iterator<string>(stream), istream_iterator<string>())) - 3;

        while (getline(failas >> ws, eil))
        {
            Studentas studentas;
            stringstream stream(eil);
            stream >> vardas >> pavarde;
            for (int i = 0; i < ndkiekis; i++)
            {
                stream >> nd;
                paz.push_back(nd);
            }
            stream >> egz;
            studentas.setVardas(vardas);
            studentas.setPavarde(pavarde);
            studentas.setPazymiai(paz);
            paz.clear();
            studentas.setEgz(egz);

            studentai.push_back(studentas);
        }
        studsk = studentai.size();
        failas.close();
    }
    catch (int e)
    {
        cout << "Failas nerastas" << endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "CLASS (LIST) Failo nuskaitymas uztruko: " << diff.count() << "s\n";
}
void naujasFailas(int studsk)
{

    // auto start = std::chrono::high_resolution_clock::now();
    string file;
    file = "studentai" + to_string(studsk) + ".txt";

    ofstream generuoti;
    generuoti.open(file);

    generuoti << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 0; i < 10; i++)
    {
        generuoti << setw(7) << "ND" + to_string(i + 1);
    };
    generuoti << setw(7) << "Egz.";
    generuoti << endl;//sukurta virsutine eilute su stulpeliu pavadinimais
    for (int i = 0; i < studsk; i++)   //failas uzpildomas duomenimis
    {
        generuoti << left << setw(20) << "Vardas" + to_string(i + 1) << setw(20) << "Pavarde" + to_string(i + 1);

        for (int j = 0; j < 11; j++)
        {
            generuoti << setw(7) << random(1, 10);
        }
        if (i != studsk - 1) generuoti << endl;
    }

    generuoti.close();
    // auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration < double>diff = end - start;
    //cout << "Failo sukurimas uztruko: " << diff.count() << "s\n";
}
void remove_if_skirstymas(vector<Studentas>& studentai, vector <Studentas>& minksti)
{
    auto start = std::chrono::high_resolution_clock::now();
    vector<Studentas>::iterator it;
    studentai.erase(remove_if(studentai.begin(), studentai.end(), [&minksti](Studentas naujas)
    {
        if (galutinis(mediana(naujas.getPazymiai()), naujas.getEgzaminas()) && galutinis(vidurkis(naujas.getPazymiai()), naujas.getEgzaminas()) < 5)
        {
            minksti.push_back(naujas);
            return true;
        }
        else
        {
            return false;
        }
    }), studentai.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "CLASS (VEKTORIUS REMOVE_IF) Skirstymas i kietus ir minkstus uztruko: " << diff.count() << "s\n";
}
void remove_if_skirstymas(list<Studentas>& studentai, list <Studentas>& minksti)
{
    auto start = std::chrono::high_resolution_clock::now();
    list<Studentas>::iterator it;
    studentai.erase(remove_if(studentai.begin(), studentai.end(), [&minksti](Studentas naujas)
    {
        if (galutinis(mediana(naujas.getPazymiai()), naujas.getEgzaminas()) && galutinis(vidurkis(naujas.getPazymiai()), naujas.getEgzaminas()) < 5)
        {
            minksti.push_back(naujas);
            return true;
        }
        else
        {
            return false;
        }
    }), studentai.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "(LIST REMOVE_IF) Skirstymas i kietus ir minkstus uztruko: " << diff.count() << "s\n";
}
void isvedimas_i_2_failus(vector<Studentas> studentai, vector<Studentas> minksti, int stud)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream output1, output2;
    output1.open("kieti" + to_string(stud) + ".txt");
    output1 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis(med.)/Galutinis(vid.)" << endl;
    output1 << string(80, '-') << endl;

    for (int i = 0; i < studentai.size(); i++)
    {
        output1 << setw(20) << left << studentai[i].getVardas() << setw(20) << left << studentai[i].getPavarde();
        output1 << fixed << setprecision(2) << setw(20) << left << galutinis(mediana(studentai[i].getPazymiai()), studentai[i].getEgzaminas()) << galutinis(vidurkis(studentai[i].getPazymiai()), studentai[i].getEgzaminas()) << endl;
    }
    output2.open("minksti" + to_string(stud) + ".txt");
    output2 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis(med.)/Galutinis(vid.)" << endl;
    output2 << string(80, '-') << endl;

    for (int i = 0; i < minksti.size(); i++)
    {
        output2 << setw(20) << left << minksti[i].getVardas() << setw(20) << left << minksti[i].getPavarde();
        output2 << fixed << setprecision(2) << setw(20) << left << galutinis(mediana(minksti[i].getPazymiai()), minksti[i].getEgzaminas()) << galutinis(vidurkis(minksti[i].getPazymiai()), minksti[i].getEgzaminas()) << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "Isvedimas i du failus uztruko: " << diff.count() << "s\n";
}
void isvedimas_i_2_failus_list(int studsk, list<Studentas> studentai, list<Studentas> minksti)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream output1, output2;
    output1.open("(list)kieti" + to_string(studsk) + ".txt");
    output1 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis(med.)/Galutinis(vid.)" << endl;
    output1 << string(80, '-') << endl;

    for (list<Studentas>::iterator IT = studentai.begin(); IT != studentai.end(); IT++)
    {
        output1 << setw(20) << left << (*IT).getVardas() << setw(20) << left << (*IT).getPavarde();
        output1 << fixed << setprecision(2) << setw(20) << left << galutinis(mediana((*IT).getPazymiai()), (*IT).getEgzaminas()) << galutinis(vidurkis((*IT).getPazymiai()), (*IT).getEgzaminas()) << endl;
    }
    output2.open("(list)minksti" + to_string(studsk) + ".txt");
    output2 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis(med.)/Galutinis(vid.)" << endl;
    output2 << string(80, '-') << endl;

    for (list<Studentas>::iterator IT = minksti.begin(); IT != minksti.end(); IT++)
    {
        output1 << setw(20) << left << (*IT).getVardas() << setw(20) << left << (*IT).getPavarde();
        output1 << fixed << setprecision(2) << setw(20) << left << galutinis(mediana((*IT).getPazymiai()), (*IT).getEgzaminas()) << galutinis(vidurkis((*IT).getPazymiai()), (*IT).getEgzaminas()) << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "Isvedimas i du failus uztruko: " << diff.count() << "s\n";
}
double mediana(vector<int> v)
{
    double m;
    if (v.size() != 0)
    {
        sort(v.begin(), v.end());
        if (v.size() % 2 != 0)
        {
            m = v[(v.size() - 1) / 2];
        }
        else
        {
            m = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
        }
    }
    else m = 0;
    return m;
}
double vidurkis(vector<int> v)
{
    double a;
    double suma;
    suma = accumulate(v.begin(), v.end(), 0);
    if (v.size() != 0)
    {
        a = suma / v.size();
    }
    else a = 0;
    return a;
}
double galutinis(double a, double egzam)
{
    double gal;
    gal = (0.4 * a) + (0.6 * egzam);
    return gal;
}
int random(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}
bool rusiav(const Studentas& s1, const Studentas& s2)
{
    return s1.getVardas() < s2.getVardas();
}
