// polynomial
#include <iostream>
using namespace std;

class Term
{
    public:
        int coef = 0;
        int power = 0;
        Term *link = nullptr;
        Term() {}
        Term(int co, int po): coef(co), power(po), link(nullptr) {}
};

class Poly
{
    protected:
        Term *first;
    public:
        Poly(): first(nullptr) {}
        void AddItem(int coef, int power);
        void DelItem();
        void Free(); // reset Poly chain
        friend Poly & operator+(Poly &, Poly &);
        friend Poly & operator*(Poly &, Poly &);
        friend ostream & operator<<(ostream &, const Poly &);
};

void Poly::AddItem(int coef, int power)
{
    Term *temp = new Term(coef, power);
    Term *find = first;
    Term *prefind;
    if (first == nullptr)
        first = temp;
    else
    {
        while (temp->power < find->power)
        {
            prefind = find;
            find = find->link;
            if (find == nullptr)
                break;
        }
        if (find == nullptr) // doesn't find, so add it to tail
            prefind->link = temp;
        else if (find->power == temp->power)
            find->coef += temp->coef;
        else if (find == first) // the added item's power is biggest
        {
            temp->link = first;
            first = temp;
        }
        else // insert item
        {
            prefind->link = temp;
            temp->link = find;
        }
    }
}

void Poly::DelItem()
{
    Term *current = first, *previous = nullptr;
    while (current)
    {
        if (current->coef == 0 && previous == nullptr) // delete first item
        {
            previous = current;
            current = current->link;
            delete previous;
            previous = nullptr;
            first = current; // remember to reset first to new head
        }
        else if (current->coef == 0)
        {
            previous->link = current->link;
            delete current;
            current = previous->link;
        }
        else // nothing happen
        {
            previous = current;
            current = current->link;
        }
    }
}

void Poly::Free()
{
    Term *current = first;
    Term *previous = current;
    while (current)
    {
        current = current->link;
        delete previous;
        previous = current;
    }
    first = nullptr; // important!! remember to reset first to NULL
}

Poly & operator+(Poly & A, Poly & B)
{
    Poly *result = new Poly;
    for (auto it = A.first; it != nullptr; it = it->link)
        result->AddItem(it->coef, it->power);
    for (auto it = B.first; it != nullptr; it = it->link)
        result->AddItem(it->coef, it->power);
    result->DelItem();
    return *result;
}

Poly & operator*(Poly & A, Poly & B)
{
    Poly *result = new Poly;
    for (auto Ait = A.first; Ait != nullptr; Ait = Ait->link)
        for (auto Bit = B.first; Bit != nullptr; Bit = Bit->link)
            result->AddItem(Ait->coef * Bit->coef, Ait->power + Bit->power);
    result->DelItem();
    return *result;
}

ostream & operator<<(ostream & os, const Poly & P)
{
    for (auto it = P.first; it != nullptr; it = it->link)
        cout << it->coef << " " << it->power << endl;
    if (P.first == nullptr) // this poly has no coef and power
        cout << "0 0" << endl;
    return os;
}

int main()
{
    Poly A, B, C, D;
    int P, Q, coef, power;
    while (true)
    {
        A.Free();
        B.Free();
        C.Free();
        D.Free();

        cin >> P;
        for (int i = 0; i < P; i++)
        {
            cin >> coef >> power;
            A.AddItem(coef, power);
        }
        cin >> Q;
        for (int i = 0; i < Q; i++)
        {
            cin >> coef >> power;
            B.AddItem(coef, power);
        }

        if (P == 0 && Q == 0)
            break;

        C = A + B;
        D = A * B;
        cout << "ADD:\n" << C << endl;
        cout << "MULTIPLY\n" << D << endl;
    }
}