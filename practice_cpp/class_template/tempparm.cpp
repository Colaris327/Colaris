// page 526
#include <iostream>
#include "stack_template.h"

template< template<typename T> class Thing, typename U, typename V>
class Crab
{
    private:
        Thing<U> s1;
        Thing<V> s2;
    public:
        Crab() {}
        // assume the thing class has push() and pop()
        bool push(U a, V x) {return s1.push(a) && s2.push(x);}
        bool pop(U & a, V & x) {return s1.pop(a) && s2.pop(x);}
};

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    Crab<Stack, int, double> nebula;
// Stack must match template <typename T> class thing
    int ni;
    double nb;
    cout << "Enter int double pair:\n";
    while (cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if (!nebula.push(ni, nb))
            break;
    }
    
    while (nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;
    cout << "Done\n";
    return 0;
}