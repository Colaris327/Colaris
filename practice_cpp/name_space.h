namespace pers
{
    const int LEN = 40;
    struct Person
    {
        char fname[LEN];
        char lname[LEN];
    };

    void getPerson(Person & rp)
    {
        using namespace std;
        cout << "Enter first name: ";
        cin >> rp.fname;
        cout << "Enter last name: ";
        cin >> rp.lname;
    }

    void showPerson(const Person & rp)
    {
        std::cout << rp.lname << ", " << rp.fname;
    }
}

namespace debts
{
    using namespace pers;
    struct Debt
    {
        Person name;
        double amount;
    };
    
    void getDebt(Debt & rd)
    {
        getPerson(rd.name);
        std::cout << "Enter debt: ";
        std::cin >> rd.amount;
    }

    void showDebt(const Debt & rd)
    {
        showPerson(rd.name);
        std::cout << ": $" << rd.amount << std::endl;
    }

    double sumDebts(const Debt ar[], int n)
    {
        double total = 0;
        for (int i = 0; i < n; ++i)
            total += ar[i].amount;
        return total;
    }
}

// pers::getPerson(Person & rp)
// {
//     cout << "Enter first name: ";
//     cin >> rp.fname;
//     cout << "Enter last name: ";
//     cin >> rp.lname;
// }

// pers::showPerson(Person & rp)
// {
//     std::cout << rp.lname << ", " << rp.fname;
// }

// debts::getDebt(Debt & rd)
// {
//     getPerson(rd.name);
//     std::cout << "Enter debt: ";
//     std::cin >> rd.amount;
// }

// debts::showDebt(const Debt & rd)
// {
//     showPerson(rd.name);
//     std::cout << ": $" << rd.amount << std::endl;
// }

// debts::sumDebts(const Debt ar[], int n)
// {
//     double total = 0;
//     for (int i = 0; i < n; ++i)
//         total += ar[i].amount;
//     return total;
// }