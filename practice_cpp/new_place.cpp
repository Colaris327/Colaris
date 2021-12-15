#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class Justtesting
{
    private:
        string words;
        int number;
    public:
        Justtesting(const string & s = "Just testing", int n = 0)
        {words = s; number = n; cout << words << " constructed.\n";}
        ~Justtesting() {cout << words << " destroyed.\n";}
        void Show() const {cout << words << ", " << number << endl;}
};

int main()
{
    char *buffer = new char[BUF];
    Justtesting *p1, *p2;
    p1 = new (buffer) Justtesting; // place object in buffer
    p2 = new Justtesting("Heap1", 20);
    cout << "Memory block address:\n" << "buffer: " << (void*) buffer << "    heap: " << p2 << endl;
    cout << "Memory content:\n";
    cout << p1 << ": ";
    p1->Show();
    cout << p2 << ": ";
    p2->Show();

    Justtesting *p3, *p4;
    p3 = new (buffer + sizeof(Justtesting)) Justtesting("Better idea", 6);
    p4 = new Justtesting("Heap2", 10);
    cout << "Memory content:\n";
    cout << p3 << ": ";
    p3->Show();
    cout << p4 << ": ";
    p4->Show();

    delete p2; // free heap1
    delete p4; // free heap2
    p1->~Justtesting(); // destroy object pointed to by p1
    p3->~Justtesting(); // destroy object pointed to by p3
    delete [] buffer; // free buffer
    cout << "DONE";
    return 0;
}