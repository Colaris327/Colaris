#ifndef QUEUETP_H_
#define QUEUETP_H_

template<class Item>
class QueueTP
{
    private:
        enum {Q_SIZE = 10};
        // Node is a nested class definition
        class Node
        {
            public:
                Item item;
                Node *next;
                Node(const Item & i): item(i), next(0) {}
        };
        Node *front;
        Node *rear;
        int items;
        const int qsize;
        QueueTP(const QueueTP & q): qsize(0) {}
        QueueTP & operator=(const QueueTP & q) {return *this;}
    public:
        QueueTP(int q = Q_SIZE);
        ~QueueTP();
        bool isEmpty() const {return items == 0;}
        bool isFull() const {return items == qsize;}
        int queuecount() const {return items;}
        bool enqueue(const Item & item);
        bool dequeue(Item & item);
};

template<class Item>
QueueTP<Item>::QueueTP(int qs): qsize(qs)
{
    front = rear = NULL;
    items = 0;
}

template<class Item>
QueueTP<Item>::~QueueTP()
{
    Node *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
    if (isFull())
        return false;
    Node *add = new Node(item);
    if (add == NULL)
        return false;
    items++;
    if (front == NULL)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
    if (front == 0)
        return false;
    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = 0;
    return true;
}
#endif