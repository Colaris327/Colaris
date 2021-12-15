// page 647
#include <valarray>
#include <iostream>
#include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint;
void show(const vint & v, int col);

int main()
{
    using std::slice;
    using std::cout;
    vint valint (SIZE);
    int i;
    for (i = 0; i < SIZE; i++)
        valint[i] = rand() % 10;
    cout << "Original array:\n";
    show(valint, 3);

    vint vcol (valint[slice(1, 4, 3)]);
    cout << "Second column:\n";
    show(vcol, 1);

    vint vrow (valint[slice(3, 3, 1)]);
    cout << "Second row:\n";
    show(vrow, 3);

    valint[slice(2, 4, 3)] = 10;
    cout << "Set last column to 10:\n";
    show(valint, 3);

    cout << "Set first column to sum of next two:\n";
    // + not defined for slices, so convert to valarray<int>
    valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);
    show(valint, 3);

    return 0;
}

void show(const vint & v, int col)
{
    using std::cout;
    using std::endl;
    int lim = v.size();
    for (int i = 0; i < lim; i++)
    {
        cout.width(3);
        cout << v[i];
        if (i % col == col - 1)
            cout << endl;
        else
            cout << ' ';
    }
    if (lim % col != 0)
        cout << endl;
}