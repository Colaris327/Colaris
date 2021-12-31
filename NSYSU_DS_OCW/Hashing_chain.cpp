// http://alrightchiu.github.io/SecondRound/hash-tablechaining.html
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

struct dict
{
    string key;
    string value;
    dict(): key(""), value("") {}
    dict(string k, string v): key(k), value(v) {}
};

class HashChain
{
    private:
        int size;
        int count; // numbers of table
        vector< list<dict> > table;
        int Prehashing(string key_str); // turns string to int
        int Hashfunction(string key_str); // calculate position
    public:
        HashChain() {}
        HashChain(int m): size(m), count(0) {table.resize(size);}
        string Search(string key);
        void Insert(dict data);
        void Delete(string key);
        void Display();
};

int HashChain::Prehashing(string key_str)
{
    // if key_str == "Ray", key_int = ASCII(R) * 9^2 + ASCII(a) * 9^1 + ASCII(y) * 9^0
    int key_int = 0, exp = 1;
    for (int i = key_str.size() - 1; i >= 0; i--)
    {
        key_int += key_str[i] * exp;
        exp *= 9;
    }
    return key_int;
}

int HashChain::Hashfunction(string key_str)
{
    return (Prehashing(key_str) % this->size);
}

string HashChain::Search(string key)
{
    int index = Hashfunction(key);
    for (auto it = table[index].begin(); it != table[index].end(); it++)
    {
        if (it->key == key)
            return it->value;
    }
    return "Not Found\n";
}

void HashChain::Insert(dict data)
{
    int index = Hashfunction(data.key);
    table[index].push_front(data);
}

void HashChain::Delete(string key)
{
    int index = Hashfunction(key);
    for (auto it = table[index].begin(); it != table[index].end();)
    {
        if (it->key == key)
            it = table[index].erase(it); // erase() will return it + 1
        else
            it++;
    }
}

void HashChain::Display()
{
    for (int i = 0; i < size; i++)
    {
        cout << "slot#" << i << ": ";
        for (auto it = table[i].begin(); it != table[i].end(); it++)
            cout << "(" << it->key << ", " << it->value << ") ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    HashChain hash (5);
    hash.Insert(dict("T-Mac","Magic"));
    hash.Insert(dict("Bryant","Lakers"));
    hash.Insert(dict("Webber","Kings"));
    hash.Insert(dict("Arenas", "Wizards"));
    hash.Insert(dict("Davis","Clippers"));
    hash.Insert(dict("Kidd","Nets"));
    hash.Display();

    cout << "T-Mac is in " << hash.Search("T-Mac") << ". " << endl;
    cout << "Arenas is in " << hash.Search("Arenas") << ". " << endl;

    hash.Delete("Kidd");
    hash.Delete("T-Mac");
    cout << "\nAfter deleing Kidd and T-Mac:\n";
    hash.Display();
    return 0;
}