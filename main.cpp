#include "student.h"

int main()
{
    int c;
    srand(time(0));

    cin.exceptions(std::istream::failbit);
    try
    {
        cout << "Studentu kiekis: ";
        cin >> c;
        Gen2(c);
    }


    catch(const ios_base::failure& e)
    {
        cout << "Klaida!" << endl;
        cout << e.what() << endl;
    }

    return 0;
}
