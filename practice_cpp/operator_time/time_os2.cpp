#include <iostream>
#include "time_os.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca: ";
    cout << aida << "; " << tosca << endl;
    cout << "Aida + Tosca: ";
    temp = aida + tosca; // operator+()
    cout << temp << endl;
    cout << "Aida * 1.17: ";
    temp = aida * 1.17; // operator*()
    cout << temp << endl;
    cout << "10 * Tosca: " << 10 * tosca << endl;

    system("pause");
    return 0;
}