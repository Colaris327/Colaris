#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<int> arr (1);
    arr[0] = 1;
    cout << "Enter the    !\b\b\b";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int size = arr.size();
        int a;
        for (a = 0; a < size; a++)
            arr[a] *= i;
        for (a = 0; a < size - 1; a++)
        {
            if (arr[a] >= 10)
            {
                arr[a + 1] += arr[a] / 10;
                arr[a] = arr[a] % 10;
            }
        }
        while (arr[size - 1] > 10)
        {
            arr.push_back(0);
            arr[size] = arr[size - 1] / 10;
            arr[size - 1] = arr[size - 1] % 10;
            size++;
        }

        cout << i << "! = ";
        for (a = arr.size() - 1; a >= 0 ; a--)
            cout << arr[a];
        cout << endl;
    }
    return 0;
}