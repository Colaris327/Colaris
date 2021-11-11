#include <iostream>

template <class T>
class Stack
{//A finite ordered list with zero or more elements
    public:
    Stack (int stackCapacity = 10);
    //Create an empty stack whose initial capacitp is staclCapacity
    bool IsEmpty() const;
    //If number of elements in the stack is 0, return true or false
    T& Top() const;
    void Push(const T& item);
    void Pop();
    private:
    T *stack;//array for stack
    int top;//array index of top element
    int capacity;//size of stack
};

template <class T>
Stack<T>::Stack (int stackCapacity) :
capacity (stackCapacity)
// capacity = stackCapacity
{
    stack = new T[capacity];
    top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const
{//inline��ĳ�sĶ�������N�{���a�J�I�s�I
    //const : ��Ƥ�����ק令���ܼƤ���
    return top == -1;
}

template <class T>
inline T& Stack<T>::Top() const
//get the top element
{
    if (IsEmpty()) throw "Stack is empty";
    //throw : �i��ҥ~(exception)�B�z�A�@��|���}�{��
    return stack[top];
}

template <class T>
void Stack<T>::Push (const T& x)
//push (add) x to the stack
{
    if (top == capacity - 1)
        throw "Stack Overflows";
    stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
//Delete top element from the stack
{
    if (IsEmpty())
        throw "Stack is empty. Cannot delete."
    stack[top--].~T();//destructor for T
}