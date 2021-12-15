#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
    private:
        long arrive;
        int process;
    public:
        Customer() {arrive = 0; process = 0;}
        void set(long when);
        long when() {return arrive;}
        int ptime() {return process;}
};
typedef Customer Item;

class Queue
{
    private:
        struct Node {Item item; Node *next;};
        enum {Q_SIZE = 10};
        Node *front;
        Node *rear;
        int items; // current number of items in Queue
        const int qsize; // maximum number of items in Queue
        //preemptive definition to prevent public copying
        Queue (const Queue & q): qsize(0) {}
        Queue & operator=(const Queue & q) {return *this;}
    public:
        Queue(int qs = Q_SIZE); // create queue with a qs limit
        ~Queue();
        bool isEmpty() const;
        bool isFull() const;
        int queuecount() const;
        bool enqueue(const Item & item);
        bool dequeue(Item & item);
};
#endif