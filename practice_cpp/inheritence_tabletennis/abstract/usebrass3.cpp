// page 459
// compile with acctABC.cpp
// polymorphic example
#include <iostream>
#include "acctabc.h"
using std::cout;
using std::cin;
using std::endl;
const int CLIENTS = 4;
const int LEN = 40;

int main()
{
    AcctABC *p_clients[CLIENTS];

    for (int i = 0; i < CLIENTS; i++)
    {
        char temp[LEN];
        long tempnum;
        double tempbal;
        char kind;

        cout << "Enter Client's name: ";
        cin.getline(temp, LEN);
        cout << "Enter Client's account: ";
        cin >> tempnum;
        cout << "Enter Client's balance: ";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: ";
            cin >> tmax;
            cout << "Enter the interest rate: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAccount();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i]; // free memory
    }
    
    cout << "Done\n";
    return 0;
}