// page 542
// compile with tv.cpp
#include <iostream>
#include "tv.h"

int main()
{
    using std::cout;
    cout << "Initial setting for 27\" TV:\n";
    Tv s27;
    s27.settings();
    s27.onoff();
    s27.chanup();
    cout << "\nAdjusted setting for 27\" TV:\n";
    s27.settings();

    Remote grey;
    grey.set_chan(s27, 10);
    grey.volup(s27);
    grey.volup(s27);
    cout << "\n27\" setting after using remote:\n";
    s27.settings();

    Tv s32(Tv::On);
    s32.set_mode();
    grey.set_chan(s32, 28);
    cout << "\n32\" settings:\n";
    s32.settings();
    return 0;
}