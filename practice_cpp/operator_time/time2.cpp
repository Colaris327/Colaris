#include "time.h"
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "Weeding Time: ";
    weeding.Show();
    
    cout << "Total worktime: ";
    total = weeding + waxing;
    total.Show();

    cout << "Weeding Time - Waxing Time: ";
    diff = weeding - waxing;
    diff.Show();

    cout << "Adjusted Work Time: ";
    adjusted = total * 1.5;
    adjusted.Show();

    system("pause");
    return 0;
}