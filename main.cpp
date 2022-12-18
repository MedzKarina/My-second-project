#include "mylib.h"
#include "funkc.h"


int main()
{
    vector<Studentas> studentai, minksti;
    list<Studentas> student, minkst;
    int n, nd, stud;
    string m, pavadinimas;

    cout << "Iveskite 1, jeigu norite nuskaityti turimus failus; \narba bet koki kita simboli, jei norite sugeneruoti naujus failus: \n";
    cin >> m;

    if (m == "1")
    {
        while (true)
        {
            cout << "\nIveskite failo, kuri norite nuskaityti pavadinima, arba 0, jei baigete darba \n" ;
            cin >> pavadinimas;
            if (pavadinimas == "0")break;
            else
            {
                nuskaitymas(studentai, stud, pavadinimas);
                sort(studentai.begin(), studentai.end(), rusiav);

                remove_if_skirstymas(studentai, minksti);
                isvedimas_i_2_failus(studentai, minksti, stud);

            }
        }
    }
    else
    {
        while (true)
        {
            cout << "Iveskite, kiek studentu norite sugeneruoti, jei baigete darba, iveskite 0:  ";
            cin >> n;
            if (n == 0) break;
            else
            {
                try
                {
                    if (n < 0) throw 0;
                    naujasFailas(n);
                    pavadinimas = "studentai" + to_string(n) + ".txt";
                    cout << "Sukurto failo pavadinimas: " << pavadinimas << endl;

                    //       VECTOR:
                    nuskaitymas(studentai, stud, pavadinimas);
                    sort(studentai.begin(), studentai.end(), rusiav);

                    remove_if_skirstymas(studentai, minksti);
                    isvedimas_i_2_failus(studentai, minksti, stud);

                }
                catch (int e)
                {
                    cout << "Per mazas studentu kiekis \n";
                }
            }
        }
    }
}
