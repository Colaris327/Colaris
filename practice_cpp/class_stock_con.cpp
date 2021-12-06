#include <iostream>
#include <cstring>

class Stock
{
    private:
        char company[30];
        int shares;
        double share_val;
        double total_val;
        void set_tot() {total_val = share_val * shares;}
    public:
        Stock();
        Stock(const char *co, int n = 0, double pr = 0.0);
        ~Stock();
        void acquire(const char *co, int n, double pr);
        void buy(int num, double price);
        void sell(int num, double price);
        void update(double price);
        void show();
};

Stock::Stock()
{
    std::cout << "Default constructor called\n";
    std::strncpy(company, "no name", 29);
    shares = 0;
    share_val = 0;
    total_val = 0;
}

Stock::Stock(const char *co, int n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    std::strncpy(company, co, 29);
    company[29] = '\0';
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

Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}

void Stock::acquire(const char *co, int n, double pr)
{
    std::strncpy(company, co, 29);
    company[29] = '\0';
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


int main()
{
    using std::cout;
    using std::ios_base;
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);

    Stock stock_original = Stock(); // 1st way to constuct Stock
    stock_original.show();
    Stock stock_ori; // 2nd way to constuct Stock
    stock_ori.show();

    cout << "Using constructor: \n";
    Stock stock1("NanoSmart", 12, 20.0); // 3rd way to constuct Stock
    stock1.show();
    Stock stock2 = Stock("Boffo Objects", 2, 2.0); // 4th way to constuct Stock
    stock1.show();
    
    cout << "Assigning stock1 to stock2: \n";
    stock2 = stock1;
    cout << "Listing stock1 and stock2: \n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Nifty Foods", 10, 50.0);
    cout << "Revised stock1: \n";
    stock1.show();
    cout << "Done.\n";
    return 0;
}