// http://alrightchiu.github.io/SecondRound/hash-tableopen-addressing.html
#include <iostream>
#include <string>
using namespace std;

struct dict
{
    int key;
    string value;
    dict(): key(0), value("") {}
    dict(int k, string v): key(k), value(v) {}
};

class HashOpenAdress
{
    private:
        int size, count;
        dict *table;
        int QuadraticProbing(int key, int i);
    public:
        HashOpenAdress(): size(0), count(0), table(nullptr) {}
        HashOpenAdress(int m): size(m), count(0) {table = new dict[size];}
        void Insert(int key, string value);
        void Delete(int key);
        string Search(int key);
        void Display();
};

int HashOpenAdress::QuadraticProbing(int key, int i)
{
    return ((int)((key % size) + 0.5 * i + 0.5 * i * i) % size); // (key % size) is the start point of probing
}

string HashOpenAdress::Search(int key)
{
    int i = 0;
    while (i != size)
    {
        int j = QuadraticProbing(key, i);
        if (table[j].key == key)
            return table[j].value;
        else
            i++;
    }
    return "Not Found...\n";
}

void HashOpenAdress::Insert(int key, string value)
{
    int i = 0;
    while (i != size)
    {
        int j = QuadraticProbing(key, i);
        if (table[j].value == "")
        {
            table[j].key = key;
            table[j].value = value;
            count++;
            return;
        }
        else
            i++;
    }
    cout << "Table Overflow...\n";
}

void HashOpenAdress::Delete(int key)
{
    int i = 0;
    while (i != size)
    {
        int j = QuadraticProbing(key, i);
        if (table[j].key == key)
        {
            table[j].key = 0;
            table[j].value = "";
            count--;
            return;
        }
        else
            i++;
    }
    cout << "Not Found...\n";
}

void HashOpenAdress::Display()
{
    for (int i = 0; i < size; i++)
    {
        cout << "slot#" << i << ": (" << table[i].key
            << ", " << table[i].value << ")\n";
    }
    cout << endl;
}

int main()
{
    HashOpenAdress hash (8);
    hash.Insert(33, "blue"); // 1
    hash.Insert(10, "yellow"); // 2
    hash.Insert(77, "red"); // 5
    hash.Insert(2, "white"); // collision with yellow -> 3
    hash.Display();
    hash.Insert(8, "black"); // 0
    hash.Insert(47, "gray"); // 7
    hash.Insert(90, "purple"); // collision -> 4
    hash.Insert(1, "deep purple"); // collision -> 6
    hash.Display();
    hash.Insert(15, "green"); // Overflow

    cout << "number#90 is " << hash.Search(90) << "\n\n";

    hash.Delete(90);
    cout << "After deleting (90, purple)\n";
    cout << "number#90 is " << hash.Search(90) << "\n\n";

    hash.Insert(12, "orange"); // 4
    hash.Display();
    
    return 0;
}