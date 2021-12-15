// page 551
#include <iostream>
#include <string>
#include "queue_nested.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::string;

    QueueTP<string> cs (5);
    string temp;

    while (!cs.isFull())
    {
        cout << "Please enter your name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. Processing begins!\n";

    while (!cs.isEmpty())
    {
        cs.dequeue(temp);
        cout << "Now processing " << temp << std::endl;
    }
    
    return 0;
}