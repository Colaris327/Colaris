// page 520
#include <iostream>
#include <string>

template<class T1, class T2>
class Pairs
{
    private:
        T1 a;
        T2 b;
    public:
        T1 & first();
        T2 & second();
        T1 first() const {return a;}
        T2 second() const {return b;}
        Pairs(const T1 & aval, const T2 & bval): a(aval), b(bval) {}
        Pairs() {}
};

template<class T1, class T2>
T1 & Pairs<T1, T2>::first()
{
    return a;
}

template<class T1, class T2>
T2 & Pairs<T1, T2>::second()
{
    return b;
}

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    Pairs<string, int> rating[4] = {
        Pairs<string, int>("The Purple Duke", 5),
        Pairs<string, int>("Jake's Frisco AI Fresco", 4),
        Pairs<string, int>("Mont Souffle", 5),
        Pairs<string, int>("Gertie's Eats", 3)
    };

    int joints = sizeof(rating) / sizeof(Pairs<string, int>);
    cout << "Rating:\t Eatery\n";
    for (int i = 0; i < joints; i++)
    {
        cout << rating[i].second() << ":\t "
            << rating[i].first() << endl;
    }

    cout << "Oops~ Revised rating:\n";
    rating[3].first() = "Gertie's Fab Eat";
    rating[3].second() = 6;
    cout << rating[3].second() << ":\t "
            << rating[3].first() << endl;

    return 0;
}