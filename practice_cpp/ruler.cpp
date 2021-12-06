#include <iostream>
using namespace std;

void Subdivide(char arr[],int low, int high, int level);
const int Len = 66;
const int Divs = 6;

int main()
{
    char ruler[Len];
    int i;
    for (i = 1; i < Len - 2; ++i)
        ruler[i] = ' ';
    ruler[Len - 1] = '\0';
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    cout << ruler << endl;
    for (i = 1; i <= Divs; ++i)
    {
        Subdivide(ruler, min, max, i);
        cout << ruler << endl;
        for (int j = 1; j  < Len - 2; ++j)
            ruler[i] = ' '; // reset
    }
    return 0;
}

void Subdivide(char arr[],int low, int high, int level)
{
    if (level == 0)
        return;
    int mid = (low + high) / 2;
    arr[mid] = '|';
    Subdivide(arr, low, mid, level - 1);
    Subdivide(arr, mid, high, level - 1);
}