#include <iostream>
using namespace std;

int main(){
    double ch[10];
    int count = 0;
    cout << "Enter values: ";
    while (cin >> ch[count] && count < 10)
    {
        ++count;
    }
    double sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += ch[i];
    }
    double avg = sum / count;
    int larger = 0;
    for (int i = 0; i < count; ++i)
    {
        if (ch[i] > avg)
        {
            ++larger;
        }
    }
    cout << "Average: " << avg << endl;
    cout << "Larger: " << larger << endl;
    return 0;
}