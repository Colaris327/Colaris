#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

class TSet
{
    private:
        set<char> asc;
    public:
        TSet() {}
        TSet(const TSet &);
        TSet(const set<char> &);
        ~TSet() {}
        const set<char> & Get() const {return this->asc;}
        const TSet operator=(const TSet &);
        const TSet operator=(const set<char>);
        friend TSet operator+(const TSet &, const TSet &);
        friend TSet operator-(const TSet &, const TSet &);
        friend TSet operator*(const TSet &, const TSet &);
        friend bool operator>=(const TSet &, const TSet &);
        friend ostream & operator<<(ostream &, const TSet &);
        friend istream & operator>>(istream &, TSet &);
        const bool IN(const char);
};


int main()
{
    int n;
    TSet A, B;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin.get();
        char in;
        cin >> A >> B >> in;
        cout << "A: ";
        cout << A << endl;
        cout << "B: ";
        cout << B << endl;

        TSet C, D;
        C = A + B;
        cout << "A+B: " << C << endl;
        D = A * B;
        cout << "A*B: " << D << endl;
        cout << "A-B: " << (A - B) << endl;
        cout << "B-A: " << (B - A) << endl;

        cout << "A " << ((A >= B) ? "contain" : "does not contain") << " B\n";
        cout << "B " << ((B >= A) ? "contain" : "does not contain") << " A\n";

        cout << "'" << in << "'" << " is " << ((A.IN(in)) ? "in" : "not in") << " A\n";
        cout << "'" << in << "'" << " is " << ((B.IN(in)) ? "in" : "not in") << " B\n";
    }
    return 0;
}

TSet::TSet(const TSet & s)
{
    asc = s.Get();
}

TSet::TSet(const set<char> & s)
{
    asc = s;
}

const TSet TSet::operator=(const TSet & A)
{
    this->asc = A.Get();
    return TSet (A.Get());
}

const TSet TSet::operator=(const set<char> s)
{
    this->asc = s;
    return TSet(s);
}

TSet operator+(const TSet & A, const TSet & B)
{
    set<char> result;
    set<char> aa = A.Get();
    set<char> bb = B.Get();
    insert_iterator< set<char> > it (result, result.begin());
    set_union(aa.begin(), aa.end(), bb.begin(), bb.end(), it);
    TSet C (result);
    return C;
}

TSet operator-(const TSet & A, const TSet & B)
{
    set<char> result;
    set<char> aa = A.Get();
    set<char> bb = B.Get();
    insert_iterator< set<char> > it (result, result.begin());
    set_difference(aa.begin(), aa.end(), bb.begin(), bb.end(), it);
    TSet C (result);
    return C;
}

TSet operator*(const TSet & A, const TSet & B)
{
    set<char> result;
    set<char> aa = A.Get();
    set<char> bb = B.Get();
    insert_iterator< set<char> > it (result, result.begin());
    set_intersection(aa.begin(), aa.end(), bb.begin(), bb.end(), it);
    TSet C (result);
    return C;
}

bool operator>=(const TSet & A, const TSet & B)
{
    TSet difference = A - B;
    set<char> result = difference.Get();
    return (result.size() == 0);
}

ostream & operator<<(ostream & os, const TSet & A)
{
    set<char> print = A.Get();
    os << "{";
    set<char>::iterator it; // also can use auto
    for (it = print.begin(); it != print.end(); it++)
        os << *it;
    os << "}";
    return os;
}

istream & operator>>(istream & is, TSet & A)
{
    set<char> result;
    string input;
    getline(is, input);
    for (auto it = input.begin(); it != input.end(); it++)
        result.insert(*it);
    A = result;
    return is;
}

const bool TSet::IN(const char ch)
{
    set<char> aa = this->Get();
    auto it = find(aa.begin(), aa.end(), ch);
    if (it == aa.end())
        return false;
    else
        return true;
}