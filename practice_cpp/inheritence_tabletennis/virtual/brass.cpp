#include <iostream>
#include <cstring>
#include "brass.h"
using std::cout;
using std::endl;
using std::ios_base;

Brass::Brass(const char *s, long an, double bal)
{
    std::strncpy(fullname, s, MAX - 1);
    fullname[MAX - 1] = '\0';
    acctnum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed!\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Withdrawal amount must be positive!\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawl amount of $" << amt << " exceeds your balance\n";
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    cout << "Client: " << fullname << endl;
    cout << "Account number: " << acctnum << endl;
    cout << "Balance: " << balance << endl;
    cout.setf(initialState); // restore original format
}

BrassPlus::BrassPlus(const char *s, long an, double bal,double ml,
        double r): Brass(s, an, bal)
{
    Maxloan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r): Brass(ba) // use implicit copy constructor
{
    Maxloan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const
{
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    Brass::ViewAcct();
    cout << "Maximum loan: " << Maxloan << endl;
    cout << "Loan Rate: " << rate * 100 << "%" << endl;
    cout << "Owed to bank: " << owesBank << endl;
    cout.setf(initialState);
}

void BrassPlus::Withdraw(double amt)
{
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    if (amt <= Balance())
        Brass::Withdraw(amt);
    else if (amt <= Balance() + Maxloan - owesBank)
    {
        double advance = amt - Balance();
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout  << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    cout.setf(initialState);
}