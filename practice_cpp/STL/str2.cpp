// page 597
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    using namespace std;
    string empty;
    string small = "bit";
    string larger = "Elephant are a girl's best fried";
    cout << "Size:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;
    
    cout << "Compacity:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;
    
    empty.reserve(50);
    cout << "Capacty after empty.reserve(50): " << empty.capacity() << endl;
    
    ofstream fout;
    string filename;
    cout << "Enter a file name: ";
    cin >> filename;
    fout.open(filename.c_str());
    fout << "123";
    fout.close();
    return 0;
}