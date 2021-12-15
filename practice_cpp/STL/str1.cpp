// introducing the string class
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string one ("Lottery Winner! "); // 1
    cout << one << endl;

    string two (20, '$'); // 2
    cout << two << endl;

    string three (one); // 3
    cout << three << endl;

    one += "Oops!"; // overload +, =
    cout << one << endl;

    two = "Sorry! That was";
    three[0] = 'P';
    string four; // 4
    four = two + three; // overload +, =
    cout << four << endl;

    char alls[] = "All's well that ends well";
    string five (alls, 20); // 5
    cout << five << endl;

    string six (alls + 6, alls + 10); // 6
    cout << six << endl;
    string seven (&five[6], &five[10]);
    cout << seven << endl;
}