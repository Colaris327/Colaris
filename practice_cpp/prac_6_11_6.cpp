#include <iostream>
#include <cstring>
using namespace std;

struct Patron
{
    string name;
    double donation;
};

int main()
{
    cout << "How many people donate: ";
    int people;
    cin >> people;
    Patron array[people];
    for (int i = 0; i < people; ++i)
    {
        cout << "Name: ";
        cin >> array[i].name;
        cout << "Donation: ";
        cin >> array[i].donation;
    }
    cout << "Grand patron: " << endl;
    bool n = true; // to verify None
    for (int i = 0; i < people; ++i)
    {
        if (array[i].donation >= 10000)
        {
            cout << array[i].name << endl;
            n = false;
            continue;
        }
    }
    if (n == true) cout << "none\n";
    n = true;
    cout << "Patron: " << endl;
    for (int i = 0; i < people; ++i)
    {
        if (array[i].donation < 10000)
        {
            cout << array[i].name << endl;
            n = false;
            continue;
        }
    }
    if (n == true) cout << "none\n";
    return 0;
}
