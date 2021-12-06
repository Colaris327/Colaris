#include <iostream>
using namespace std;

// argument is pointer to a type double function that takes a type int argument.
void Estimate(int lines, double (*pt)(int));

double Besty(int);
double Pam(int);

int main()
{
    int lines;
    cout << "How many lines of code do you need? ";
    cin >> lines;
    cout << "Here's Betsy's estimate: \n";
    Estimate(lines, Besty);
    cout << "Here's Pam's estimate: \n";
    Estimate(lines, Pam);
    return 0;
}


double Besty(int lns)
{
    return 0.05 * lns;
}

double Pam(int lns)
{
    return 0.03 * lns + 0.0004 *lns *lns;
}

void Estimate(int lines, double (*pt)(int))
{
    cout << lines << " lines will take ";
    cout << (*pt)(lines) << " hours." << endl;
}