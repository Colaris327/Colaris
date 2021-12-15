#ifndef ACCTABC_H_
#define ACCTABC_H_

// Abstact Base Class
class AcctABC
{
    private:
        enum {MAX = 35};
        char fullname[MAX];
        long acctnum;
        double balance;
    protected:
        const char *FullName() const {return fullname;}
        long AcctNum() const {return acctnum;}
        std::ios_base::fmtflags SetFormat() const;
    public:
        AcctABC(const char *s = "Nullbody", long an = -1, double bal = 0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt);
        double Balance() const {return balance;}
        virtual void ViewAccount() const = 0; // pure virtual function
        virtual ~AcctABC() {}
};

class Brass: public AcctABC
{
    public:
        Brass(const char *s = "Nullbody", long an = -1, double bal = 0.0): AcctABC(s, an, bal) {}
        virtual void Withdraw(double amt);
        virtual void ViewAccount() const;
        virtual ~Brass() {}
};

class BrassPlus: public AcctABC
{
    private:
        double Maxloan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const char *s = "Nullbody", long an = -1, double bal = 0.0, double ml = 0.0,
                double r = 0.10);
        BrassPlus(const Brass & ba, double ml, double r);
        virtual void Withdraw(double amt);
        virtual void ViewAccount() const;
        void ResetMax(double m) {Maxloan = m;}
        void ResetRate(double r) {rate = r;}
        void ResetOwes() {owesBank = 0;}
};
#endif