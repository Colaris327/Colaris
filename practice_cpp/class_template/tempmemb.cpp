// page 523
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class beta
{
    private:
        template<typename V> // nested template class member
        class hold
        {
            private:
                V val;
            public:
                hold(V v = 0): val(v) {}
                void show() const {cout << val << endl;}
                V value() const {return val;}
        };
        hold<T> q; // template object
        hold<int> n; // template object
    public:
        beta(T t, int i): q(t), n(i) {}
        template<typename U> // template method
        U blab(U u, T t) {return (n.value() + q.value()) * u / t;}
        void Show() const {q.show(); n.show();}
};

int main()
{
    beta<double> guy(3.5, 3);
    guy.Show();
    cout << guy.blab(10, 2.3) << endl;
    cout << "Done\n";
    return 0;
}