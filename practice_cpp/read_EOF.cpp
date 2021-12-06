#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;
    // cin.get(ch);
    while (cin.get(ch)) // use <CTRL><Z> to stop
    {
        cout << ch;
        ++count;
        //cin.get(ch);
    }
    cout << endl << count;
    return 0;
}