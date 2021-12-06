#include <iostream>
using namespace std;
enum {red, orange, yellow, green, blue};

int main()
{
    cout << "Enter code(0-4) : ";
    int code;
    cin >> code;
    while (code >= red && code <= blue)
    {
        switch (code)
        {
            case red : cout << "RED" << endl; break;
            case orange : cout << "ORANGE" << endl; break;
            case yellow : cout << "YELLOW" << endl; break;
            case green : cout << "GREEN" << endl; break;
            case blue : cout << "BLUE" << endl; break;
        }
        cout << "Enter code(0-6) : ";
        cin >> code;
    }
    cout << "Bye";
    return 0;
}