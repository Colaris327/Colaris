#include <iostream>
#include <cstring>
using namespace std;

const int Size = 80;
char * left(const char * str, int n = 1);

int main()
{
    char str[Size];
    cout << "Enter a string: ";
    cin.get(str, Size);
    char * sample = left(str);
    cout << sample << endl;
    delete [] sample; // free old string
    sample = left(str, 23551);
    cout << sample << endl;
    delete [] sample;
    return 0;
}


char * left(const char * str, int n)
{
    if (n < 0)
        n = 0;
    int len = strlen(str);
    n = (n < len) ? n : len;
    char * ps = new char[n + 1];
    int i;
    for (i = 0; i < n; ++i)
        ps[i] = str[i];
    while (i <= n)
        ps[i++] = '\0';
    return ps;
}