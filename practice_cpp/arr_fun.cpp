#include <iostream>
const int Max = 5;

void Show_arr(const double arr[], int n); // Don't change data
int Fill_array(double arr[], int limit);
void Revalue(double rate, double arr[], int n);

int main()
{
    using namespace std;
    double arr[Max];
    int size = Fill_array(arr, Max);
    Show_arr(arr, size);
    cout << "Enter the rate: ";
    double rate;
    cin >> rate;
    Revalue(rate, arr, size);
    Show_arr(arr, size);
    return 0;
}


int Fill_array(double arr[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; ++i)
    {
        cout << "Enter the #" << i + 1 << " value: ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "ERROR!!!" << endl;
            break;
        }
        else if (temp < 0)
            break;
        arr[i] = temp;
    }
    return i;
}

void Show_arr(const double arr[], int n)
{
    using namespace std;
    for (int i = 0; i < n; ++i)
    {
        cout << "Property #" << i + 1 << ": $" << arr[i];
        cout << endl;
    }
}

void Revalue(double rate, double arr[], int n)
{
    for (int i = 0; i < n; ++i)
        arr[i] *= rate;
}