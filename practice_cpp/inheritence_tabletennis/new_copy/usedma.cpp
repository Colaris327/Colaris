// page 465
// compile with dma.cpp
#include "dma.h"
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt ("Portabelly", 8);
    lacksDMA ballon ("red", "Blimpo", 4);
    hasDMA map ("Mercator", "Buffalo keys", 5);

    cout << shirt << endl;
    cout << ballon << endl;
    cout << map << endl;

    lacksDMA ballon2 (ballon);
    hasDMA map2;
    map2 = map;
    cout << ballon2 << endl;
    cout << map2 << endl;

    return 0;
}