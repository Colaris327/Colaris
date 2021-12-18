// magic square
#include <iostream>
using namespace std;

int ** CreateArray(int size)
{
    int **arr = new int *[size];
    for (int i = 0; i < size; i++)
        arr[i] = new int [size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            arr[i][j] = 0;
    return arr;
}

void PrintArray(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout.width(3);
            cout << arr[i][j];
        }
        cout << endl;
    }
}

struct Point
{
    int vertical;
    int horizon;
};

void MagicSquare(int size)
{
    int **square = CreateArray(size);
    Point point {0, size / 2};
    Point current = point; // current is to check whether the next position be used or not
    int count = 1;
    while (count <= size * size)
    {
        if (square[current.vertical][current.horizon] != 0)
        {
            square[point.vertical + 1][point.horizon] = count++;
            point.vertical++;
        }
        else
        {
            point = current;
            square[point.vertical][point.horizon] = count++;
        }
        if (point.vertical == 0)
            current.vertical = size - 1;
        else
            current.vertical = point.vertical - 1;
        if (point.horizon == 0)
            current.horizon = size - 1;
        else
            current.horizon = point.horizon - 1;
    }
    PrintArray(square, size);
}

int main()
{
    cout << "Enter size: ";
    int size;
    cin >> size;
    MagicSquare(size);
    return 0;
}