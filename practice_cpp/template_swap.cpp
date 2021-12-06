#include <iostream>
using namespace std;

template <class T>
void SWAP(T & a, T & b);

int main()
{
    int i = 10, j = 20;
    cout << "i = " << i << ". " << "j = " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    SWAP(i, j);
    cout << "i = " << i << ". " << "j = " << j << ".\n\n";

    double x = 24.5, y = 71.7;
    cout << "x = " << x << ". " << "y = " << y << ".\n";
    cout << "Using compiler-generated double swapper:\n";
    SWAP(x, y);
    cout << "x = " << x << ". " << "y = " << y << ".\n";
    return 0;
}


template <class T>
void SWAP(T & a, T & b)
{
    T temp = a;
    a = b;
    b = temp;
}