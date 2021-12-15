// Random walk
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

using VECTOR::Vector;
using namespace std;

int main()
{
    Vector result(0.0, 0.0);
    Vector step;
    double target;
    double dstep;
    srand(time(0));
    double direction;
    unsigned long steps = 0;
    cout << "Enter target distance(q to quit): ";
    while(cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.set(dstep, direction, 'p');
            steps++;
            result = result + step;
        }

        cout << "After " << steps << " steps, the subject has the following location:\n";
        cout << result << endl << "or\n";
        result.polar_mode();
        cout << result << endl;
        cout << "Average outward distanse per step = " << result.magval() / steps << endl;

        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance(q to quit): ";
    }
    system("pause");
    return 0;
}