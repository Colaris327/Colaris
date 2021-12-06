#include <iostream>
using namespace std;

const int Cities = 5;
const int Years = 4;

int main()
{
    // char *cities[Cities] =
    // {
    //     "Gribble City",
    //     "Gribbletown",
    //     "New Gribble",
    //     "San Gribble",
    //     "Gribble Vista"
    // };

    // char cities[Cities][25] =
    // {
    //     "Gribble City",
    //     "Gribbletown",
    //     "New Gribble",
    //     "San Gribble",
    //     "Gribble Vista"
    // };
    
    string cities[Cities] =
    {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };
    
    
    int maxtemp[Years][Cities] =
    {
        {95, 99, 86, 100, 104},
        {95, 97, 90, 106, 102},
        {96, 100, 94, 107, 105},
        {97, 102, 89, 108, 104}
    };

    cout << "Maximum temperatures for 2002-2005\n\n";
    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ": \t";
        for (int year = 0; year < Years; ++year)
        {
            cout << maxtemp[year][city] << " ";
        }
        cout << endl;
    }
    return 0;
}