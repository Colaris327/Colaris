// page 559
#include "exc_mean.h"
#include <iostream>
#include <cmath>

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometrical mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
            cout << "Enter newxt two numbers: ";
        }
        catch(bad_hmean & hg)
        {
            hg.mesg();
            cout << "Try again\n";
            continue;
        }
        catch(bad_gmean & bg)
        {
            bg.mesg();
            cout << bg.mesg();
            cout << "Values used: " << bg.v1 << " and " << bg.v2 << endl;
            cout << "Sorry, you don't get to play anymore\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}