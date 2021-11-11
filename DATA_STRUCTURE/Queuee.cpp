
template <class T>
class Queue
{//A finite ordered list with zero or more elements
public:
    queue (int queueCapacity = 10);
    bool IsEmpty() const;
    T& Front() const;
    T& Rear() const;
    void Push(const T& item);
    void Pop();
private:
    T *queue; //array for queue
    int front;
    int rear;
    int capacity;
}

template <class T>
Queue<T>::Queue (int queueCapacity) :
capacity (queueCapacity)
// capacity = queueCapacity
{
    queue = new T[capacity];
    front = rear = capacity - 1 // 0 is OK
}

template <class T>
inline bool Queue<T>::IsEmpty()
{
    return (front == rear);
}

template <class T>
inline T& Queue::front()
{
    if (IsEmpty())
        throw "Queue is empty"
    return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::rear()
{
    if (IsEmpty())
        throw "Queue is empty."
    return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& x)
{
    if ((rear + 1) % capacity == front)
        throw "Queue is full"
    rear = (rear + 1) % capacity;
    queue[rear] = x;
}

template <class T>
void Queue<T>::Pop()
{
    if (IsEmpty())
        throw "Queue is empty."
    front = (front + 1) % capacity;
    queue[front].~T(); // destructor for T
}