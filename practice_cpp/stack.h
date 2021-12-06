#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
    private:
        enum {MAX = 10};
        Item items[MAX];
        int top;
    public:
        Stack();
        bool isEmpty();
        bool isFull();
        bool push(const Item & item);
        bool pop(Item & item);
};

Stack::Stack()
{
    top = 0;
}

bool Stack::isEmpty()
{
    return top == 0;
}

bool Stack::isFull()
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

#endif