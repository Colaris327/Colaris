#include <iostream>

template <class T> class Chain; // forward declaration

template <class T>
class ChainNode
{
    friend class Chain<T>;
    private:
        T data;
        ChainNode<T> *link;
};

template <class T>
class Chain
{
    private:
        ChainNode<T> *first;
        ChainNode<T> *last;
    public:
        Chain() {first = 0;}
        void Insertback(const T & e);
        void Concatenate(Chain<T> & e);
        void Reverse();
};

template <class T>
void Chain<T>::Insertback(const T & e)
{
    if (first == 0)
    {
        first = new ChainNode<T> (e);
        last = first;
    }
    else
    {
        last->link = new ChainNode<T> (e);
        last = last->link;
    }
}

template <class T>
void Chain<T>::Concatenate(Chain<T> & e)
{
    if (e.first == 0) // empty e
        return;
    if (first)
    {
        last->link = e.first;
        last = e.last
    }
    else {first = e.first; last = e.last;} // empty
    e.first = e.last = 0;
}

template <class T>
void Chain<T>::Reverse()
{
    ChainNode<T> *current = first, *previous = 0;
    while (current)
    {
        ChainNode<T> *r = previous;
        previous = current;
        current = current->link;
        previous->link = r;
    }
    first = previous;
}