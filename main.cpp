#include "mylib.hpp"

struct studentas {
    string vardas, pavarde;
    int nd[10]; //namu darbai
    double egz; //egzamino rezultatas
    double galutinis;
};

void print(studentas& kint);
void pild(studentas& kint, int x);
studentas studentai[30]; 

int main()
{
    double m; //studentu skaicius
    cout << "Iveskite studentu skaiciu: "; cin >> m; cout << endl;
    {
        int x;
        cout << "Jeigu norite, kad galutinis balas butu su vidurkiu rasykite '0', jeigu su mediana '1': "; cin >> x; cout << endl;
        for (int i = 0; i < m; i++)
        pild(studentai[i], x); //bus pildoma informacija apie studenta
        cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(10) << ((x == 0) ? "Galutinis (vid.)" : "Galutinis(med.)") << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < m; i++)
            print(studentai[i]); //spausdinami rezultatai 
    }
}

void pild(studentas& kint, int x) //informacijos pildymo funkcija
{
    double n; //namu darbu skaicius
    int sk; 
    double sum = 0; //visu pazymiu suma
    double vid = 0; // visu pazymiu vidurkis
    double mediana = 0;
    cout << "Iveskite studento vardo ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
    cout << "Parasykite, jeigu zinote namu darbu skaiciu (1-10), jeigu nezinote, parasykite '-1'" << endl;   
    cin >> sk;
    if (sk == -1)
    {
        int k = 1; //pazymio vieta masyve nd
        cout << "Ivedus 0, programa supras, kad baigete nd pazymiu ivedima" << endl;
        cout << "Iveskite namu darbu pazymius: " << endl;
        
        while (k > 0)
        {
            cin >> n;
            if (n > 0 && n <= 10)
            {
              kint.nd[k-1] = n;
              sum = sum + kint.nd[k-1];
              k++;
            }
            else
            {
                break;
            }
        }
        vid = sum / k;
        sort(kint.nd, kint.nd + k);
        if (k % 2 != 0)
        {
            mediana = (double)kint.nd[k / 2];
        }
        else
        {
            mediana = (double)(kint.nd[(k - 1) / 2] + kint.nd[k / 2]) / 2.0;
        }
        cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;
    }
    if (sk > 0) 
    {
          cout << "Iveskite namu darbu pazymius: " << endl;
          for (int i = 0; i < sk; i++)
          {
             cin >> kint.nd[i];
             sum = sum + kint.nd[i];
          }
        vid = sum / sk; //vidurkis
        cout << "Iveskite egzamino pazymi: "; cin >> kint.egz;
        if (sk % 2 != 0)
            mediana = (double)kint.nd[sk / 2];
        else
        {
           mediana =  (double)(kint.nd[(sk - 1) / 2] + kint.nd[sk / 2]) / 2.0;
        }
    }
    if (x == 0) {
        kint.galutinis = 0.4 * vid + 0.6 * kint.egz; //apskaiciuojamas galutinis balas
    }
    else {
        kint.galutinis = 0.4 * mediana + 0.6 * kint.egz;
    }
}

void print(studentas& kint) //spausdinimo funkcija
{
    cout << left << setw(12) << kint.pavarde << setw(12) << kint.vardas << setw(10) << setprecision(3) << kint.galutinis << endl;
}
