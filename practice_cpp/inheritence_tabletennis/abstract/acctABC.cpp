#include <iostream>
#include <cstring>
#include "acctabc.h"
using std::cout;
using std::endl;
using std::ios_base;

AcctABC::AcctABC(const char *s, long an, double bal)
{
    std::strncpy(fullname, s, MAX - 1);
    fullname[MAX - 1] = '\0';
    acctnum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed!\n";
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

// protected method
ios_base::fmtflags AcctABC::SetFormat() const
{
    ios_base::fmtflags initialstate = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    return initialstate;
}

// Brass
void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Withdrawal amount must be positive!\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "Withdrawl amount of $" << amt << " exceeds your balance\n";
}

void Brass::ViewAccount() const
{
    ios_base::fmtflags initialState = SetFormat();
    cout << "Client: " << FullName() << endl;
    cout << "Account number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout.setf(initialState);
}

// BrassPlus
BrassPlus::BrassPlus(const char *s, long an, double bal,double ml,
        double r): AcctABC(s, an, bal)
{
    Maxloan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r): AcctABC(ba) // inplicit copy constructor
{
    Maxloan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::Withdraw(double amt)
{
    ios_base::fmtflags initialState = SetFormat();

    if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else if (amt <= Balance() + Maxloan - owesBank)
    {
        double advance = amt - Balance();
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout  << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    cout.setf(initialState);
}

void BrassPlus::ViewAccount() const
{
    ios_base::fmtflags initialState = SetFormat();

    cout << "Client: " << FullName() << endl;
    cout << "Account number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << Maxloan << endl;
    cout << "Loan Rate: " << rate * 100 << "%" << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.setf(initialState);
}