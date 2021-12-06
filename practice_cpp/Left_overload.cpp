#include <iostream>
using namespace std;

unsigned long Left(unsigned long num, unsigned ct);
char * Left(const char *str, int n = 1);

int main()
{
    char *trip = "Hawaii!!!";
    unsigned long n = 12345678;
    int i;
    char *temp;

    for (i = 1; i < 10; ++i)
    {
        cout << Left(n, i) << endl;
        temp = Left(trip, i);
        cout << temp << endl;
        delete [] temp;
    }
    return 0;
}


unsigned long Left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;
    if (ct == 0 || num == 0)
        return 0;
    while (n /= 10)
        digits++;
    if (digits > ct)
    {
        ct = digits - ct;
        while(ct--)
            num /= 10;
        return num;
    }
    else
        return num;
}

char * Left(const char *str, int n)
{
    if (n < 0)
        n = 0;
    char *p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; ++i) // use str[i] to avoid n > length of str
        p[i] = str[i];
    while (i <= n)
    {
        p[i] = '\0';
        i++;
    }
    return p;
}