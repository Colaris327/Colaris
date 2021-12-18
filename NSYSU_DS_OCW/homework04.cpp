// knight with recursion
#include <iostream>
using namespace std;

int ** CreatBoard(int size)
{
    int **array = new int*[size + 4]; // +4 is for boundary
    for (int i = 0; i < size + 4; i++)
        array[i] = new int[size + 4];
    for (int i = 0; i < size + 4; i++)
        for (int j = 0; j < size + 4; j++)
            array[i][j] = 1;
    for (int i = 2; i < size + 2; i++)
        for (int j = 2; j < size + 2; j++)
            array[i][j] = 0;
    return array;
}

void PrintBoard(int **arr, int size)
{
    for (int i = 2; i < size + 2; i++)
    {
        for (int j = 2; j < size + 2; j++)
        {
            cout.width(3);
            cout << arr[i][j];
        }
        cout << endl;
    }        
}

bool isSafe(int **arr, int x, int y)
{
    return arr[x][y] == 0;
}

bool rec(int ** arr, int size, int x, int y, int step)
{
    if (step == size * size)
    {
        if (isSafe(arr, x, y))
        {
            arr[x][y] = step;
            return true;
        }
    }
    if (isSafe(arr, x, y))
    {
        arr[x][y] = step;
        
        if (rec(arr, size, x - 2, y + 1, step + 1)) // K1
            return true;
        if (rec(arr, size, x - 1, y + 2, step + 1)) // K2
            return true;
        if (rec(arr, size, x + 1, y + 2, step + 1)) // K3
            return true;
        if (rec(arr, size, x + 2, y + 1, step + 1)) // K4
            return true;
        if (rec(arr, size, x + 2, y - 1, step + 1)) // K5
            return true;
        if (rec(arr, size, x + 1, y - 2, step + 1)) // K6
            return true;
        if (rec(arr, size, x - 1, y - 2, step + 1)) // K7
            return true;
        if (rec(arr, size, x - 2, y - 1, step + 1)) // K8
            return true;
        
        arr[x][y] = 0;
        return false;
    }

    return false;
}


int main()
{
    int size;
    for (size = 1; size <= 6; size++)
    {
        int **board = CreatBoard(size);
        if (rec(board, size, 2, 2, 1)) // start from(2, 2) because of the wall
            PrintBoard(board, size);
        else
            cout << "no solution\n";
        cout << endl;
    }
    return 0;
}

