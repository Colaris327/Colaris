#include <iostream>
#include <fstream> // file I/O support
#include <cstdlib> // support for exit()
using namespace std;
const int SIZE = 60;

int main()
{
    char filename[SIZE];
    ifstream inFile; // object for handling file input
    cout << "Enter file name : "; // scores.txt
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file" << endl;
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;
    inFile >> value; // get value // just like using "cin >>"
    
    while (inFile.good()) // while input good or not at EOF
    {
        sum += value;
        ++count;
        inFile >> value;
    }

    if (inFile.eof())
        cout << "End of file reached." << endl;
    else if (inFile.fail())
        cout << "Input terminated by data mismatch" << endl;
    else
        cout << "Input terminated for unknown reason" << endl;
    
    if (count == 0)
        cout << "No data in the file" << endl;
    else
    {
        cout << "Items read: " << count <<endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    
    inFile.close();
    return 0;
}
