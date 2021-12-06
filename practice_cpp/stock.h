#ifndef STOCK_H_
#define STOCK_H_
#include <string>

class Stock
{
    private:
        std::string company;
        int shares;
        double share_val;
        double total_val;
        void set_tot() {total_val = share_val * shares;}
    public:
        Stock();
        Stock(const char *co, int n = 0, double pr = 0.0);
        ~Stock(){};
        //void acquire(const char *co, int n, double pr);
        void buy(int num, double price);
        void sell(int num, double price);
        void update(double price);
        void show();
        const Stock & topval(const Stock & s) const;
};

Stock::Stock()
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0;
    total_val = 0;
}

Stock::Stock(const char *co, int n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    // std::strncpy(company, co, 29);
    // company[29] = '\0';
    company = co;
    if (n < 0)
    {
        std::cerr << "Number of shares can't be negative. " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}


// void Stock::acquire(const char *co, int n, double pr)
// {
//     std::strncpy(company, co, 29);
//     company[29] = '\0';
//     if (n < 0)
//     {
//         std::cerr << "Number of shares can't be negative. " << company << " shares set to 0.\n";
//         shares = 0;
//     }
//     else
//         shares = n;
//     share_val = pr;
//     set_tot();
// }

void Stock::buy(int num, double price)
{
    if (num < 0)
    {
        std::cerr << "Number of shares purchased can't be negative. " << "Transaction is aborted.\n";        
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    using std::cerr;
    if (num < 0)
    {
        cerr << "NUmber of shares sold can't be negative. " << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cerr << "You can't sell more than you have! Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::endl;
    cout << "Company: " << company << " Shares: " << shares << endl;
    cout << " Share Price: " << share_val << " Total worth: " << total_val << endl;
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

#endif