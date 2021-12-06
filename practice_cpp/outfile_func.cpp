#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void File_it(ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;

int main()
{
    ofstream fout;
    const char * fn = "ep_data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "ERROR!!!" << endl;
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the Focal length of your telescope objective in mm: ";
    cin >> objective;
    double eps[LIMIT];
    for (int i = 0; i < LIMIT; ++i)
    {
        cout << "Eye piece #" << i+1 << " : ";
        cin >> eps[i];
    }
    File_it(cout, objective, eps, LIMIT);
    File_it(fout, objective, eps, LIMIT);
    return 0;
}

void File_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); // save initial formatting state
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f eyepiece";
    os.width(20);
    os << "magnification\n";
    for (int i = 0; i < LIMIT; ++i)
    {
        os.width(10);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }
    os.setf(initial); // restore initial formatting state
}