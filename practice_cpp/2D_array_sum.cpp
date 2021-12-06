#include <iostream>
using namespace std;

int Sum(int (*arr)[4], int size);

int main()
{
    int data[3][4] = {{1, 2, 3, 4}, {9, 8, 7, 6}, {2, 4, 6, 8}};
    int total = Sum(data, 3);
    cout << total;
}


int Sum(int (*arr)[4], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

// int Sum(int arr[][4], int size)
// {
//     int sum = 0;
//     for (int i = 0; i < size; ++i)
//     {
//         for (int j = 0; j < 4; ++j)
//         {
//             sum += arr[i][j];
//         }
//     }
//     return sum;
// }